################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_edma.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpi2c.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_sai.c \
../drivers/fsl_sai_edma.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_edma.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpi2c.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_sai.o \
./drivers/fsl_sai_edma.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_edma.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpi2c.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_sai.d \
./drivers/fsl_sai_edma.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


