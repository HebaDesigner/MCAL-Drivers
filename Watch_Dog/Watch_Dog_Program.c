/*
 * Watch_Dog_Program.c
 * WatchDog driver for the microcontroller ATMega 32
 * Created on: Jun 16, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include "Watch_Dog_Interface.h"
#include "Watch_Dog_Register.h"


void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	/*Clear the Prescaler bits*/
	WDTCR &= 0b11111000;

	/*Set The required Prescaler*/
	WDTCR |= Copy_u8SleepTime;
}
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR, WDTCR_WDE);

}
void WDT_voidDisable(void)
{
	WDTCR |= 0b00011000;
	WDTCR = 0x00;
}
