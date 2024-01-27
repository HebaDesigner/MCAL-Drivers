/*
 *  I2C_Driver
 *  I2C_Interface.h
 *  Created on: Jun 20, 2023
 *  Author: Heba Atef Ahmed
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterRReadByteErr,

}TWI_ErrStatus;

#define A2_Connect                                          G_Connect
/*Options
 *       Ground_Connect
 *       VCC_Connect
 */
#define G_Connect                                           0    //Ground_Connect
#define VCC_Connect                                         1   //VCC_Connect


//Pass 0 in the slave address argument if master will not be addressed
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStartCondition(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataType);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataType);

void TWI_SendStopCondition(void);

TWI_ErrStatus EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16Address);

TWI_ErrStatus EEPROM_ReadDataByte(u8 *Copy_u8DataByte, u16 Copy_u16Address);

/*void I2C_Master_Init(void);
u8 I2C_Start_Write(u8 slave_Address);
u8 I2C_Repeated_Start_Read(u8 slave_Address);
u8 I2C_Master_Transmit(u8 data);
u8 I2C_Master_Receive_Ack(void);
u8 I2C_Master_Receive_NAck(void);
void I2C_Stop(void);
void I2C_Slave_Init(u8 slave_Address);
u8 I2C_Slave_Listen(void);
u8 I2C_Slave_Transmit(u8 data);*/

#endif /* I2C_INTERFACE_H_ */
