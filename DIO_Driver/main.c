/*
 * main.c
 * DIO driver for the microcontroller ATMega 32
 * Created on: May 6, 2023
 * Author: Heba Atef Ahmed
 */

#include"avr/delay.h"
#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"


void main(void){

	u8 Local_Pu8_u8_Pin_Val = 1;

	// set pin 2 as input for switch
	DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_2, DIO_u8_Input);

	//Activate pullup for pin 2
	DIO_u8_SetPin_value(Group_B, DIO_u8_Pin_2, DIO_u8_High);

	// Set pin 1 as output for led
	DIO_u8_SetPin_Dir(Group_A, DIO_u8_Pin_2, DIO_u8_Output);
	while(1)
	{
		DIO_u8_GetPin_value(Group_B, DIO_u8_Pin_2, &Local_Pu8_u8_Pin_Val);
		if(Local_Pu8_u8_Pin_Val == 0)
		{
			DIO_u8_SetPin_value(Group_A, DIO_u8_Pin_2, DIO_u8_High);

		}else
			DIO_u8_SetPin_value(Group_A, DIO_u8_Pin_2, DIO_u8_Low);

	}
}




