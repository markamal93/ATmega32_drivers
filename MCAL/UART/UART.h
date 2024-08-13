/*
 * UART.h
 *
 *  Created on: Aug 13, 2024
 *      Author: markk
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "UART_config.h"
#include "ATMEGA32_REG.h"
#include "MACROS.h"
#include "STD_TYPES.h"


#define     BR_2400_BPS     207
#define     BR_4800_BPS     103
#define     BR_9600_BPS     51

#define     FREE_REG        0




void UART_Init(void);


void UART_TransmitDataAsynchronous(u8 Data);

void UART_ReceiveDataAsynchronous(u8 * ReceivedData);

void UART_SendString(u8 * String);


void UART_SetTXCCallBack(void(*pvNotificationFunction)(void));

void UART_SetUDRECallBack(void(*pvNotificationFunction)(void));

void UART_SetRXCCallBack(void(*pvNotificationFunction)(void));




#endif /* MCAL_UART_UART_H_ */
