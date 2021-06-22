#include <stdio.h>
#include <stdarg.h>
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_sai_edma.h"
#include "fsl_codec_common.h"
#include "fsl_wm8960.h"
#include "fsl_codec_adapter.h"
#include "fsl_dmamux.h"
#include "cr_section_macros.h"
#include "pin_mux.h"
#include "peripherals.h"
#include "MIMXRT1011.h"
#include "PCF85063AT.h"
#include "I2C.h"
#include "OLED.h"
#include "compiletime.h"

#define M5ATOM_I2C_ADDR  0x19
#define EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW 4
/* Use CMSIS to make DSP work fast NOTE: define it before edge impulse header */
#define EIDSP_USE_CMSIS_DSP             1
#define EIDSP_LOAD_CMSIS_DSP_SOURCES    1

#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "edge-impulse-sdk/dsp/numpy.hpp"
#include "model-parameters/model_metadata.h"

/********************************/
/* SAI instance and clock */
#define DEMO_CODEC_WM8960
#define DEMO_SAI              SAI1
#define DEMO_SAI_CHANNEL      (0)
#define DEMO_SAI_IRQ          SAI1_IRQn
#define DEMO_SAITxIRQHandler  SAI1_IRQHandler
#define DEMO_SAI_TX_SYNC_MODE kSAI_ModeAsync
#define DEMO_SAI_RX_SYNC_MODE kSAI_ModeSync
#define DEMO_SAI_MCLK_OUTPUT  true
#define DEMO_SAI_MASTER_SLAVE kSAI_Master

#define DEMO_AUDIO_DATA_CHANNEL (2U)
#define DEMO_AUDIO_BIT_WIDTH    kSAI_WordWidth16bits
#define DEMO_AUDIO_SAMPLE_RATE  (kSAI_SampleRate16KHz)
#define DEMO_AUDIO_MASTER_CLOCK DEMO_SAI_CLK_FREQ

/* IRQ */
#define DEMO_SAI_TX_IRQ SAI1_IRQn
#define DEMO_SAI_RX_IRQ SAI1_IRQn

/* DMA */
#define DEMO_DMA             DMA0
#define DEMO_DMAMUX          DMAMUX
#define DEMO_TX_EDMA_CHANNEL (0U)
#define DEMO_RX_EDMA_CHANNEL (1U)
#define DEMO_SAI_TX_SOURCE   kDmaRequestMuxSai1Tx
#define DEMO_SAI_RX_SOURCE   kDmaRequestMuxSai1Rx

/* Select Audio/Video PLL (786.48 MHz) as sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_SELECT (2U)
/* Clock pre divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER (0U)
/* Clock divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_DIVIDER (63U)
/* Get frequency of sai1 clock */
#define DEMO_SAI_CLK_FREQ                                                        \
    (CLOCK_GetFreq(kCLOCK_AudioPllClk) / (DEMO_SAI1_CLOCK_SOURCE_DIVIDER + 1U) / \
     (DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER + 1U))

/* I2C instance and clock */
#define DEMO_I2C LPI2C1

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define DEMO_I2C_CLK_FREQ ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (DEMO_LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

#define BOARD_MASTER_CLOCK_CONFIG()
//#define BUFFER_SIZE   (1024U)
#define BUFFER_SIZE   (32000U)

#define RING_BUFLEN 5


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static int mic_audio_signal_get_data(size_t offset, size_t length, float *out_ptr);
extern void ei_printf(const char *format, ...);
/*******************************************************************************
 * Variables
 ******************************************************************************/
wm8960_config_t wm8960Config = {
    .route  = kWM8960_RoutePlaybackandRecord,
    .bus    = kWM8960_BusI2S,
    .format = {.mclk_HZ = 6144000U, .sampleRate = kWM8960_AudioSampleRate16KHz, .bitWidth = kWM8960_AudioBitWidth16bit},
    .master_slave = false,
    .rightInputSource = kWM8960_InputDifferentialMicInput2,
    .playSource       = kWM8960_PlaySourceDAC,
    .slaveAddress     = WM8960_I2C_ADDR,
    .i2cConfig = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE, .codecI2CSourceClock = BOARD_CODEC_I2C_CLOCK_FREQ},
};


codec_config_t boardCodecConfig = {.codecDevType = kCODEC_WM8960, .codecDevConfig = &wm8960Config};
/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM)
 *                              = 24 * (32 + 77/100)
 *                              = 786.48 MHz
 */
const clock_audio_pll_config_t audioPllConfig = {
    .loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1,   /* Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator   = 77,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 100, /* 30 bit denominator of fractional loop divider */
};

