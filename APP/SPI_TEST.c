/*
 * SPI_TEST.c
 *
 *  Created on: Aug 18, 2024
 *      Author: markk
 */

#include "SPI/SPI.h"

int main (void){
	SPI_InitMaster();

	while(1){
		SPI_TransferByte('m');

	}
}
