/*
 * ATMEGA32_REG.h
 *
 *  Created on: Jul 28, 2024
 *      Author: markk
 */

#ifndef UTILS_ATMEGA32_REG_H_
#define UTILS_ATMEGA32_REG_H_

/*/
 *
 * =======================GPIO REGISTERS========================================
 *
 */

#define DDRA *((volatile u8* const) 0x3A)
#define PORTA *((volatile u8* const) 0x3B)
#define PINA *((volatile u8* const) 0x39)

#define DDRB *((volatile u8* const) 0x24)
#define PORTB *((volatile u8* const) 0x25)
#define PINB *((volatile u8* const) 0x23)

#define DDRC *((volatile u8* const) 0x34)
#define PORTC *((volatile u8* const) 0x35)
#define PINC *((volatile u8* const) 0x33)


#define DDRD *((volatile u8* const) 0x31)
#define PORTD *((volatile u8* const) 0x32)
#define PIND *((volatile u8* const) 0x30)

/*/
 *
 * =======================ADC REGISTERS=========================================
 *
 */
#define ADMUX *((volatile u8* const) 0x27)
#define ADCSRA *((volatile u8* const) 0x26)
#define ADCH *((volatile u8* const) 0x25)
#define ADCL *((volatile u8* const) 0x24)

#define ADMUX_MUX0     0
#define ADMUX_MUX1     1
#define ADMUX_MUX2     2
#define ADMUX_MUX3     3
#define ADMUX_MUX4     4
#define ADMUX_ADLAR    5
#define ADMUX_REFS0    6
#define ADMUX_REFS1    7

#define ADCSRA_ADPS0     0
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS2     2
#define ADCSRA_ADIE      3
#define ADCSRA_ADIF      4
#define ADCSRA_ADATE     5
#define ADCSRA_ADSC      6
#define ADCSRA_ADEN      7

/************************* TIMER0 *****************************/

#define TIFR      *((volatile u8*)0x58)
#define TIMSK     *((volatile u8*)0x59)

#define TCNT0     *((volatile u8*)0x52)
#define TCCR0     *((volatile u8*)0x53)
#define OCR0      *((volatile u8*)0x5C)

#define TCCR1A    *((volatile u8*)0x4F)
#define TCCR1B    *((volatile u8*)0x4E)
#define TCCR1     *((volatile u16*)0x4E)
#define TCNT1H    *((volatile u8*)0x4D)
#define TCNT1L    *((volatile u8*)0x4C)
#define TCNT1     *((volatile u16*)0x4C)
#define OCR1AH    *((volatile u8*)0x4B)
#define OCR1AL    *((volatile u8*)0x4A)
#define OCR1A     *((volatile u16*)0x4A)
#define OCR1BH    *((volatile u8*)0x49)
#define OCR1BL    *((volatile u8*)0x48)
#define OCR1B     *((volatile u16*)0x48)
#define ICR1H     *((volatile u8*)0x47)
#define ICR1L     *((volatile u8*)0x46)
#define ICR1      *((volatile u16*)0x46)

#define TCNT2     *((volatile u8*)0x44)
#define TCCR2     *((volatile u8*)0x45)
#define OCR2      *((volatile u8*)0x43)

#define ASSR      *((volatile u8*)0x42)

#define NULL      '\0'

#define TIFR_TOV0         0
#define TIFR_OCF0         1
#define TIFR_TOV1         2
#define TIFR_OCF1B        3
#define TIFR_OCF1A        4
#define TIFR_ICF1         5
#define TIFR_TOV2         6
#define TIFR_OCF2         7

#define TIMSK_TOIE0       0
#define TIMSK_OCIE0       1
#define TIMSK_TOIE1       2
#define TIMSK_OCIE1B      3
#define TIMSK_OCIE1A      4
#define TIMSK_TICIE1      5
#define TIMSK_TOIE2       6
#define TIMSK_OCIE2       7

#define TCCR0_CS00        0
#define TCCR0_CS01        1
#define TCCR0_CS02        2
#define TCCR0_WGM01       3
#define TCCR0_COM00       4
#define TCCR0_COM01       5
#define TCCR0_WGM00       6
#define TCCR0_FOC0        7

#define TCCR1A_WGM10      0
#define TCCR1A_WGM11      1
#define TCCR1A_FOC1B      2
#define TCCR1A_FOC1A      3
#define TCCR1A_COM1B0     4
#define TCCR1A_COM1B1     5
#define TCCR1A_COM1A0     6
#define TCCR1A_COM1A1     7

#define TCCR1B_CS10       0
#define TCCR1B_CS11       1
#define TCCR1B_CS12       2
#define TCCR1B_WGM12      3
#define TCCR1B_WGM13      4
#define TCCR1B_ICES1      6
#define TCCR1B_ICNC1      7

