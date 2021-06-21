################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/tflite-model/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/micro/testing/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/micro/kernels/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/micro/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/kernels/internal/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/kernels/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/core/api/subdir.mk
-include source/edge-impulse-sdk/tensorflow/lite/c/subdir.mk
-include source/edge-impulse-sdk/porting/zephyr/subdir.mk
-include source/edge-impulse-sdk/porting/stm32-cubeai/subdir.mk
-include source/edge-impulse-sdk/porting/sony/subdir.mk
-include source/edge-impulse-sdk/porting/silabs/subdir.mk
-include source/edge-impulse-sdk/porting/posix/subdir.mk
-include source/edge-impulse-sdk/porting/mingw32/subdir.mk
-include source/edge-impulse-sdk/porting/mbed/subdir.mk
-include source/edge-impulse-sdk/porting/lib/subdir.mk
-include source/edge-impulse-sdk/porting/imxrt1010/subdir.mk
-include source/edge-impulse-sdk/porting/himax/subdir.mk
-include source/edge-impulse-sdk/porting/ecm3532/subdir.mk
-include source/edge-impulse-sdk/porting/arduino/subdir.mk
-include source/edge-impulse-sdk/dsp/kissfft/subdir.mk
-include source/edge-impulse-sdk/dsp/dct/subdir.mk
-include source/edge-impulse-sdk/dsp/subdir.mk
-include source/edge-impulse-sdk/classifier/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/ReshapeFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/BasicMathFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/BayesFunctions/subdir.mk
-include source/edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include component/i2c/subdir.mk
-include codec/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MIMXRT1011_Faucet_Alarm_Project.axf

# Tool invocations
MIMXRT1011_Faucet_Alarm_Project.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="MIMXRT1011_Faucet_Alarm_Project.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -T MIMXRT1011_Faucet_Alarm_Project_Debug.ld -u _printf_float -o "MIMXRT1011_Faucet_Alarm_Project.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) MIMXRT1011_Faucet_Alarm_Project.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "MIMXRT1011_Faucet_Alarm_Project.axf"; # arm-none-eabi-objcopy -v -O binary "MIMXRT1011_Faucet_Alarm_Project.axf" "MIMXRT1011_Faucet_Alarm_Project.bin" ; # checksum -p MIMXRT1011xxxxx -d "MIMXRT1011_Faucet_Alarm_Project.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
