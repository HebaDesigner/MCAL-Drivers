/*
 *  I2C_Driver
 *  I2C_Register.h
 *  Created on: Jun 20, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

#define TWCR                                  *((volatile u8*)0x56)                //TWI control register
#define TWCR_TWINT                            7                                    //Interrupt flag
#define TWCR_TWEA                             6                                    //Enable Acknowledge
#define TWCR_TWSTA                            5                                    //start condition
#define TWCR_TWSTO                            4                                    //Stop condition
#define TWCR_TWWC                             3                                    //Write collision
#define TWCR_TWEN                             2                                    //Enable
#define TWCR_TWIE                             0                                    //Interrupt Enable

#define TWDR                                  *((volatile u8*)0x23)                //TWI data register

#define TWAR                                  *((volatile u8*)0x22)                //TWI address register
#define TWAR_TEGCE                            0                                    //General call recognition enable

#define TWSR                                  *((volatile u16*)0x21)               //TWI status register
#define TWSR_TWPS0                            0                                    //Prescaler bit 0
#define TWSR_TWPS1                            1                                    //Prescaler bit 1

#define TWBR                                  *((volatile u8*)0x20)                //TWI bit rate register

#endif /* I2C_REGISTER_H_ */
