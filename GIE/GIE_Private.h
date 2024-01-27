/*
 * GIE_Private.h
 * GIE driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

#define SREG             *((volatile u8*)0x5F)
#define SREG_I           7                             //Global Interrupt Enable

#endif /* GIE_PRIVATE_H_ */
