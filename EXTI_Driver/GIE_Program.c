/*
 * GIE_Program.c
 * GIE driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"GIE_Private.h"
#include"GIE_Interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}