#define TCCR2_CS20        0
#define TCCR2_CS21        1
#define TCCR2_CS22        2
#define TCCR2_WGM21       3
#define TCCR2_COM20       4
#define TCCR2_COM21       5
#define TCCR2_WGM20       6
#define TCCR2_FOC2        7

#define ASSR_AS2          3
/******************************Register Description*******************************/

#define TIFR      *((volatile u8*)0x58)
#define TIMSK     *((volatile u8*)0x59)

#define TCNT0     *((volatile u8*)0x52)
#define TCCR0     *((volatile u8*)0x53)
#define OCR0      *((volatile u8*)0x5C)

#define TCCR1A    *((volatile u8*)0x4F)
#define TCCR1B    *((volatile u8*)0x4E)
#define TCCR1     *((volatile u16*)0x4E)
#define TCNT1H    *((volatile u8*)0x4D)
#define TCNT1L    *((volatile u8*)0x4C)
#define TCNT1     *((volatile u16*)0x4C)
#define OCR1AH    *((volatile u8*)0x4B)
#define OCR1AL    *((volatile u8*)0x4A)
#define OCR1A     *((volatile u16*)0x4A)
#define OCR1BH    *((volatile u8*)0x49)
#define OCR1BL    *((volatile u8*)0x48)
#define OCR1B     *((volatile u16*)0x48)
#define ICR1H     *((volatile u8*)0x47)
#define ICR1L     *((volatile u8*)0x46)
#define ICR1      *((volatile u16*)0x46)

#define TCNT2     *((volatile u8*)0x44)
#define TCCR2     *((volatile u8*)0x45)
#define OCR2      *((volatile u8*)0x43)

#define ASSR      *((volatile u8*)0x42)

#define NULL      '\0'

#define TIFR_TOV0         0
#define TIFR_OCF0         1
#define TIFR_TOV1         2
#define TIFR_OCF1B        3
#define TIFR_OCF1A        4
#define TIFR_ICF1         5
#define TIFR_TOV2         6
#define TIFR_OCF2         7

#define TIMSK_TOIE0       0
#define TIMSK_OCIE0       1
#define TIMSK_TOIE1       2
#define TIMSK_OCIE1B      3
#define TIMSK_OCIE1A      4
#define TIMSK_TICIE1      5
#define TIMSK_TOIE2       6
#define TIMSK_OCIE2       7

#define TCCR0_CS00        0
#define TCCR0_CS01        1
#define TCCR0_CS02        2
#define TCCR0_WGM01       3
#define TCCR0_COM00       4
#define TCCR0_COM01       5
#define TCCR0_WGM00       6
#define TCCR0_FOC0        7

#define TCCR1A_WGM10      0
#define TCCR1A_WGM11      1
#define TCCR1A_FOC1B      2
#define TCCR1A_FOC1A      3
#define TCCR1A_COM1B0     4
#define TCCR1A_COM1B1     5
#define TCCR1A_COM1A0     6
#define TCCR1A_COM1A1     7

#define TCCR1B_CS10       0
#define TCCR1B_CS11       1
#define TCCR1B_CS12       2
#define TCCR1B_WGM12      3
#define TCCR1B_WGM13      4
#define TCCR1B_ICES1      6
#define TCCR1B_ICNC1      7

#define TCCR2_CS20        0
#define TCCR2_CS21        1
#define TCCR2_CS22        2
#define TCCR2_WGM21       3
#define TCCR2_COM20       4
#define TCCR2_COM21       5
#define TCCR2_WGM20       6
#define TCCR2_FOC2        7

#define ASSR_AS2          3

/*/
 *
 * =======================SYSCNTRL REGISTERS======================================
 *
 */
#define MCUCR * ((volatile u8 *) 0x55)

/*/
 *
 * =======================UART REGISTERS========================================
 *
 */
#define UCSRB * ((volatile u8*) 0x2A)
#define UCSRA * ((volatile u8*) 0x2B)
#define UBRRL * ((volatile u8*) 0x29)
#define UDR * ((volatile u8*)) 0x2C)

/*/
 *
 * =======================SPI REGISTERS=========================================
 *
 */
#define SPCR * ((u8* const) 0x2D)
#define SPDR * ((volatile u8* const) 0x2F)
#define SPSR * ((volatile u8* const) 0x2E)

/*/
 *
 * =======================I2C REGISTERS========================================
 *
 */
#define TWCR * ((volatile u8 * const) 0x56)
#define TWDR * ((volatile u8 * const) 0x23)
#define TWAR * ((volatile u8 * const) 0x22)
#define TWSR * ((volatile u8 * const) 0x21)
#define TWBR * ((volatile u8 * const) 0x20)


#endif /* UTILS_ATMEGA32_REG_H_ */
