/*
 * GPIO.h
 *
 *  Created on: Jul 28, 2024
 *      Author: markk
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"
#include "MACROS.h"

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5
#define GPIO_PORTG 6

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

#define GPIO_OUTPUT 1
#define GPIO_INPUT 0


void GPIO_SetPortDirection(u8 Port , u8 Direction);
void GPIO_SetPortValue(u8 Port , u8 Value);
u8 	 GPIO_GetPortValue(u8 Port);

void GPIO_SetPinDirection(u8 Port ,u8 PinNumber, u8 Direction);
void GPIO_SetPinValue(u8 Port ,u8 PinNumber, u8 Value);
u8 	 GPIO_GetPinValue(u8 Port , u8 PinNumber);

void GPIO_TogglePin(u8 port , u8 PinNumber);

void GPIO_SetPullUpOnPin(u8 port,u8 PinNumber);




#endif /* MCAL_GPIO_GPIO_H_ */
