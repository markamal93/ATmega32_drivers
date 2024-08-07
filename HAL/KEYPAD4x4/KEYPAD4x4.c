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

	GPIO_SetPinDirection(KPD_ROWS_PORT, KPD_ROW0_PIN, GPIO_INPUT);
	GPIO_SetPinDirection(KPD_ROWS_PORT, KPD_ROW1_PIN, GPIO_INPUT);
	GPIO_SetPinDirection(KPD_ROWS_PORT, KPD_ROW2_PIN, GPIO_INPUT);
	GPIO_SetPinDirection(KPD_ROWS_PORT, KPD_ROW3_PIN, GPIO_INPUT);

	GPIO_SetPinValue(KPD_ROWS_PORT, KPD_ROW0_PIN, STD_HIGH);
	GPIO_SetPinValue(KPD_ROWS_PORT, KPD_ROW1_PIN, STD_HIGH);
	GPIO_SetPinValue(KPD_ROWS_PORT, KPD_ROW2_PIN, STD_HIGH);
	GPIO_SetPinValue(KPD_ROWS_PORT, KPD_ROW3_PIN, STD_HIGH);

    GPIO_SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, GPIO_OUTPUT);

    GPIO_SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, STD_HIGH);
    GPIO_SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, STD_HIGH);
    GPIO_SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, STD_HIGH);
    GPIO_SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, STD_HIGH);
}
u8 KEYPAD_GetKey(void){
	 static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COULMNS_NUM] = KPD_ARR_VAL;
	    static u8 Local_u8KPDColumnsArray[KPD_COULMNS_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	    static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	    u8 Local_u8RowValue;
	    u8 Local_u8ColumnsIterator;
	    u8 Local_u8RowsIterator;
	    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL;
	    for(Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COULMNS_NUM; Local_u8ColumnsIterator++)
	    {
	        GPIO_SetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], STD_LOW);
	        for(Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM; Local_u8RowsIterator++)
	        {
	            Local_u8RowValue = GPIO_GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
	            if(Local_u8RowValue == STD_LOW)
	            {
	                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];
	                while(Local_u8RowValue == STD_LOW)
	                {
	                    Local_u8RowValue = GPIO_GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
	                }
	                return Local_u8PressedKey;
	            }
	        }
	        GPIO_SetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], STD_HIGH);
	    }
	    return Local_u8PressedKey;
}

