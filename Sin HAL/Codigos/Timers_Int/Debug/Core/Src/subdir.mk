################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GPIO.c \
../Core/Src/Sysconfig.c \
../Core/Src/Timer.c \
../Core/Src/main.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/GPIO.o \
./Core/Src/Sysconfig.o \
./Core/Src/Timer.o \
./Core/Src/main.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/GPIO.d \
./Core/Src/Sysconfig.d \
./Core/Src/Timer.d \
./Core/Src/main.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -c -I"C:/Users/Cristobal/Desktop/STM32/Codigos/Timers_Int/CMSIS/Include" -I"C:/Users/Cristobal/Desktop/STM32/Codigos/Timers_Int/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/GPIO.d ./Core/Src/GPIO.o ./Core/Src/GPIO.su ./Core/Src/Sysconfig.d ./Core/Src/Sysconfig.o ./Core/Src/Sysconfig.su ./Core/Src/Timer.d ./Core/Src/Timer.o ./Core/Src/Timer.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

