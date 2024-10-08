/*
 * LCD16x2.h
 *
 *  Created on: Jul 29, 2024
 *      Author: markk
 */

#ifndef HAL_LCD16X2_LCD16X2_H_
#define HAL_LCD16X2_LCD16X2_H_

#include "LCD16x2_config.h"
#include "GPIO/GPIO.h"
#include <util/delay.h>


#define LCD_D0 GPIO_PIN0
#define LCD_D1 GPIO_PIN1
#define LCD_D2 GPIO_PIN2
#define LCD_D3 GPIO_PIN3
#define LCD_D4 GPIO_PIN4
#define LCD_D5 GPIO_PIN5
#define LCD_D6 GPIO_PIN6
#define LCD_D7 GPIO_PIN7

#define LCD_8MODE_2L 0x38
#define LCD_ON_NOCURSOR 0x0C
#define LCD_CLEAR_SCREEN 0b00000001
#define LCD_RETURN_HOME 0b00000010

#define LCD_XPOS0 0
#define LCD_XPOS1 1
#define LCD_XPOS2 2
#define LCD_XPOS3 3
#define LCD_XPOS4 4
#define LCD_XPOS5 5
#define LCD_XPOS6 6
#define LCD_XPOS7 7
#define LCD_XPOS8 8
#define LCD_XPOS9 9
#define LCD_XPOS10 10
#define LCD_XPOS11 11
#define LCD_XPOS12 12
#define LCD_XPOS13 13
#define LCD_XPOS14 14
#define LCD_XPOS15 15
#define LCD_XPOS16 16
#define LCD_XPOS17 17
#define LCD_XPOS18 18
#define LCD_XPOS19 19

#define LCD_YPOS0 0
#define LCD_YPOS1 1
#define LCD_YPOS2 2
#define LCD_YPOS3 3
/*This macro is used to shift the clock digits
 *on LCD row.
 * */
#define  LCD_XPOS_SHIFT 6

/*LCD configurations*/

/*Entry mode*/
#define LCD_SET_ENTRY_MODE 0x04
#define LCD_MOVE_CURSOR_RIGHT 0x02
#define LCD_MOVE_CURSOR_LEFT 0x00
#define LCD_DISPLAY_SHIFT_ON 0x01
#define LCD_DISPLAY_SHIFT_OFF 0x00


/*Display on/off control */
#define LCD_DISPLAY_ON 0x0C
#define LCD_DISPLAY_OFF 0x08

#define LCD_CURSOR_ON 0x0A
#define LCD_CURSOR_OFF 0x08

#define LCD_CURSOR_BLINK_ON 0x09
#define LCD_CURSOR_BLINK_OFF 0x08

/*Function set*/
#define LCD_FUNCTION_SET 0x20
#define LCD_8BIT 0x10
#define LCD_4BIT 0x00
#define LCD_4LINES 0x08

void LCD_Init(void);
void LCD_SendCommand(u8);
void LCD_SendChar(u8);
void LCD_SendString(u8*);
void LCD_GotoXy(u8,u8);
void LCD_SendNumber(u16 number);








#endif /* HAL_LCD16X2_LCD16X2_H_ */
