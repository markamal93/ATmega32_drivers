/*
 * ADC_POT.c
 *
 *  Created on: Aug 8, 2024
 *      Author: markk
 */

#include "ADC/ADC.h"
#include "GPIO/GPIO.h"
#include <util/delay.h>
#include "LCD16x2/LCD16x2.h"

int main(){
	ADC_Init();
	LCD_Init();

while(1){
	u8 value  = ADC_StartConversionSynchronous(CHANNEL0);
	LCD_SendCommand(LCD_CLEAR_SCREEN);
	LCD_GotoXy(0,0);
	LCD_SendString("ADC value :");
	LCD_SendNumber(value);
	_delay_ms(200);

}
return 0;
}
