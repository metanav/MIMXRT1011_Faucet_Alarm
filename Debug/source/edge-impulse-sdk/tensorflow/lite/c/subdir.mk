################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/edge-impulse-sdk/tensorflow/lite/c/common.c 

OBJS += \
./source/edge-impulse-sdk/tensorflow/lite/c/common.o 

C_DEPS += \
./source/edge-impulse-sdk/tensorflow/lite/c/common.d 


# Each subdirectory must supply rules for building sources it contributes
source/edge-impulse-sdk/tensorflow/lite/c/%.o: ../source/edge-impulse-sdk/tensorflow/lite/c/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


