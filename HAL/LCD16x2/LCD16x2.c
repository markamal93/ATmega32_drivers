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
void LCD_SendCommand(u8 command){
#ifdef LCD_4BIT_MODE
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(command,4));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(command,5));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(command,6));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(command,7));

	/*RS=0*/
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RS,STD_LOW);

		/*Sending enable signal*/
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(1);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_us(200);

	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(command,0));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(command,1));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(command,2));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(command,3));

	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(1);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
#else
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RS,STD_LOW);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(command,0));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(command,1));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(command,2));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(command,3));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(command,4));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(command,5));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(command,6));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(command,7));

	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(2);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_us(2);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);

#endif
}
void LCD_SendChar(u8 character){
#ifdef LCD_4BIT_MODE
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(character,4));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(character,5));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(character,6));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(character,7));

	/*RS=1*/
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RS,STD_HIGH);

		/*Sending enable signal*/
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(1);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_us(200);

	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(character,0));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(character,1));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(character,2));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(character,3));

	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(1);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
#else
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RS,STD_HIGH);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(character,0));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(character,1));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(character,2));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(character,3));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(character,4));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(character,5));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(character,6));
	GPIO_SetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(character,7));

	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_us(2);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_us(2);
	GPIO_SetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);

#endif


}
void LCD_SendString(u8* str){
    int i;
    for (i = 0; str[i] != 0; i++) {
        LCD_SendChar(str[i]);
}
}
void LCD_GotoXy(u8 x_cor,u8 y_cor){
#define LCD_SET_CURSOR_LOCATION 0x80
	u8 address = x_cor;
	switch(y_cor) {
		case 0:
			address = x_cor;
			break;
		case 1:
			address = x_cor+0xC0;
			break;
		case 2:
			address = x_cor+0x94;
			break;
		case 3:
			address = x_cor+0xD4;
			break;
	}
	LCD_SendCommand(address | 0x80);
}
void LCD_SendNumber(u16 number) {
    char buffer[17];     // Buffer to hold the converted number string
    itoa(number, buffer, 10);  // Convert the integer to a string (base 10)
    LCD_SendString(buffer);    // Send the string to the LCD
}
