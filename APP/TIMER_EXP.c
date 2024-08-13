/*
 * TIMER_EXP.c
 *
 *  Created on: Aug 13, 2024
 *      Author: markk
 */

#include "GPIO/GPIO.h"
#include "TIMER/TIMER.h"

int main (void){
	TIMER0_Init();
	GPIO_SetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT);


	while(1){
		GPIO_SetPinValue(GPIO_PORTA , GPIO_PIN0 , STD_HIGH);
		TIMER0_SetBusyWait_OVFMode(50);
		GPIO_SetPinValue(GPIO_PORTA , GPIO_PIN0 , STD_LOW);
		TIMER0_SetBusyWait_OVFMode(50);
	}
	return 0;
}

