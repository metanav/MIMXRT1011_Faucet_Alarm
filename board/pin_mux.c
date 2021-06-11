/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMXRT1011xxxxx
package_id: MIMXRT1011DAE5A
mcu_data: ksdk2_0
processor_version: 9.0.1
board: MIMXRT1010-EVK
pin_labels:
- {pin_num: '3', pin_signal: GPIO_09, label: UART1_RXD, identifier: UART1_RXD}
- {pin_num: '2', pin_signal: GPIO_10, label: UART1_TXD, identifier: UART1_TXD}
- {pin_num: '65', pin_signal: GPIO_SD_10, label: FlexSPI_CLK, identifier: FlexSPI_CLK}
- {pin_num: '66', pin_signal: GPIO_SD_09, label: FlexSPI_D0_A, identifier: FlexSPI_D0_A}
- {pin_num: '68', pin_signal: GPIO_SD_07, label: FlexSPI_D1_A, identifier: FlexSPI_D1_A}
- {pin_num: '67', pin_signal: GPIO_SD_08, label: FlexSPI_D2_A, identifier: FlexSPI_D2_A}
- {pin_num: '64', pin_signal: GPIO_SD_11, label: FlexSPI_D3_A, identifier: FlexSPI_D3_A}
- {pin_num: '69', pin_signal: GPIO_SD_06, label: FlexSPI_SS0, identifier: FlexSPI_SS0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '59', peripheral: LPI2C2, signal: SDA, pin_signal: GPIO_AD_01}
  - {pin_num: '58', peripheral: LPI2C2, signal: SCL, pin_signal: GPIO_AD_02}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_01_LPI2C2_SDA, 1U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_02_LPI2C2_SCL, 1U);
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_02_LPI2C2_SCL, 0xD8B0U);
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_01_LPI2C2_SDA, 0xD8B0U);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_01_LPI2C1_SDA,              /* GPIO_01 is configured as LPI2C1_SDA */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_01 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_02_LPI2C1_SCL,              /* GPIO_02 is configured as LPI2C1_SCL */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_02 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_04_SAI1_TX_DATA00,          /* GPIO_04 is configured as SAI1_TX_DATA00 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_04 */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_03_SAI1_RX_DATA00,          /* GPIO_03 is configured as SAI1_RX_DATA00 */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_03 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_06_SAI1_TX_BCLK,            /* GPIO_06 is configured as SAI1_TX_BCLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_06 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_07_SAI1_TX_SYNC,            /* GPIO_07 is configured as SAI1_TX_SYNC */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_07 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_08_SAI1_MCLK,               /* GPIO_08 is configured as SAI1_MCLK */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_08 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_09_LPUART1_RXD,             /* GPIO_09 is configured as LPUART1_RXD */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_10_LPUART1_TXD,             /* GPIO_10 is configured as LPUART1_TXD */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_01_LPI2C1_SDA,              /* GPIO_01 PAD functional properties : */
      0xD8A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_02_LPI2C1_SCL,              /* GPIO_02 PAD functional properties : */
      0xD8A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */

  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_03_SAI1_RX_DATA00,          /* GPIO_03 PAD functional properties : */
      0x18A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */


  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_04_SAI1_TX_DATA00,          /* GPIO_04 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_06_SAI1_TX_BCLK,            /* GPIO_06 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_07_SAI1_TX_SYNC,            /* GPIO_07 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_08_SAI1_MCLK,               /* GPIO_08 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_09_LPUART1_RXD,             /* GPIO_09 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_10_LPUART1_TXD,             /* GPIO_10 PAD functional properties : */
      0x10A0U);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: fast(150MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '3', peripheral: LPUART1, signal: RXD, pin_signal: GPIO_09}
  - {pin_num: '2', peripheral: LPUART1, signal: TXD, pin_signal: GPIO_10}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_09_LPUART1_RXD, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_10_LPUART1_TXD, 0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitQSPIPins:
- options: {coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '65', peripheral: FLEXSPI, signal: FLEXSPI_A_SCLK, pin_signal: GPIO_SD_10}
  - {pin_num: '66', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA0, pin_signal: GPIO_SD_09}
  - {pin_num: '68', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA1, pin_signal: GPIO_SD_07}
  - {pin_num: '67', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA2, pin_signal: GPIO_SD_08}
  - {pin_num: '64', peripheral: FLEXSPI, signal: FLEXSPI_A_DATA3, pin_signal: GPIO_SD_11}
  - {pin_num: '69', peripheral: FLEXSPI, signal: FLEXSPI_A_SS0_B, pin_signal: GPIO_SD_06}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitQSPIPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitQSPIPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_06_FLEXSPI_A_SS0_B, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_07_FLEXSPI_A_DATA1, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_08_FLEXSPI_A_DATA2, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_09_FLEXSPI_A_DATA0, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_10_FLEXSPI_A_SCLK, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_11_FLEXSPI_A_DATA3, 0U); 
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
