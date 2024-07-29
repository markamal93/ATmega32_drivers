/*
 * GPIO.c
 *
 *  Created on: Jul 28, 2024
 *      Author: markk
 */


#include "GPIO.h"


void GPIO_SetPortDirection(u8 Port , u8 Direction){
	switch(Port){
	case GPIO_PORTA :
		DDRA = Direction;
		break;
	case GPIO_PORTB :
		DDRB = Direction;
		break;
	case GPIO_PORTC :
		DDRC = Direction;
		break;
	case GPIO_PORTD :
		DDRD = Direction;
		break;
	}
}
void GPIO_SetPortValue(u8 Port , u8 Value){
	switch(Port){
	case GPIO_PORTA :
		PORTA = Value;
		break;
	case GPIO_PORTB :
		PORTB = Value;
		break;
	case GPIO_PORTC :
		PORTC = Value;
		break;
	case GPIO_PORTD :
		PORTD = Value;
		break;
	}
}
u8 GPIO_GetPortValue(u8 Port){
	u8 Value = 0x00;
	switch(Port){
	case GPIO_PORTA:
		Value = PINA;
		break;
	case GPIO_PORTB:
		Value = PINB;
		break;
	case GPIO_PORTC :
		Value = PINC;
		break;
	case GPIO_PORTD :
		Value = PIND;
		break;
	}
	return Value;
}

void GPIO_SetPinDirection(u8 Port ,u8 PinNumber, u8 Direction){
	switch(Port){
	case GPIO_PORTA:
		if (Direction == GPIO_OUTPUT){
			SET_BIT(DDRA , PinNumber);
		}else {
			CLEAR_BIT(DDRA,PinNumber);
		}break;

	}

}


void GPIO_SetPinValue(u8 Port ,u8 PinNumber, u8 Value){

}
u8 GPIO_GetPinValue(u8 Port , u8 PinNumber){

}

void GPIO_TogglePin(u8 port , u8 PinNumber){

}

void GPIO_SetPullUpOnPin(u8 port,u8 PinNumber){

}



