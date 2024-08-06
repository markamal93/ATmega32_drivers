/*
 * main.c
 *
 *  Created on: Jul 28, 2024
 *      Author: markk
 */

#include "GPIO/GPIO.h"
#include "LCD16x2/LCD16x2.h"
#include <util/delay.h>
#include "STD_TYPES.h"
#include "KEYPAD4x4/KEYPAD4x4.h"

#define F_CPU 1000000UL  // 1 MHz clock speed

int main(){

	//u8 str[] = "mark_kamal";
	LCD_Init();
	//LCD_SendString("mark kamal\0");
	KEYPAD_Init();

	while(1){
		u8 pressedkey = KEYPAD_GetKey();
		LCD_SendChar(pressedkey);
	}



}
