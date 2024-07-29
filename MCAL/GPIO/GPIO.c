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
	case GPIO_PORTB:
		if (Direction == GPIO_OUTPUT){
			SET_BIT(DDRB , PinNumber);
		}else {
			CLEAR_BIT(DDRB,PinNumber);
		}break;
	case GPIO_PORTC:
		if (Direction == GPIO_OUTPUT){
			SET_BIT(DDRC , PinNumber);
		}else {
			CLEAR_BIT(DDRC,PinNumber);
		}break;
	case GPIO_PORTD:
		if (Direction == GPIO_OUTPUT){
			SET_BIT(DDRD , PinNumber);
		}else {
			CLEAR_BIT(DDRD,PinNumber);
		}break;
	}
}

void GPIO_SetPinValue(u8 Port ,u8 PinNumber, u8 Value){
	switch(Port){
	case GPIO_PORTA:
		if (Value == STD_HIGH){
			SET_BIT(PORTA , PinNumber);
		}else {
			CLEAR_BIT(PORTA,PinNumber);
		}break;
	case GPIO_PORTB:
		if (Value == STD_HIGH){
			SET_BIT(PORTB , PinNumber);
		}else {
			CLEAR_BIT(PORTB,PinNumber);
		}break;
	case GPIO_PORTC:
		if (Value == STD_HIGH){
			SET_BIT(PORTC , PinNumber);
		}else {
			CLEAR_BIT(PORTC,PinNumber);
		}break;
	case GPIO_PORTD:
		if (Value == STD_HIGH){
			SET_BIT(PORTD , PinNumber);
		}else {
			CLEAR_BIT(PORTD,PinNumber);
		}break;
	}
}

u8 GPIO_GetPinValue(u8 Port , u8 PinNumber){

	u8 Value = 0;
	switch(Port){
	case GPIO_PORTA:
		Value = GET_BIT(PINA ,PinNumber);
		break;
	case GPIO_PORTB:
		Value = GET_BIT(PINB ,PinNumber);
		break;
	case GPIO_PORTC :
		Value = GET_BIT(PINC ,PinNumber);
		break;
	case GPIO_PORTD :
		Value = GET_BIT(PIND ,PinNumber);
		break;
	}
	return Value;
}



void GPIO_TogglePin(u8 port , u8 PinNumber){
	switch(port){
	case GPIO_PORTA:
		TOGGLE_BIT(PORTA , PinNumber);
		break;
	case GPIO_PORTB:
		TOGGLE_BIT(PORTB , PinNumber);
		break;
	case GPIO_PORTC :
		TOGGLE_BIT(PORTC , PinNumber);
		break;
	case GPIO_PORTD :
		TOGGLE_BIT(PORTD , PinNumber);
		break;
	}
}

void GPIO_SetPullUpOnPin(u8 port,u8 PinNumber){
	GPIO_SetPinDirection(port , PinNumber , GPIO_INPUT);
	GPIO_SetPinValue(port , PinNumber , STD_HIGH);

}



