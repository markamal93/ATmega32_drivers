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

/*/
 *
 * =======================TIMER_0 REGISTERS=====================================
 *
 */


#define TCCR0 *((volatile u8* const) 0x53)
#define TCNT0 *((volatile u8* const) 0x52)
#define OCR0 *((volatile u8* const) 0x5C)


/*/
 *
 * =======================TIMER_1 REGISTERS=====================================
 *
 */
#define TCCR1A *((volatile u8* const) 0x4F)
#define TCCR1B *((volatile u8* const) 0x4E)
#define OCR1AH *((volatile u8* const) 0x4A)
#define OCR1AL *((volatile u8* const) 0x4B)
#define OCR1A * ((volatile u8* const) 0x4B)
#define OCR1BH *((volatile u8* const) 0x49)
#define OCR1BL  *((volatile u8* const) 0x48)
#define OCR1B *((volatile u8* const) 0x48)

/*/
 *
 * =======================TIMER_2 REGISTERS=====================================
 *
 */
#define TCCR2 * ((volatile u8*) 0x45)
#define TCNT2 * ((volatile u8*) 0x44)
#define OCR2 * ((volatile u8*) 0x43)
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
