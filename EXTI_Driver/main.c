/*
 * main.c
 * EXTI driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"avr/delay.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include"EXTI_Interface.h"

void INT0_ISR(void)
{
	static u8 flag =0;
	DIO_u8_SetPin_value(Group_C, DIO_u8_Pin_0, TOG_BIT(flag,0));
}
void INT1_ISR(void)
{
	static u8 flag =0;
	DIO_u8_SetPin_value(Group_C, DIO_u8_Pin_1, TOG_BIT(flag,0));
}
void INT2_ISR(void)
{
	static u8 flag =0;
	DIO_u8_SetPin_value(Group_C, DIO_u8_Pin_2, TOG_BIT(flag,0));
}


void main(void)
{
	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_2, DIO_u8_Input);
	DIO_u8_SetPin_value(Group_D, DIO_u8_Pin_2, DIO_u8_High);

	DIO_u8_SetPort_Dir(Group_C, DIO_u8_Output);

	EXTI_voidINT0_Init();

	EXTI_u8INT0SetCallback(&INT0_ISR);
	EXTI_u8INT1SetCallback(&INT1_ISR);
	EXTI_u8INT2SetCallback(&INT2_ISR);

	GIE_voidEnable();

	while(1)
	{

	}
}


/*void Blinked (void)
{
	static u8 flag =0;
	DIO_u8_SetPin_value(Group_C, DIO_u8_Pin_0, TOG_BIT(flag,0));
}


void main(void){
	DIO_u8_SetPort_Dir(Group_C, DIO_u8_Output);


	DIO_u8_SetPin_Dir(Group_D, DIO_u8_Pin_2, DIO_u8_Input);
	DIO_u8_SetPin_value(Group_D, DIO_u8_Pin_2, DIO_u8_High);

	EXTI_voidSet_Callback(EXTI_u8_INT_0_Set_LVL_Bit_0, Blinked);

	EXTI_void_Set_Level(EXTI_u8_INT_0,  Falling_Edge_INT_0);
	EXTI_void_EN_Dis(EXTI_u8_INT_0, EXTI_Enable);
	EXTI_voidGlobal_EN_Dis(EXTI_Enable);
	while(1){

	}
}*/

