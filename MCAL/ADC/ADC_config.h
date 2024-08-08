/*
 * ADC_config.h
 *
 *  Created on: Aug 7, 2024
 *      Author: markk
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#include "ATMEGA32_REG.h"

/*
    ORTIONS:
    RIGHT_ADJUST
    LEFT_ADJUST
*/
#define     ADC_ADJUST_RESULT       LEFT_ADJUST

/*
    ORTIONS:
    AREF
    AVCC
    INTERNAL_2v56
*/
#define     ADC_Reference_SELCTION       AVCC

/*
    ORTIONS:
    DIV_FACTOR_2
    DIV_FACTOR_4
    DIV_FACTOR_8
    DIV_FACTOR_16
    DIV_FACTOR_32
    DIV_FACTOR_64
    DIV_FACTOR_128
*/
#define     ADC_PRESCALER       DIV_FACTOR_64

/*
    ORTIONS:
    ENABLE
    DISABLE
*/
#define     ADC_INTERRUPT_STATUS      ENABLE

/*
    ORTIONS:
    ENABLE
    DISABLE
*/
#define         ADC_ENABLE              ENABLE


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
