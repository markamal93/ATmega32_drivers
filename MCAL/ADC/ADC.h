/*
 * ADC.h
 *
 *  Created on: Aug 7, 2024
 *      Author: markk
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "ADC_config.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "GPIO/GPIO.h"

#define     ADC_INTERRUPT_ENABLE                  1
#define     ADC_INTERRUPT_DISABLE                 0

#define     CHANNEL0                    0b00000000
#define     CHANNEL1                    0b00000001
#define     CHANNEL2                    0b00000010
#define     CHANNEL3                    0b00000011
#define     CHANNEL4                    0b00000100
#define     CHANNEL5                    0b00000101
#define     CHANNEL6                    0b00000110
#define     CHANNEL7                    0b00000111

#define     RIGHT_ADJUST            0
#define     LEFT_ADJUST             1

//#define     AREF                    0
//#define     AVCC                    1
//#define     INTERNAL_2v56           2

#define     ENABLE                  1
#define     DISABLE                 0

#define     AREF                    0b00000000
#define     AVCC                    0b01000000
#define     INTERNAL_2v56           0b11000000
#define     REF_SEL_BIT_MASK        0b00111111

#define     DIV_FACTOR_2            0b00000000
#define     DIV_FACTOR_4            0b00000010
#define     DIV_FACTOR_8            0b00000011
#define     DIV_FACTOR_16           0b00000100
#define     DIV_FACTOR_32           0b00000101
#define     DIV_FACTOR_64           0b00000110
#define     DIV_FACTOR_128          0b00000111
#define     PRE_SCALER_BIT_MASK     0b11111000

#define     CHANNEL_SELECTION_MASK      0b11100000

void ADC_Init(void);
void ADC_InterruptControl(u8 InterruptStatus);
u8 ADC_StartConversionSynchronous(u8 ChannelNumber);
void ADC_ADCSetCallback(void (*NotificationFunction)(void));
u8 ADC_StartConversionAsynchronous(u8 ChannelNumber, void (*NotificationFunction)(void));


#endif /* MCAL_ADC_ADC_H_ */
