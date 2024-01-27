/*
 *  SPI_Driver_Master
 *  SPI_Private.h
 *  Created on: Jun 17, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR                                                *((volatile u8*)0x2D)
#define SPCR_SPE                                            6                                    //SPI Enable
#define SPCR_MSTR                                           4                                   //Master/Slave Select
#define SPCR_SPR1                                           1                                  // Prescaler bit1
#define SPCR_SPR0                                           0                                 // Prescaler bit0

#define SPSR                                                *((volatile u8*)0x2E)
#define SPSR_SPIF                                           7                                // Interrupt Flag transfer is complete
#define SPSR_SPI2X                                          0                               //Prescaler bit 2
                                                                                           //Double SPI Speed Bit
                                                                                          //will be doubled when the SPI is in Master mode
                                                                                         //When SPI is Slave, the SPI is only guaranteed to work at fosc/4 or lower.

#define SPDR     *((volatile u8*)0x2F)                                                 //Data Register is a read/write


#endif /* SPI_PRIVATE_H_ */
