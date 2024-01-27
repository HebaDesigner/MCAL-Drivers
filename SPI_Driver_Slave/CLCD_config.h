/*
 * Config.h
 * CLCD driver for the microcontroller ATMega 32
 * Created on: May 8, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_DATA_PORT			Group_C

#define CLCD_CONTROL_PORT		Group_B
#define CLCD_RS_PIN				DIO_u8_Pin_0
#define CLCD_RW_PIN				DIO_u8_Pin_1
#define CLCD_E_PIN     			DIO_u8_Pin_2

#endif /* CLCD_CONFIG_H_ */
