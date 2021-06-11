################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../source/edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_string.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_time.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/micro_utils.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/test_helpers.cc 

CC_DEPS += \
./source/edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_string.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_time.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_utils.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/test_helpers.d 

OBJS += \
./source/edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_string.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_time.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/micro_utils.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/test_helpers.o 


# Each subdirectory must supply rules for building sources it contributes
source/edge-impulse-sdk/tensorflow/lite/micro/%.o: ../source/edge-impulse-sdk/tensorflow/lite/micro/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source/edge-impulse-sdk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


