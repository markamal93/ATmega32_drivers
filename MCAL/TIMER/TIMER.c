/*
 * TIMER.c
 *
 *  Created on: Aug 11, 2024
 *      Author: markk
 */
#include "TIMER.h"

static void (*TIMER0_pvOVFNotificationFunction)(void) = NULL;
static void (*TIMER0_pvOCNotificationFunction)(void) = NULL;

static void (*TIMER1_pvOVFNotificationFunction)(void) = NULL;
static void (*TIMER1_pvOC1ANotificationFunction)(void) = NULL;
static void (*TIMER1_pvOC1BNotificationFunction)(void) = NULL;
static void (*TIMER1_pvICUNotificationFunction)(void) = NULL;

static void (*TIMER2_pvOVFNotificationFunction)(void) = NULL;
static void (*TIMER2_pvOCNotificationFunction)(void) = NULL;

void TIMER0_Init(void) {
#if TIMER0_MODE_SEL == TIMER0_NORMAL_MODE
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER0_MODE_SEL == TIMER0_CTC_MODE
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);
	#if TIMER0_OUTPUT_COMPARE_SEL == NORMAL_OC0_DISCONNECTED
		CLEAR_BIT(TCCR0 , TCCR0_COM01 );
		CLEAR_BIT(TCCR0 ,TCCR0_COM00 );
	#elif  TIMER0_OUTPUT_COMPARE_SEL == TOG_OC0_ON_COMPARE_MATCH
		CLEAR_BIT(TCCR0 , TCCR0_COM01 );
		SET_BIT(TCCR0 ,TCCR0_COM00 );
	#elif  TIMER0_OUTPUT_COMPARE_SEL == CLR_OC0_ON_COMPARE_MATCH
		SET_BIT(TCCR0 , TCCR0_COM01 );
		CLEAR_BIT(TCCR0 ,TCCR0_COM00 );
	#elif  TIMER0_OUTPUT_COMPARE_SEL == SET_OC0_ON_COMPARE_MATCH
		SET_BIT(TCCR0 , TCCR0_COM01 );
		SET_BIT(TCCR0 ,TCCR0_COM00 );
	#endif
#elif TIMER0_MODE_SEL == TIMER0_PHASE_CORRECT_PWM_MODE
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
	SET_BIT(TCCR0 , TCCR0_WGM00);
#elif TIMER0_MODE_SEL == TIMER0_FAST_PWM_MODE
	SET_BIT(TCCR0 , TCCR0_WGM01);
	SET_BIT(TCCR0 , TCCR0_WGM00);
#endif

#if 	TIMER0_CLK_SEL == TIMER0_STOP
	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL   ==    DIV_FACTOR_1
	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL   ==    DIV_FACTOR_8
	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL    ==   DIV_FACTOR_64
	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL    ==   DIV_FACTOR_256
	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL     ==  DIV_FACTOR_1024
	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL   ==    EXT_CLK_FALLING_T0
	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
#elif 	TIMER0_CLK_SEL    ==   EXT_CLK_RISING_T0
	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
#endif






}

void TIMER0_DisableTimer0(void){
	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);
}
void TIMER0_EnableTimer0(void);

void TIMER0_SetPreloadValue(u8 Value);
void TIMER0_SetOCMatchValue(u8 Value);

void TIMER0_SetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER0_SetOCCallBack(void (*pvNotificationFunction)(void));

void TIMER0_EnableInterrupt(u8 Mode);
void TIMER0_DisableInterrupt(u8 Mode);

void TIMER0_SetBusyWait_OVFMode(u32 Time);
void TIMER0_SetBusyWait_OCMode(u32 Time);

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
u16 ICU_GetICRRegister(void);
void ICU_SetTriggerSignal(u8 TriggerSignal);

void TIMER1_SetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER1_SetOC1ACallBack(void (*pvNotificationFunction)(void));
void TIMER1_SetOC1BCallBack(void (*pvNotificationFunction)(void));
void TIMER1_SetICUCallBack(void (*pvNotificationFunction)(void));

void TIMER2_Init(void);

void TIMER2_SetPreloadValue(u8 Value);
void TIMER2_SetOCMatchValue(u8 Value);

void TIMER2_SetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER2_SetOCCallBack(void (*pvNotificationFunction)(void));

void TIMER2_EnableInterrupt(u8 Mode);
void TIMER2_DisableInterrupt(u8 Mode);

void TIMER2_SetBusyWait_OVFMode(u32 Time);
void TIMER2_SetBusyWait_OCMode(u32 Time);

