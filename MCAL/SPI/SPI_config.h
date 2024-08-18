/*
 * SPI_config.h
 *
 *  Created on: Aug 18, 2024
 *      Author: markk
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#include "ATMEGA32_REG.h"
#include "MACROS.h"
#include "STD_TYPES.h"



#define SPI_PORT 		GPIO_PORTB

#define SPI_MOSI_PIN 	GPIO_PIN5
#define SPI_MISO_PIN 	GPIO_PIN6
#define SPI_SCK_PIN 	GPIO_PIN7
#define SPI_SS_PIN 		GPIO_PIN4

/*
    ORTIONS:
    DIV_FACTOR_4
    DIV_FACTOR_16
    DIV_FACTOR_64
    DIV_FACTOR_128
    DIV_FACTOR_2X_2
    DIV_FACTOR_2X_8
    DIV_FACTOR_2X_32
    DIV_FACTOR_2X_64
*/
#define     SPI_SCK_SEL       DIV_FACTOR_16


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