AT_NONCACHEABLE_SECTION_INIT(sai_edma_handle_t txHandle);
AT_NONCACHEABLE_SECTION_INIT(sai_edma_handle_t rxHandle);
edma_handle_t dmaTxHandle = {0}, dmaRxHandle = {0};
extern codec_config_t boardCodecConfig;
codec_handle_t codecHandle;


/** Audio buffers, pointers and selectors */
typedef struct {
    signed short buffers[2][EI_CLASSIFIER_SLICE_SIZE];
    unsigned char buf_select;
    unsigned char buf_ready;
    unsigned int buf_count;
    unsigned int n_samples;
} inference_t;


// Place the buffer in the OCRAM memory region
__DATA(RAM3)  static inference_t inference;
__DATA(RAM3)  static signed short sampleBuffer[EI_CLASSIFIER_SLICE_SIZE>>1];


static bool record_ready = false;
static bool debug_nn = false; // Set this to true to see e.g. features generated from the raw signal
static int print_results = -(EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW);

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_EnableSaiMclkOutput(bool enable)
{
    if (enable)
    {
        IOMUXC_GPR->GPR1 |= IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK;
    }
    else
    {
        IOMUXC_GPR->GPR1 &= (~IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK);
    }
}

static void rx_callback(I2S_Type *base, sai_edma_handle_t *handle, status_t status, void *userData)
{
    if (kStatus_SAI_RxError == status)
    {
        /* Handle the error. */
    }
    else
    {
        if (record_ready == true) {
            for(int i = 0; i <EI_CLASSIFIER_SLICE_SIZE>>1 ; i++) {
                inference.buffers[inference.buf_select][inference.buf_count++] = sampleBuffer[i];

                if (inference.buf_count >= inference.n_samples) {
                    inference.buf_select ^= 1;
                    inference.buf_count = 0;
                    inference.buf_ready = 1;
                }
            }

            sai_transfer_t xfer;
        	xfer.data     = (uint8_t *)&sampleBuffer[0];
            xfer.dataSize = EI_CLASSIFIER_SLICE_SIZE;

            if (kStatus_Success == SAI_TransferReceiveEDMA(DEMO_SAI, &rxHandle, &xfer))
            {
            	//ei_printf("Sample requested\n");
            }
        }
    }
}

