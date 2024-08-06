################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATmega32_drivers/APP/main.c 

OBJS += \
./ATmega32_drivers/APP/main.o 

C_DEPS += \
./ATmega32_drivers/APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
ATmega32_drivers/APP/%.o: ../ATmega32_drivers/APP/%.c ATmega32_drivers/APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\1Embedded Systems\NEW\atmega_new\ATmega32_DRIVERS\UTILS" -I"G:\1Embedded Systems\NEW\atmega_new\ATmega32_DRIVERS\MCAL" -I"G:\1Embedded Systems\NEW\atmega_new\ATmega32_DRIVERS\HAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


