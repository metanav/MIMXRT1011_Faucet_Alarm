################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/activations.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/add.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/arg_min_max.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ceil.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/circular_buffer.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/comparisons.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/concatenation.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/conv.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/depthwise_conv.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/dequantize.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/elementwise.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ethosu.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/floor.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/fully_connected.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/l2norm.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logical.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logistic.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/maximum_minimum.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mli_slicers.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mul.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/neg.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pack.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pad.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pooling.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/prelu.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/quantize.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reduce.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reshape.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/round.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buf_mgr.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buffers.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/softmax.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/split.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/strided_slice.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/sub.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/svdf.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tanh.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tflite_detection_postprocess.cc \
../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/unpack.cc 

CC_DEPS += \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/activations.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/add.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/arg_min_max.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ceil.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/circular_buffer.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/comparisons.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/concatenation.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/conv.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/depthwise_conv.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/dequantize.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/elementwise.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ethosu.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/floor.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/fully_connected.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/l2norm.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logical.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logistic.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/maximum_minimum.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mli_slicers.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mul.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/neg.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pack.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pad.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pooling.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/prelu.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/quantize.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reduce.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reshape.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/resize_nearest_neighbor.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/round.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buf_mgr.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buffers.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/softmax.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/split.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/strided_slice.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/sub.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/svdf.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tanh.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tflite_detection_postprocess.d \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/unpack.d 

OBJS += \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/activations.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/add.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/arg_min_max.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ceil.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/circular_buffer.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/comparisons.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/concatenation.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/conv.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/depthwise_conv.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/dequantize.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/elementwise.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/ethosu.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/floor.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/fully_connected.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/l2norm.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logical.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/logistic.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/maximum_minimum.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mli_slicers.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/mul.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/neg.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pack.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pad.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/pooling.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/prelu.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/quantize.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reduce.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/reshape.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/resize_nearest_neighbor.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/round.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buf_mgr.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/scratch_buffers.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/softmax.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/split.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/strided_slice.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/sub.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/svdf.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tanh.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/tflite_detection_postprocess.o \
./source/edge-impulse-sdk/tensorflow/lite/micro/kernels/unpack.o 


# Each subdirectory must supply rules for building sources it contributes
source/edge-impulse-sdk/tensorflow/lite/micro/kernels/%.o: ../source/edge-impulse-sdk/tensorflow/lite/micro/kernels/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MIMXRT1011DAE5A -DCPU_MIMXRT1011DAE5A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/board" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/drivers" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/xip" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/serial_manager" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/uart" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/utilities" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/codec" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/i2c" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/component/lists" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/CMSIS" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/device" -I"/Users/naveen/Documents/MCUXpressoIDE_11.3.1/workspace/MIMXRT1011_Faucet_Alarm_Project/source/edge-impulse-sdk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