int main(void)
{
    sai_transfer_t xfer;
    edma_config_t dmaConfig = {0};
    sai_transceiver_t saiConfig;

    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_BootClockRUN();
    CLOCK_InitAudioPll(&audioPllConfig);
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    if (SysTick_Config(SystemCoreClock / 1000U))
    {
    	PRINTF("SysTick_Config failed. Halted.\n");
        while (1) {}
    }

    /*Clock setting for LPI2C*/
    CLOCK_SetMux(kCLOCK_Lpi2cMux, DEMO_LPI2C_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, DEMO_LPI2C_CLOCK_SOURCE_DIVIDER);

    /*Clock setting for SAI1*/
    CLOCK_SetMux(kCLOCK_Sai1Mux, DEMO_SAI1_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Sai1PreDiv, DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER);
    CLOCK_SetDiv(kCLOCK_Sai1Div, DEMO_SAI1_CLOCK_SOURCE_DIVIDER);

    /*Enable MCLK clock*/
    BOARD_EnableSaiMclkOutput(true);

    /* Init DMAMUX */
    DMAMUX_Init(DEMO_DMAMUX);
    DMAMUX_SetSource(DEMO_DMAMUX, DEMO_TX_EDMA_CHANNEL, (uint8_t)DEMO_SAI_TX_SOURCE);
    DMAMUX_EnableChannel(DEMO_DMAMUX, DEMO_TX_EDMA_CHANNEL);
    DMAMUX_SetSource(DEMO_DMAMUX, DEMO_RX_EDMA_CHANNEL, (uint8_t)DEMO_SAI_RX_SOURCE);
    DMAMUX_EnableChannel(DEMO_DMAMUX, DEMO_RX_EDMA_CHANNEL);

    /* Init DMA and create handle for DMA */
    EDMA_GetDefaultConfig(&dmaConfig);
    EDMA_Init(DEMO_DMA, &dmaConfig);
    EDMA_CreateHandle(&dmaTxHandle, DEMO_DMA, DEMO_TX_EDMA_CHANNEL);
    EDMA_CreateHandle(&dmaRxHandle, DEMO_DMA, DEMO_RX_EDMA_CHANNEL);
#if defined(FSL_FEATURE_EDMA_HAS_CHANNEL_MUX) && FSL_FEATURE_EDMA_HAS_CHANNEL_MUX
    EDMA_SetChannelMux(DEMO_DMA, DEMO_TX_EDMA_CHANNEL, DEMO_SAI_TX_EDMA_CHANNEL);
    EDMA_SetChannelMux(DEMO_DMA, DEMO_RX_EDMA_CHANNEL, DEMO_SAI_RX_EDMA_CHANNEL);
#endif

    /* SAI init */
    SAI_Init(DEMO_SAI);

    //SAI_TransferTxCreateHandleEDMA(DEMO_SAI, &txHandle, tx_callback, NULL, &dmaTxHandle);
    SAI_TransferRxCreateHandleEDMA(DEMO_SAI, &rxHandle, rx_callback, NULL, &dmaRxHandle);

    /* I2S mode configurations */
    SAI_GetClassicI2SConfig(&saiConfig, DEMO_AUDIO_BIT_WIDTH, kSAI_Stereo, 1U << DEMO_SAI_CHANNEL);
    saiConfig.syncMode    = DEMO_SAI_TX_SYNC_MODE;
    saiConfig.masterSlave = DEMO_SAI_MASTER_SLAVE;
    SAI_TransferTxSetConfigEDMA(DEMO_SAI, &txHandle, &saiConfig);
    saiConfig.syncMode = DEMO_SAI_RX_SYNC_MODE;
    SAI_TransferRxSetConfigEDMA(DEMO_SAI, &rxHandle, &saiConfig);

    /* set bit clock divider */
    SAI_TxSetBitClockRate(DEMO_SAI, DEMO_AUDIO_MASTER_CLOCK, DEMO_AUDIO_SAMPLE_RATE, DEMO_AUDIO_BIT_WIDTH,
                          DEMO_AUDIO_DATA_CHANNEL);
    SAI_RxSetBitClockRate(DEMO_SAI, DEMO_AUDIO_MASTER_CLOCK, DEMO_AUDIO_SAMPLE_RATE, DEMO_AUDIO_BIT_WIDTH,
                          DEMO_AUDIO_DATA_CHANNEL);

    /* master clock configurations */
    BOARD_MASTER_CLOCK_CONFIG();

    /* Use default setting to init codec */
    if (CODEC_Init(&codecHandle, &boardCodecConfig) != kStatus_Success)
    {
        assert(false);
    }

    i2c_init();
	i2c_scan();

	OLED_Init();
	OLED_Clear_Screen();


	datetime_t dt;
	PCF85063AT_init();
	PRINTF("Resetting RTC, status: %d\n", PCF85063AT_reset());

	char timestamp_str[11] = {0};
	timestamp_t cur_ts;

	if (i2c_read(M5ATOM_I2C_ADDR, 10, (uint8_t*) timestamp_str)) {
		cur_ts = strtol(timestamp_str, NULL, 10);
		PRINTF("cur_ts = %ld\n", cur_ts);
	} else {
		PRINTF("Read failed\n");
		return -1;
	}

	breakTime(cur_ts, &dt);

	if (! PCF85063AT_time_set(&dt)) {
		PRINTF("time set failed.\n");
		return -1;
	}

   // PCF85063AT_countdown_set(true, CNTDOWN_CLOCK_1HZ, 30, false, false);


    inference.buf_select = 0;
    inference.buf_count = 0;
    inference.n_samples = EI_CLASSIFIER_SLICE_SIZE;
    inference.buf_ready = 0;


	xfer.data     = (uint8_t *)&sampleBuffer[0];
    xfer.dataSize = EI_CLASSIFIER_SLICE_SIZE;

    ei_printf("EI started!\n");

    if (kStatus_Success == SAI_TransferReceiveEDMA(DEMO_SAI, &rxHandle, &xfer))
    {
    	ei_printf("First sample requested\n");
    } else {
    	ei_printf("First sample failed\n");
    }

    record_ready = true;


    uint8_t preds_ix[RING_BUFLEN] = {1};

    unsigned long int faucet = 0;
    unsigned long int noise  = 0;

    while (1)
    {
        if (inference.buf_ready == 1) {
            ei_printf(
                "Error sample buffer overrun. Decrease the number of slices per model window "
                "(EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW)\n");
            break;
        }

        while (inference.buf_ready == 0) {
            ei_sleep(10);
        }

        inference.buf_ready = 0;

        signal_t signal;
		signal.total_length = EI_CLASSIFIER_SLICE_SIZE;
		signal.get_data = &mic_audio_signal_get_data;
		ei_impulse_result_t result = {0};

		EI_IMPULSE_ERROR r = run_classifier_continuous(&signal, &result, debug_nn);
		if (r != EI_IMPULSE_OK) {
			ei_printf("ERR: Failed to run classifier (%d)\n", r);
			break;
		}


		if (++print_results >= (EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW)) {
			// print the predictions
//			ei_printf("Predictions ");
//			ei_printf("(DSP: %d ms., Classification: %d ms.)",
//				result.timing.dsp, result.timing.classification);
//			ei_printf(": \n");

			uint8_t ix_max;

			for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
				ei_printf("    %s: %d\n", result.classification[ix].label,
						  uint8_t(result.classification[ix].value * 100));

				if (result.classification[ix].value > 0.60f) {
                    ix_max = ix;
				}
			}

		    memmove(preds_ix, preds_ix+1, sizeof(preds_ix[0]) * (RING_BUFLEN -1) );
		    preds_ix[RING_BUFLEN -1] = ix_max;

		    uint8_t sum = 0;

		    for (uint8_t k = 0; k < RING_BUFLEN; k++) {
		        sum += preds_ix[k];
		    }

			char text[7];

	        if (sum < 3) {
			    strcpy(text, "FAUCET");
			    faucet++;
			    noise=0;
			} else {
			    strcpy(text, "NOISE ");
			    noise++;
			    faucet = 0;
			}
			OLED_PrintText(3, 24, (uint8_t*) text);

			print_results = 0;
		}

		PRINTF("noise=%ld, faucet=%ld\n", noise, faucet);

		if (faucet == 25) {
			uint8_t  buf[3] = {0x09, 0x01, 0x09};

	    	if (i2c_write(M5ATOM_I2C_ADDR, sizeof(buf), buf)) {
	            PRINTF("Buzzer on request sent!");
	    	}
		    PCF85063AT_countdown_set(true, CNTDOWN_CLOCK_1HZ, 10, false, false);
			PRINTF("Countime timer started for email alert\n");

		}

		if (noise == 20) {
			PRINTF("Countime timer disabled\n");
		    PCF85063AT_countdown_set(true, CNTDOWN_CLOCK_1HZ, 0, false, false);

			uint8_t  buf[3] = {0x09, 0x00, 0x09};

	    	if (i2c_write(M5ATOM_I2C_ADDR, sizeof(buf), buf)) {
	            PRINTF("Buzzer off request sent!");
	    	}
		}

	   datetime_t cur_dt;

	   if (PCF85063AT_time_get(&cur_dt)) {
	       PRINTF("%02d-%02d-%d %02d:%02d:%02d\n", (1970 + cur_dt.year), cur_dt.month,
				  cur_dt.day, cur_dt.hour, cur_dt.minute, cur_dt.second);
	    } else {
		   PRINTF("Could not get time.\n");
	    }


	    /* Read control registers */
	    PCF85063AT_Regs regs;
	    PCF85063AT_ctrl_get(&regs);
	    PCF85063AT_Regs new_regs = regs;
	    PCF85063AT_REG_SET(new_regs, PCF85063AT_REG_AF);
	    PCF85063AT_REG_SET(new_regs, PCF85063AT_REG_TF);


	    if (PCF85063AT_REG_GET(regs, PCF85063AT_REG_TF))
	    {
	        PRINTF("Countdown timer triggered!\n");
	        PCF85063AT_REG_CLEAR(new_regs, PCF85063AT_REG_TF);
	        // Disable timer
	        uint8_t  buf[3] = {0x05, 0x01, 0x05};

	    	if (i2c_write(M5ATOM_I2C_ADDR, sizeof(buf), buf)) {
	            PRINTF("Alert email send request dispatched!");
	    	}

	    	// disable timer

	        PCF85063AT_countdown_set(true, CNTDOWN_CLOCK_1HZ, 0, false, false);

	    }

	    PCF85063AT_ctrl_set(new_regs, false);
	}

    PRINTF("Exited\n");

    return 0;
}

static int mic_audio_signal_get_data(size_t offset, size_t length, float *out_ptr)
{
	//ei_printf("offset: %d, length: %d\n", offset, length);
	numpy::int16_to_float(&inference.buffers[inference.buf_select ^ 1][offset], out_ptr, length);

    return 0;
}

void ei_printf(const char *format, ...) {
    static char print_buf[1024] = { 0 };

    va_list args;
    va_start(args, format);
    int r = vsnprintf(print_buf, sizeof(print_buf), format, args);
    va_end(args);

    if (r > 0) {
        PRINTF(print_buf);
    }
}
