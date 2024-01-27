/*
 *  I2C_Driver
 *  I2C_Program.c
 *  Created on: Jun 20, 2023
 *  Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"I2c_Private.h"
#include"I2c_Interface.h"
#include"I2c_Register.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	//Set clock frequency to 400 kbps
	////Set TWBR to 2
	TWDR = 2;

	//Clear the 2 bits of TWPS
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	//Initialize the node address
	if(Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress << 1;
	}

	//Enable to TWI
	SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	//Initialize the node address
	TWAR = Copy_u8SlaveAddress << 1;

	//Enable to TWI
	SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//Send start condition on bus
	SET_BIT(TWCR, TWCR_TWSTA);

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//
	if((TWSR & 0XF8) != START_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = StartConditionErr;
	}
	else
	{
		//Do Nothing
	}

	return Local_ErrorState;
}

TWI_ErrStatus TWI_SendRepeatedStartCondition(void)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//Send start condition on bus
	SET_BIT(TWCR, TWCR_TWSTA);

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//Check the operation status in the status register
	if((TWSR & 0XF8) != REP_START_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = RepeatedStartErr;
	}
	else
	{
		//Do Nothing
	}
	return Local_ErrorState;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//Clear start condition bit
	CLR_BIT(TWCR, TWCR_TWSTA);

	//Set the slave address in the 7 MSB in the data register
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR, 0);                          //For write request

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//Check the operation status in the status register
	if((TWSR & 0XF8) != SLAVE_ADD_AND_WR_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
	}
	else
	{
		//Do Nothing
	}

	return Local_ErrorState;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//Clear start condition bit
	CLR_BIT(TWCR, TWCR_TWSTA);

	//Set the slave address in the 7 MSB in the data register
	TWDR = Copy_u8SlaveAddress << 1;
	SET_BIT(TWDR, 0);                          //For read request

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//Check the operation status in the status register
	if((TWSR & 0XF8) != SLAVE_ADD_AND_RD_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = SlaveAddressWithReadErr;
	}
	else
	{
		//Do Nothing
	}
	return Local_ErrorState;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//write the data Byte
	TWDR = Copy_u8DataByte;

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//Check the operation status in the status register
	if((TWSR & 0XF8) != MSTR_WR_BYTE_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = MasterWriteByteErr;
	}
	else
	{
		//Do Nothing
	}
	return Local_ErrorState;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	//Enable Master generation acknowledge bit after receiving the data
	SET_BIT(TWCR, TWCR_TWEA);

	//Clear the Interrupt Flag to start the slave sending data
	SET_BIT(TWCR, TWCR_TWINT);

	//Wait until the Interrupt Flag is raised again and the previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	//Check the operation status in the status register
	if((TWSR & 0XF8) != MSTR_RD_BYTE_WITH_ACK)           //0XF8 = 0b11111000 to masking with it
	{
		Local_ErrorState = MasterRReadByteErr;
	}
	else
	{
		//Read the received data
		*Copy_pu8DataByte = TWDR;
	}
	return Local_ErrorState;
}

void TWI_SendStopCondition(void)
{
	//Generate stop condition on the bus
	SET_BIT(TWCR, TWCR_TWSTO);

	//Clear the Interrupt Flag to start the previous operation
	SET_BIT(TWCR, TWCR_TWINT);
}

TWI_ErrStatus EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16Address)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(0b1010 | A2_Connect<<2 |Copy_u16Address>>8);

	TWI_MasterWriteDataByte((u8) Copy_u16Address);

	TWI_MasterWriteDataByte(Copy_u8DataByte);

	TWI_SendStopCondition();

	return Local_ErrorState;
}

TWI_ErrStatus EEPROM_ReadDataByte(u8 *Copy_u8DataByte, u16 Copy_u16Address)
{
	TWI_ErrStatus Local_ErrorState = NoError;

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(0b1010 | A2_Connect<<2 |Copy_u16Address>>8);

	TWI_MasterWriteDataByte((u8) Copy_u16Address);

	TWI_SendRepeatedStartCondition();

	TWI_SendSlaveAddressWithRead(0b1010 | A2_Connect<<2 |Copy_u16Address>>8);

	TWI_MasterReadDataByte(Copy_u8DataByte);

	TWI_SendStopCondition();

	return Local_ErrorState;
}
