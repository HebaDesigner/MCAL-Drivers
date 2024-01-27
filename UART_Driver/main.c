/*
 * main.c
 * UART driver for the microcontroller ATMega 32
 * Created on: Jun 16, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"UART_Private.h"
#include"UART_Interface.h"
#include"CLCD_interface.h"
#include"avr/delay.h"


void main(void)
{
	DIO_u8_SetPort_Dir(Group_B, DIO_u8_PORT_Output);
	DIO_u8_SetPort_Dir(Group_A, DIO_u8_PORT_Output);

	DIO_u8_SetPort_Dir(Group_C, DIO_u8_PORT_Output);

	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_0 ,DIO_u8_Input);
	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_1 ,DIO_u8_Output);
	USART_Init();

	CLCD_voidInit();

	while(1)
	{
		char Data = USART_voidReceive_char();

		if(Data == '1')
		{
			DIO_u8_SetPin_value(Group_B, DIO_u8_Pin_7, DIO_u8_High);
			CLCD_voidWriteString("Heba");
		}
		else if (Data == '2')
		{
			DIO_u8_SetPin_value(Group_B, DIO_u8_Pin_7, DIO_u8_Low);
			CLCD_voidWriteString(" bebooooooo");

		}
		//_delay_ms(1000);
	}
}
