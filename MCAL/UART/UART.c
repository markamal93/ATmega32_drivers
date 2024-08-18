#include "UART.h"

void UART_vidInit(void) {

	//Setting both Receive Enable and Transmit Enable
	//Setting both Receive Enable and Transmit Enable
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);
	//set data bit size
#if DATA_SIZE == DATA_SIZE_5BIT
	CLEAR_BIT(UCSRC , UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_6BIT
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_7BIT
	CLEAR_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_8BIT
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB , UCSRB_UCSZ2);
#elif DATA_SIZE == DATA_SIZE_8BIT
	SET_BIT(UCSRC , UCSRC_UCSZ0);
	SET_BIT(UCSRC , UCSRC_UCSZ1);
	SET_BIT(UCSRB , UCSRB_UCSZ2);
#endif


	//No parity
#if PARITY_MODE	== PARITY_DISABLED
	 CLEAR_BIT(UCSRC , UCSRC_UPM0);
	 CLEAR_BIT(UCSRC , UCSRC_UPM1);
#elif PARITY_MODE	== EVEN_PARITY
	 CLEAR_BIT(UCSRC , UCSRC_UPM0);
	 SET_BIT(UCSRC , UCSRC_UPM1);
#elif PARITY_MODE	== ODD_PARITY
	 SET_BIT(UCSRC , UCSRC_UPM0);
	 SET_BIT(UCSRC , UCSRC_UPM1);
#endif

	//Number of stop bits
#if STOP_BIT_SELECT == ONE_BIT
	 CLEAR_BIT(UCSRC,UCSRC_USBS);
#elif STOP_BIT_SELECT == TWO_BITS
	 SET_BIT(UCSRC,UCSRC_USBS);
#endif

#if BAUDRATE_VALUE == BR_9600_BPS
	//Selecting UBRRH
	UBRRH = 0;
	UBRRL = 51;
#elif BAUDRATE_VALUE == BR_4800_BPS
	//Selecting UBRRH
	UBRRH = 0;
	UBRRL = 103;
#elif BAUDRATE_VALUE == BR_2400_BPS
	UBRRH = 0;
	UBRRL = 207;
#endif
}


void UART_vidSendByte(u8 u8byteCpy) {
	while (GET_BIT(UCSRA,5) == 0); //Checking the UART Data Register Empty (UDRE) bit
	UDR = u8byteCpy;
}

u8 UART_u8ReceiveByte(void) {
	while (GET_BIT(UCSRA,7) == 0); //Checking the Receive Complete (RxE) bit
	return UDR;
}

u8 UART_u8GetReceivedByte(void)
{
	return UDR;
}

void UART_vidSendString(u8 * u8pStringCpy) {
	do {
		UART_vidSendByte(*u8pStringCpy);
	}while(*u8pStringCpy++ != '\0');
}

void UART_vidSendLine(void) {
	UART_vidSendString((u8*)"\n\r******\n\r");
}
