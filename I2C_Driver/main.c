/*
 *  I2C_Driver
 *  main.c
 *  Created on: Jun 20, 2023
 *  Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"I2c_Interface.h"
#include"CLCD_interface.h"
#include"avr/delay.h"


void main(void)
{
	u8 Local_u8Var;

	DIO_u8_SetPort_Dir(Group_B, DIO_u8_PORT_Output);

	TWI_voidMasterInit(0);

	EEPROM_SendDataByte(0, 0x55);                          //0x55 = 0b01010101

	_delay_ms(10);

	EEPROM_ReadDataByte(0, &Local_u8Var);

	DIO_u8_SetPort_value(Group_B, Local_u8Var);

	while(1)
	{

	}
}
