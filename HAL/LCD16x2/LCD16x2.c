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
	_delay_ms(20);
#ifdef LCD_4BIT_MODE
	LCD_SendCommand(0x02);
	LCD_SendCommand(0x28);
	LCD_SendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	LCD_SendCommand(LCD_RETURN_HOME); /*Move to home*/
	LCD_SendCommand(LCD_SET_ENTRY_MODE|LCD_MOVE_CURSOR_RIGHT); /*Set entry mode*/
	LCD_SendCommand(LCD_DISPLAY_ON); /*Display On/Off control*/
	_delay_ms(2);
#else
	LCD_SendCommand(LCD_FUNCTION_SET|LCD_8BIT|LCD_4LINES); /*Function Set*/
	LCD_SendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	LCD_SendCommand(LCD_RETURN_HOME); /*Move to home*/
	LCD_SendCommand(LCD_SET_ENTRY_MODE|LCD_MOVE_CURSOR_RIGHT); /*Set entry mode*/
	LCD_SendCommand(LCD_FUNCTION_SET|LCD_8BIT|LCD_4LINES);
	LCD_SendCommand(LCD_DISPLAY_ON); /*Display On/Off control*/
#endif
}
void LCD_SendCommand(u8){

}
void LCD_SendChar(u8){

}
void LCD_SendString(s8*){

}
void LCD_GotoXy(u8,u8){

}

