/*
 * SPI.h
 *
 *  Created on: Aug 18, 2024
 *      Author: markk
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "SPI_config.h"


#define SPI_CLK_RISING 0
#define SPI_CLK_FALLING 1

#define SPI_CLK_PHASE_SAMPLE 0
#define SPI_CLK_PHASE_SETUP 1

/*Prescaler definitions*/
#define SPI_CLK_PRES_4 0
#define SPI_CLK_PRES_16 1
#define SPI_CLK_PRES_64 2
#define SPI_CLK_PRES_128 3
#define SPI_CLK_PRES_2 4
#define SPI_CLK_PRES_8 5
#define SPI_CLK_RPES_32 6
#define SPI_CLK_RPES_64 7


void SPI_InitMaster(void);
void SPI_InitSlave(void);
void SPI_EnableSS(void);
void SPI_DisableSS(void);
void SPI_TransferByte(u8);
u8 SPI_ReceiveByte(void);
void SPI_SendString(u8 * u8String);
void SPI_EnableInterrupt(void);
void SPI_DisableInterrupt(void);





#endif /* MCAL_SPI_SPI_H_ */
