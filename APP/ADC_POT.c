/*
 * ADC_POT.c
 *
 *  Created on: Aug 8, 2024
 *      Author: markk
 */

#include "ADC/ADC.h"
#include "GPIO/GPIO.h"
#include <util/delay.h>

int main(){
	ADC_Init(ADC_REF_AVCC ,ADC_LEFTADJUST,ADC_MUX_0,ADC_CLK_64);
	GPIO_SetPortDirection(GPIO_PORTC , GPIO_OUTPUT);

	while(1){
		u16 adc_value = ADC_GetValue();
		GPIO_SetPortValue(GPIO_PORTC , (adc_value >> 2));
		_delay_ms(100);

	}


	return 0;
}
