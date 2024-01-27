/*
 * main.c
 * WatchDog driver for the microcontroller ATMega 32
 * Created on: Jun 29, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"avr/delay.h"
#include"DIO_Interface.h"
#include "Watch_Dog_Interface.h"
#include "Watch_Dog_Register.h"


void main(void){

	DIO_u8_SetPort_Dir(Group_A,DIO_u8_PORT_Output);
	DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_0,DIO_u8_High);

	_delay_ms(1000);

	DIO_u8_SetPin_value(Group_A,DIO_u8_Pin_0,DIO_u8_Low);

	WDT_voidEnable();

	//Watch_Dog sleep after 1 Sec
	WDT_voidSleep(Watch_Dog_Clk);
	//_delay_ms(1000);

	WDT_voidDisable();
	while(1)
	{

	}
}

