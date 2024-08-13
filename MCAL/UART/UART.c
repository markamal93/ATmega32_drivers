/*
 * UART.c
 *
 *  Created on: Aug 13, 2024
 *      Author: markk
 */

#include "UART.h"



void UART_Init(void){
	//Setting both Receive Enable and Transmit Enable
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);
	//seta data bit size
#if DATA_SIZE == DATA_SIZE_5-bit
	CLEAR_BIT(UCSRC , UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_6-bit
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_7-bit
	CLEAR_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_8-bit
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_9-bit
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	SET_BIT(UCSRB , UCSRB_UCSZ2);
#endif




}

void UART_TransmitDataAsynchronous(u8 Data);

void UART_ReceiveDataAsynchronous(u8 * ReceivedData);

void UART_SendString(u8 * String);


void UART_SetTXCCallBack(void(*pvNotificationFunction)(void));

void UART_SetUDRECallBack(void(*pvNotificationFunction)(void));

void UART_SetRXCCallBack(void(*pvNotificationFunction)(void));



