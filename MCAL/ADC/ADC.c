
#include "ADC.h"
void ADC_Init(void){
	   /* ADC Enable */
	    #if ADC_ENABLE == ENABLE
	        SET_BIT(ADCSRA, ADCSRA_ADEN);
	    #elif ADC_ENABLE == DISABLE
	        CLR_BIT(ADCSRA, ADCSRA_ADEN);
	    #else
	        #error("Error, ADC_ENABLE Configuration error")
	    #endif


	    /* ADC Interrupt Enable */
	        /* Pre Build */
	    #if ADC_INTERRUPT_STATUS == ENABLE
	        SET_BIT(ADCSRA, ADCSRA_ADIE);
	    #elif ADC_INTERRUPT_STATUS == DISABLE
	        CLR_BIT(ADCSRA, ADCSRA_ADIE);
	    #else
	        #error("Error, ADC_INTERRUPT_STATUS Configuration error")
	    #endif


	    /* Reference voltage choose */
	    /*
	    #if ADC_Reference_SECTION == AREF
	        CLR_BIT(ADMUX, ADMUX_REFS0);
	        CLR_BIT(ADMUX, ADMUX_REFS1);
	    #elif ADC_Reference_SECTION == AVCC
	        SET_BIT(ADMUX, ADMUX_REFS0);
	        CLR_BIT(ADMUX, ADMUX_REFS1);
	    #elif ADC_Reference_SECTION == INTERNAL_2v56
	        SET_BIT(ADMUX, ADMUX_REFS0);
	        SET_BIT(ADMUX, ADMUX_REFS1);
	    #else
	        #error("Error, ADC_Reference_SECTION Configuration error")
	    #endif
	    */

	    /* Reference voltage choose by bit masking */
	    ADMUX &= REF_SEL_BIT_MASK;
	    ADMUX |= ADC_Reference_SELCTION;

	    /* Adjust Result */
	    #if ADC_ADJUST_RESULT == RIGHT_ADJUST
	        CLR_BIT(ADMUX, ADMUX_ADLAR);
	    #elif ADC_ADJUST_RESULT == LEFT_ADJUST
	        SET_BIT(ADMUX, ADMUX_ADLAR);
	    #else
	        #error("Error, ADC_ADJUST_RESULT Configuration error")
	    #endif

	    /* Pre-Scaler by bit mask */
	    ADCSRA &= PRE_SCALER_BIT_MASK;
	    ADCSRA |= ADC_PRESCALER;

}
void ADC_InterruptControl(u8 InterruptStatus){

	/*Post Build*/
	    switch (InterruptStatus)
	    {
	    case ADC_INTERRUPT_DISABLE:
	        CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
	        break;
	    case ADC_INTERRUPT_ENABLE:
	        SET_BIT(ADCSRA, ADCSRA_ADIE);
	        break;
	    default:
	        /* Do Nothing */
	        break;
	    }

}
u8 ADC_StartConversionSynchronous(u8 ChannelNumber){
	 /* Set Channel */
	    ADMUX &= CHANNEL_SELECTION_MASK;
	    ADMUX |= ChannelNumber;

	    /* ADC start convertion */
	    SET_BIT(ADCSRA, ADCSRA_ADSC);

	    /* Polling (Busy wait) till the flag is raised */
	    while (GET_BIT(ADCSRA, ADCSRA_ADIF) == FALSE);

	    /* Clear flag */
	    SET_BIT(ADCSRA, ADCSRA_ADIF);

	    /* Return value */
	    u8 DigitalValue;
	    #if ADC_ADJUST_RESULT == LEFT_ADJUST
	    DigitalValue = ADCH;
	    #elif ADC_ADJUST_RESULT == RIGHT_ADJUST
	    Local_u8DigitalValue = ADCL;
	    #endif

	    return DigitalValue;
	}


