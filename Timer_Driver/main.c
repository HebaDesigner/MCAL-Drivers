#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include"TIMER_Interface.h"

void LED(void)
{
	static u16 Local_u16Counter = 0;
	static u8 Local_u8LEDState = 0;
	Local_u16Counter++;

	if(Local_u16Counter == 4000)
	{
		TOG_BIT(Local_u8LEDState,0);
		DIO_u8_SetPin_value(Group_B, DIO_u8_Pin_3, Local_u8LEDState);
		Local_u16Counter = 0;
	}

}

void main(void)
{
	DIO_u8_SetPort_Dir(Group_B,DIO_u8_PORT_Output);
	TIM0_voidInitialize();
	TIMERS_u8SetCallBack(&LED, TIM0_Comp_INT);
	GIE_voidEnable();

	while(1)
	{

	}
}
