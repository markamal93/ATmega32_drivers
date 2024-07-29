/*
 * MACROS.h
 *
 *  Created on: Jul 28, 2024
 *      Author: markk
 */

#ifndef UTILS_MACROS_H_
#define UTILS_MACROS_H_

#define SET_BIT(reg,bit) reg|= (1<<bit)
#define CLEAR_BIT(reg,bit) reg&= ~(1<<bit)
#define GET_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit) reg ^= (1<<bit)





#endif /* UTILS_MACROS_H_ */
