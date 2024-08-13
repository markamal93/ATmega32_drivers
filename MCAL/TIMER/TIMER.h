/*
 * TIMER.h
 *
 *  Created on: Aug 11, 2024
 *      Author: markk
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "TIMER_config.h"
#include "ATMEGA32_REG.h"
#include "MACROS.h"
#include "STD_TYPES.h"

/************************* TIMER0 *****************************/

#define TIMER0_OVF      0
#define TIMER0_COMP     1

#define     TIMER0_NORMAL_MODE                           0b00000000
#define     TIMER0_PHASE_CORRECT_PWM_MODE                0b01000000
#define     TIMER0_CTC_MODE                              0b00001000
#define     TIMER0_FAST_PWM_MODE                         0b01001000
#define     TIMER0_MODE_SEL_BIT_MASK                     0b10110111

//#define     NORMAL_OC0_DISCONNECTED      0
//#define     TOG_OC0_ON_COMPARE_MATCH     1
//#define     CLR_OC0_ON_COMPARE_MATCH     2
//#define     SET_OC0_ON_COMPARE_MATCH     3

#define     NORMAL_OC0_DISCONNECTED         0b00000000
#define     TOG_OC0_ON_COMPARE_MATCH        0b00010000
#define     CLR_OC0_ON_COMPARE_MATCH        0b00100000
#define     SET_OC0_ON_COMPARE_MATCH        0b00110000
#define     TIMER0_OC0_MODE_BIT_MASK        0b11001111

#define     TIMER0_STOP                     0b00000000
#define     DIV_FACTOR_1                    0b00000001
#define     DIV_FACTOR_8                    0b00000010
#define     DIV_FACTOR_64                   0b00000011
#define     DIV_FACTOR_256                  0b00000100
#define     DIV_FACTOR_1024                 0b00000101
#define     EXT_CLK_FALLING_T0              0b00000110
#define     EXT_CLK_RISING_T0               0b00000111
#define     TIMER0_CLK_SEL_BIT_MASK         0b11111000



void TIMER0_Init(void);

void TIMER0_DisableTimer0(void);
void TIMER0_EnableTimer0(void);

void TIMER0_SetPreloadValue(u8 Value);
void TIMER0_SetOCMatchValue(u8 Value);

void TIMER0_SetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_SetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER0_EnableInterrupt(u8 Mode);
void TIMER0_DisableInterrupt(u8 Mode);

void TIMER0_SetBusyWait_OVFMode(u32 Time);
void TIMER0_SetBusyWait_OCMode(u32 Time);

/************************* TIMER1 *****************************/

#define     TIMER1_OVF            0
#define     TIMER1_COMPB          1
#define     TIMER1_COMPA          2
#define     TIMER1_CAPT           3

#define     ICU_ENABLE            1
#define     ICU_DISABLE           0

#define     ICU_RISING_EDGE       1
#define     ICU_FALLING_EDGE      0


#define     NORMAL_OC1A_DISCONNECTED         0b00000000
#define     TOG_OC1A_ON_COMPARE_MATCH        0b01000000
#define     CLR_OC1A_ON_COMPARE_MATCH        0b10000000
#define     SET_OC1A_ON_COMPARE_MATCH        0b11000000
#define     TIMER1_OC1A_MODE_BIT_MASK        0b00111111

#define     NORMAL_OC1B_DISCONNECTED         0b00000000
#define     TOG_OC1B_ON_COMPARE_MATCH        0b00010000
#define     CLR_OC1B_ON_COMPARE_MATCH        0b00100000
#define     SET_OC1B_ON_COMPARE_MATCH        0b00110000
#define     TIMER1_OC1B_MODE_BIT_MASK        0b11001111

#define     TIMER1_STOP                     0b00000000
#define     DIV_FACTOR_1                    0b00000001
#define     DIV_FACTOR_8                    0b00000010
#define     DIV_FACTOR_64                   0b00000011
#define     DIV_FACTOR_256                  0b00000100
#define     DIV_FACTOR_1024                 0b00000101
#define     EXT_CLK_FALLING_T1              0b00000110
#define     EXT_CLK_RISING_T1               0b00000111
#define     TIMER1_CLK_SEL_BIT_MASK         0b11111000

