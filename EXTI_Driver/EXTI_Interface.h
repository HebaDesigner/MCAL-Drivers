/*
 * Interface.h
 * EXTI driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#include"EXTI_Private.h"

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define Low_Level               1
#define On_Change               2
#define Falling_Edge            3
#define Rising_Edge             4

void EXTI_voidINT0_Init(void);
void EXTI_voidINT1_Init(void);
void EXTI_voidINT2_Init(void);

/* Description: A function to set the required sense control of INT0 using postbuild configuration
 * Inputs: Copy_u8Sense, options are 1- Low_Level
                                    2- On_Change
                                    3- Falling_Edge
                                    4- Rising_Edge
 * Output: Error status with type u8
*/
u8 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense_INT0);

/* Description: A function to set the required sense control of INT1 using postbuild configuration
 * Inputs: Copy_u8Sense, options are 1- Low_Level
                                    2- On_Change
                                    3- Falling_Edge
                                    4- Rising_Edge
 * Output: Error status with type u8*/
u8 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense_INT1);


/* Description: A function to set the required sense control of INT2 using postbuild configuration
 * Inputs: Copy_u8Sense, options are 1- Falling_Edge
                                     2- Rising_Edge
 * Output: Error status with type u8*/
u8 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense_INT2);


u8 EXTI_u8INTEn_Dis(u8 Copy_u8INT, u8 Copy_u8En_Dis);

u8 EXTI_u8INT0SetCallback(void (*Copy_PvINT0Func)(void));


#endif /* EXTI_INTERFACE_H_ */
