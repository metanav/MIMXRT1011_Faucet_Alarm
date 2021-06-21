################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/I2C.cpp \
../source/MIMXRT1011_Faucet_Alarm_Project.cpp \
../source/OLED.cpp \
../source/PCF85063AT.cpp \
../source/cpp_config.cpp \
../source/datetime.cpp 

C_SRCS += \
../source/semihost_hardfault.c 

OBJS += \
./source/I2C.o \
./source/MIMXRT1011_Faucet_Alarm_Project.o \
./source/OLED.o \
./source/PCF85063AT.o \
./source/cpp_config.o \
./source/datetime.o \
./source/semihost_hardfault.o 

CPP_DEPS += \
./source/I2C.d \
./source/MIMXRT1011_Faucet_Alarm_Project.d \
./source/OLED.d \
./source/PCF85063AT.d \
./source/cpp_config.d \
./source/datetime.d 

C_DEPS += \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source/edge-impulse-sdk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