#define     TIMER1_NORMAL_MODE                                  0b0000000000000000
#define     TIMER1_PHASE_CORRECT_PWM_8_BIT_MODE                 0b0000000000000001
#define     TIMER1_PHASE_CORRECT_PWM_9_BIT_MODE                 0b0000000000000010
#define     TIMER1_PHASE_CORRECT_PWM_10_BIT_MODE                0b0000000000000011
#define     TIMER1_CTC_OCR1A_MODE                               0b0000100000000000
#define     TIMER1_FAST_PWM_8_BIT_MODE                          0b0000100000000001
#define     TIMER1_FAST_PWM_9_BIT_MODE                          0b0000100000000010
#define     TIMER1_FAST_PWM_10_BIT_MODE                         0b0000100000000011
#define     TIMER1_PHASE_FREQ_CORRECT_PWM_ICR1_MODE             0b0001000000000000
#define     TIMER1_PHASE_FREQ_CORRECT_PWM_OCR1A_MODE            0b0001000000000001
#define     TIMER1_PHASE_CORRECT_PWM_ICR1_MODE                  0b0001000000000010
#define     TIMER1_PHASE_CORRECT_PWM_OCR1A_MODE                 0b0001000000000011
#define     TIMER1_CTC_ICR1_MODE                                0b0001100000000000
#define     TIMER1_FAST_PWM_ICR1_MODE                           0b0001100000000010
#define     TIMER1_FAST_PWM_OCR1A_MODE                          0b0001100000000011
#define     TIMER1_MODE_SEL_BIT_MASK                            0b1110011111111100


void TIMER1_Init(void);

void TIMER1_SetPreloadValue(u16 Value);
void TIMER1_SetOC1AMatchValue(u16 Value);
void TIMER1_SetOC1BMatchValue(u16 Value);
void TIMER1_SetICR1Value(u16 Value);

void TIMER1_EnableInterrupt(u8 Mode);
void TIMER1_DisableInterrupt(u8 Mode);

void TIMER1_SetBusyWait_OVFMode(u32 Time);
void TIMER1_SetBusyWait_OC1BMode(u32 Time);
void TIMER1_SetBusyWait_OC1AMode(u32 Time);

void ICU_InterruptControl(u8 InterruptEnable);
u16  ICU_GetICRRegister(void);
void ICU_SetTriggerSignal(u8 TriggerSignal);

void TIMER1_SetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER1_SetOC1ACallBack(void(*pvNotificationFunction)(void));
void TIMER1_SetOC1BCallBack(void(*pvNotificationFunction)(void));
void TIMER1_SetICUCallBack(void(*pvNotificationFunction)(void));

/************************* TIMER2 *****************************/

#define TIMER2_OVF      0
#define TIMER2_COMP     1

#define CLK      1
#define OSC      0

#define     TIMER2_NORMAL_MODE                           0b00000000
#define     TIMER2_PHASE_CORRECT_PWM_MODE                0b01000000
#define     TIMER2_CTC_MODE                              0b00001000
#define     TIMER2_FAST_PWM_MODE                         0b01001000
#define     TIMER2_MODE_SEL_BIT_MASK                     0b10110111

#define     NORMAL_OC2_DISCONNECTED         0b00000000
#define     TOG_OC2_ON_COMPARE_MATCH        0b00010000
#define     CLR_OC2_ON_COMPARE_MATCH        0b00100000
#define     SET_OC2_ON_COMPARE_MATCH        0b00110000
#define     TIMER2_OC2_MODE_BIT_MASK        0b11001111

#define     TIMER2_STOP                     0b00000000
#define     DIV_FACTOR_1                    0b00000001
#define     DIV_FACTOR_8                    0b00000010
#define     DIV_FACTOR_32                   0b00000011
#define     DIV_FACTOR_64                   0b00000100
#define     DIV_FACTOR_128                  0b00000101
#define     DIV_FACTOR_256                  0b00000110
#define     DIV_FACTOR_1024                 0b00000111
#define     TIMER2_CLK_SEL_BIT_MASK         0b11111000


void TIMER2_Init(void);

void TIMER2_SetPreloadValue(u8 Value);
void TIMER2_SetOCMatchValue(u8 Value);

void TIMER2_SetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER2_SetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER2_EnableInterrupt(u8 Mode);
void TIMER2_DisableInterrupt(u8 Mode);

void TIMER2_SetBusyWait_OVFMode(u32 Time);
void TIMER2_SetBusyWait_OCMode(u32 Time);

#endif /* MCAL_TIMER_TIMER_H_ */
