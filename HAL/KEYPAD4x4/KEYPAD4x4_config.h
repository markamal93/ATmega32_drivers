/*
 * KEYPAD4x4_config.h
 *
 *  Created on: Jul 29, 2024
 *      Author: markk
 */

#ifndef HAL_KEYPAD4X4_KEYPAD4X4_CONFIG_H_
#define HAL_KEYPAD4X4_KEYPAD4X4_CONFIG_H_

#define 	KPD_ROWS_PORT       	GPIO_PORTD
#define 	KPD_COLUMNS_PORT    	GPIO_PORTD


#define 	KPD_ROW0_PIN        GPIO_PIN0
#define 	KPD_ROW1_PIN        GPIO_PIN1
#define 	KPD_ROW2_PIN        GPIO_PIN2
#define 	KPD_ROW3_PIN        GPIO_PIN3

#define 	KPD_COLUMN0_PIN     GPIO_PIN4
#define 	KPD_COLUMN1_PIN     GPIO_PIN5
#define 	KPD_COLUMN2_PIN     GPIO_PIN6
#define 	KPD_COLUMN3_PIN     GPIO_PIN7

#define 	KPD_NOT_PRESSED_VAL 		255

#define     KPD_ARR_VAL          {{'7', '8', '9', '/'},{'4', '5', '6', '*'},{'1', '2', '3', '-'},{'#', '0', '=', '+'}}
#define     KPD_ROWS_NUM        	4
#define     KPD_COULMNS_NUM     	4


#endif /* HAL_KEYPAD4X4_KEYPAD4X4_CONFIG_H_ */
