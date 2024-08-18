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


typedef struct {
	u8 RxTxEnable;
	u8 ParityBits;
	u8 StopBits;
	u8 CharacterSize;
	u8 BaudRateHigh;
	u8 BaudRateLow;
} UARTConfig_t;

#define UART_ENABLE_TXRX 			0
#define UART_ENABLE_TX 				1
#define UART_ENABLE_RX 				2

#define UART_PARITYBITS_DISABLED 	0
#define UART_PARITYBITS_EVEN 		1
#define UART_PARITYBITS_ODD 		2

#define UART_STOPBITS_1 			0
#define UART_STOPBITS_2 			1

#define UART_CHARSIZE_5 			0
#define UART_CHARSIZE_6 			1
#define UART_CHARSIZE_7 			2
#define UART_CHARSIZE_8 			3
#define UART_CHARSIZE_9 			4



#define UART_ENABLE_TXRX 0
#define UART_ENABLE_TX 1
#define UART_ENABLE_RX 2

#define UART_PARITYBITS_DISABLED 0
#define UART_PARITYBITS_EVEN 1
#define UART_PARITYBITS_ODD 2

#define UART_STOPBITS_1 0
#define UART_STOPBITS_2 1

#define UART_CHARSIZE_5 0
#define UART_CHARSIZE_6 1
#define UART_CHARSIZE_7 2
#define UART_CHARSIZE_8 3
#define UART_CHARSIZE_9 4

void UART_vidInit(void);
//void UART_vidInitExpanded(UARTConfig_t *);
void UART_vidSendByte(u8);
u8 UART_u8ReceiveByte(void);
u8 UART_u8GetReceivedByte(void);
void UART_vidSendLine(void);
void UART_vidSendString(u8 *);


#endif /* MCAL_UART_UART_H_ */
