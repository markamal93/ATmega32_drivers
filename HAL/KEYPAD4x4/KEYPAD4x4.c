/*
 * KEYPAD4x4.c
 *
 *  Created on: Jul 29, 2024
 *      Author: markk
 */

#include "KEYPAD4x4_config.h"
#include "GPIO/GPIO.h"
#include <util/delay.h>



void KEYPAD_Init(void){

	GPIO_SetPinDirection(COL0_PORT,COL0_PIN,GPIO_OUTPUT);
	GPIO_SetPinDirection(COL1_PORT,COL1_PIN,GPIO_OUTPUT);
	GPIO_SetPinDirection(COL2_PORT,COL2_PIN,GPIO_OUTPUT);
	GPIO_SetPinDirection(COL3_PORT,COL3_PIN,GPIO_OUTPUT);

	GPIO_SetPinDirection(ROW0_PORT,ROW0_PIN,GPIO_INPUT);
	GPIO_SetPinValue(COL0_PORT,ROW0_PIN,STD_HIGH);
	GPIO_SetPinDirection(ROW1_PORT,ROW1_PIN,GPIO_INPUT);
	GPIO_SetPinValue(COL1_PORT,ROW1_PIN,STD_HIGH);
	GPIO_SetPinDirection(ROW2_PORT,ROW2_PIN,GPIO_INPUT);
	GPIO_SetPinValue(COL2_PORT,ROW2_PIN,STD_HIGH);
	GPIO_SetPinDirection(ROW3_PORT,ROW3_PIN,GPIO_INPUT);
	GPIO_SetPinValue(COL3_PORT,ROW3_PIN,STD_HIGH);

}
u8 KEYPAD_GetKey(void){
	static u8 keys[4][4] = {{'/',3,2,1},{'*',6,5,4},{'+',9,8,7},{'=','-',0,'#'}};
	static u8 values[4] = {0x0E,0x0D,0x0B,0x07};
	static u8 value,i = 0;


	for (i = 0; i < 4; i++) {
		u8 ColRead = 0;
		value = values[i];
		GPIO_SetPinValue(COL0_PORT,COL0_PIN,GET_BIT(value,0));
		GPIO_SetPinValue(COL1_PORT,COL1_PIN,GET_BIT(value,1));
		GPIO_SetPinValue(COL2_PORT,COL2_PIN,GET_BIT(value,2));
		GPIO_SetPinValue(COL3_PORT,COL3_PIN,GET_BIT(value,3));

		ColRead |= (GPIO_GetPinValue(ROW0_PORT,ROW0_PIN) << 0);
		ColRead |= (GPIO_GetPinValue(ROW1_PORT,ROW1_PIN) << 1);
		ColRead |= (GPIO_GetPinValue(ROW2_PORT,ROW2_PIN) << 2);
		ColRead |= (GPIO_GetPinValue(ROW3_PORT,ROW3_PIN) << 3);
		/*This macro, if defined, will not print a character until
		 *the button is depressed. It is used to prevent printing
		 *the character more than once.
		 **/
		#ifdef KEYPAD_HOLD_BUTTON
			while(GPIO_GetPinValue(ROW0_PORT,ROW0_PIN) == 0);
			while(GPIO_GetPinValue(ROW1_PORT,ROW1_PIN) == 0);
			while(GPIO_GetPinValue(ROW2_PORT,ROW2_PIN) == 0);
			while(GPIO_GetPinValue(ROW3_PORT,ROW3_PIN) == 0);
		#endif
		switch(ColRead) {
			case 0x07:
				return keys[i][0];
			case 0x0B:
				return keys[i][1];
			case 0x0D:
				return keys[i][2];
			case 0x0E:
				return keys[i][3];
		}
	}
	return 0xFF;
}

