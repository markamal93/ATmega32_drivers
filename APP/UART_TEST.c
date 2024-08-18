/*
 * UART_TEST.c
 *
 *  Created on: Aug 14, 2024
 *      Author: markk
 */

#include "GPIO/GPIO.h"
#include "UART/UART.h"
#include "TIMER/TIMER.h"

int main (void){


	UART_vidInit();
	TIMER0_Init();
	while(1){
		UART_vidSendByte('m');
		TIMER0_SetBusyWait_OVFMode(100);
		UART_vidSendByte('a');
		TIMER0_SetBusyWait_OVFMode(100);
		UART_vidSendByte('r');
		TIMER0_SetBusyWait_OVFMode(100);
		UART_vidSendByte('k');



	}
	return 0;
}

