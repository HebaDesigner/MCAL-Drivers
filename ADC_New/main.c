/*
 * main.c
 * ADC driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "CLCD_Interface.h"
#include "GIE_Interface.h"
#include "ADC_NInterface.h"

u8 App_u8ADCReading;

void ADCNotification(void)
{
	DIO_u8_SetPort_value(Group_D , App_u8ADCReading);
}

void main(void){

	//A0 --- i/p
	DIO_u8_SetPin_Dir(Group_A, DIO_u8_Pin_0, DIO_u8_Input);
	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_7, DIO_u8_Output);
	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_6, DIO_u8_Output);
	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_5, DIO_u8_Output);

	ADC_voidInit();
	CLCD_voidInit();

	// Enable global interrupt
	GIE_voidEnable();

	while(1)
	{
		ADC_u8StartConversionAsynch(Channel_A0, &App_u8ADCReading, &ADCNotification);
	}
}


