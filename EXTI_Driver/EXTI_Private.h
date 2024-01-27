/*
 * EXTI_Private.h
 * EXTI driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR                   *((volatile u8*)0x55)
#define MCUCR_ISC11_INT1        3
#define MCUCR_ISC10_INT1        2
#define MCUCR_ISC01_INT0        1
#define MCUCR_ISC00_INT0        0

#define MCUCSR                  *((volatile u8*)0x54)
#define MCUCSR_INT2             6

#define GICR                    *((volatile u8*)0x5B)
#define GICR_INT1               7
#define GICR_INT0               6
#define GICR_INT2               5

#define GIFR                    *((volatile u8*)0x5A)

#define Enabled_INT0                 1
#define Disabled_INT0                2

#define Enabled_INT1                 3
#define Disabled_INT1                4

#define Enabled_INT2                 5
#define Disabled_INT2                6

#endif /* EXTI_PRIVATE_H_ */
