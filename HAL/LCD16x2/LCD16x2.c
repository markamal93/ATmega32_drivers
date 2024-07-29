/*
 * LCD16x2.c
 *
 *  Created on: Jul 29, 2024
 *      Author: markk
 */

#include "LCD16x2.h"

void LCD_Init(void){
#ifdef LCD_4BIT_MODE

	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D4 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D5 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D6 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D7 , GPIO_OUTPUT);
#else
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D0 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D1 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D2 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D3 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D4 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D5 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D6 , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_DATA_PORT , LCD_D7 , GPIO_OUTPUT);

#endif
	GPIO_SetPinDirection(LCD_CTRL_PORT , LCD_E , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_CTRL_PORT , LCD_RW , GPIO_OUTPUT);
	GPIO_SetPinDirection(LCD_CTRL_PORT , LCD_RS , GPIO_OUTPUT);

}
void LCD_SendCommand(u8){

}
void LCD_SendChar(u8){

}
void LCD_SendString(s8*){

}
void LCD_GotoXy(u8,u8){

}

