################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/leap_years.cpp \
../src/main.cpp \
../src/roman_numerals.cpp 

OBJS += \
./src/leap_years.o \
./src/main.o \
./src/roman_numerals.o 

CPP_DEPS += \
./src/leap_years.d \
./src/main.d \
./src/roman_numerals.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/mike/Documents/workspace/igloo_examples/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


