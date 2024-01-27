/*
 *  SPI_Driver_Slave
 *  SPI_Interface.h
 *  Created on: Jun 17, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
u8 SPI_u8Transceive(u8 Copy_u8Data);

/*void SPI_Master_Init(void);
void SPI_Slave_Init(void);
u8 SPI_Transfer(u8 Data);*/




#endif /* SPI_INTERFACE_H_ */
