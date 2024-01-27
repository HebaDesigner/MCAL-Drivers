/*
 * EXTI_Program.c
 * EXTI driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include"EXTI_Private.h"
#include"EXTI_Config.h"
#include"EXTI_Interface.h"

//Global pointer to function to hold INT0 ISR address
void (*EXTI_pvINT0Func)(void) = NULL;
void (*EXTI_pvINT1Func)(void) = NULL;
void (*EXTI_pvINT2Func)(void) = NULL;


void EXTI_voidINT0_Init(void)
{
	//check sense control
#if INT0_SENSE == Low_Level
	CLR_BIT(MCUCR,MCUCR_ISC00_INT0);
	CLR_BIT(MCUCR,MCUCR_ISC01_INT0);

#elif INT0_SENSE == On_Change
	SET_BIT(MCUCR,MCUCR_ISC00_INT0);
	CLR_BIT(MCUCR,MCUCR_ISC01_INT0);

#elif INT0_SENSE == Falling_Edge
	CLR_BIT(MCUCR,MCUCR_ISC00_INT0);
	SET_BIT(MCUCR,MCUCR_ISC01_INT0);

#elif INT0_SENSE == Rising_Edge
	SET_BIT(MCUCR,MCUCR_ISC00_INT0);
	SET_BIT(MCUCR,MCUCR_ISC01_INT0);

#else
#error "Wrong INT0_SENSE configuration option"
#endif

	//check Peripherals interrupt enable Initial state for INT0
#if INT0_INITIAL_STATE == Enabled_INT0
	//Peripherals interrupt enable for INT0
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == Disabled_INT0
	//Peripherals interrupt disabled for INT0
	CLR_BIT(GICR,GICR_INT0);

#else
#error "Wrong INT0_INITIAL_STATE configuration option"
#endif

}

void EXTI_voidINT1_Init(void)
{
	//check sense control
	#if INT1_SENSE == Low_Level
		CLR_BIT(MCUCR,MCUCR_ISC10_INT1);
		CLR_BIT(MCUCR,MCUCR_ISC11_INT1);

	#elif INT1_SENSE == On_Change
		SET_BIT(MCUCR,MCUCR_ISC10_INT1);
		CLR_BIT(MCUCR,MCUCR_ISC11_INT1);

	#elif INT1_SENSE == Falling_Edge
		CLR_BIT(MCUCR,MCUCR_ISC10_INT1);
		SET_BIT(MCUCR,MCUCR_ISC11_INT1);

	#elif INT1_SENSE == Rising_Edge
		SET_BIT(MCUCR,MCUCR_ISC10_INT1);
		SET_BIT(MCUCR,MCUCR_ISC11_INT1);

	#else
	#error "Wrong INT1_SENSE configuration option"
	#endif

		//check Peripherals interrupt enable Initial state for INT1
	#if INT1_INITIAL_STATE == Enabled_INT1
		//Peripherals interrupt enable for INT1
		SET_BIT(GICR,GICR_INT1);

	#elif INT1_INITIAL_STATE == Disabled_INT1
		//Peripherals interrupt disabled for INT1
		CLR_BIT(GICR,GICR_INT1);

	#else
	#error "Wrong INT1_INITIAL_STATE configuration option"
	#endif

}

void EXTI_voidINT2_Init(void)
{
	//check sense control
#if INT2_SENSE == Falling_Edge
		CLR_BIT(MCUCR,MCUCSR_INT2);

	#elif INT2_SENSE == Rising_Edge
		SET_BIT(MCUCR,MCUCSR_INT2);

	#else
	#error "Wrong INT2_SENSE configuration option"
	#endif

		//check Peripherals interrupt enable Initial state for INT1
	#if INT2_INITIAL_STATE == Enabled_INT2
		//Peripherals interrupt enable for INT2
		SET_BIT(GICR,GICR_INT2);

	#elif INT2_INITIAL_STATE == Disabled_INT2
		//Peripherals interrupt disabled for INT2
		CLR_BIT(GICR,GICR_INT2);

	#else
	#error "Wrong INT2_INITIAL_STATE configuration option"
	#endif

}

u8 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense_INT0)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense_INT0)
	{
	case Low_Level:	CLR_BIT(MCUCR,MCUCR_ISC00_INT0); CLR_BIT(MCUCR,MCUCR_ISC01_INT0); break;
	case On_Change: SET_BIT(MCUCR,MCUCR_ISC00_INT0); CLR_BIT(MCUCR,MCUCR_ISC01_INT0); break;
	case Falling_Edge: CLR_BIT(MCUCR,MCUCR_ISC00_INT0); SET_BIT(MCUCR,MCUCR_ISC01_INT0); break;
	case Rising_Edge: SET_BIT(MCUCR,MCUCR_ISC00_INT0); SET_BIT(MCUCR,MCUCR_ISC01_INT0); break;
	default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense_INT1)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense_INT1)
	{
	case Low_Level:	CLR_BIT(MCUCR,MCUCR_ISC10_INT1); CLR_BIT(MCUCR,MCUCR_ISC11_INT1); break;
	case On_Change: SET_BIT(MCUCR,MCUCR_ISC10_INT1); CLR_BIT(MCUCR,MCUCR_ISC11_INT1); break;
	case Falling_Edge: CLR_BIT(MCUCR,MCUCR_ISC10_INT1); SET_BIT(MCUCR,MCUCR_ISC11_INT1); break;
	case Rising_Edge: SET_BIT(MCUCR,MCUCR_ISC10_INT1); SET_BIT(MCUCR,MCUCR_ISC11_INT1); break;
	default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense_INT2)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense_INT2)
	{
	case Falling_Edge: CLR_BIT(MCUCR,MCUCSR_INT2); break;
	case Rising_Edge: SET_BIT(MCUCR,MCUCSR_INT2); break;
	default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INTEn_Dis(u8 Copy_u8INT, u8 Copy_u8En_Dis)
{
	switch(Copy_u8INT)
		{
		case INT0_INITIAL_STATE:
			ASSIGN_Bit(GICR, GICR_INT0, Copy_u8En_Dis);
			break;

		case INT1_INITIAL_STATE:
			ASSIGN_Bit(GICR, GICR_INT1, Copy_u8En_Dis);
			break;

		case INT2_INITIAL_STATE:
			ASSIGN_Bit(GICR, GICR_INT2, Copy_u8En_Dis);
			break;
		}
}

u8 EXTI_u8INT0SetCallback(void (*Copy_PvINT0Func)(void))
{
	u8 Local_u8ErrorStatus =OK;
	if (Copy_PvINT0Func != NULL)
	{
		EXTI_pvINT0Func = Copy_PvINT0Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_Pointer;
	}

	return Local_u8ErrorStatus;
}

u8 EXTI_u8INT1SetCallback(void (*Copy_PvINT1Func)(void))
{
	u8 Local_u8ErrorStatus =OK;
	if (Copy_PvINT1Func != NULL)
	{
		EXTI_pvINT1Func = Copy_PvINT1Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_Pointer;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_u8INT2SetCallback(void (*Copy_PvINT2Func)(void))
{
	u8 Local_u8ErrorStatus =OK;
	if (Copy_PvINT2Func != NULL)
	{
		EXTI_pvINT2Func = Copy_PvINT2Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_Pointer;
	}
	return Local_u8ErrorStatus;
}



void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvINT0Func != NULL)
	{
	EXTI_pvINT0Func();
	}
	else
	{
		// Do Nothing
	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvINT1Func != NULL)
	{
	EXTI_pvINT1Func();
	}
	else
	{
		// Do Nothing
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvINT2Func != NULL)
	{
	EXTI_pvINT2Func();
	}
	else
	{
		// Do Nothing
	}
}








/*
// GIE
void EXTI_voidGlobal_EN_Dis(u8 Copy_u8_En_Dis)
{
	switch(Copy_u8_En_Dis)
	{
	case EXTI_u8_Global_En:
		SET_BIT(SREG, EXTI_u8_Global_INT_Bit_7);
		break;

	case EXTI_u8_Global_Dis:
		CLR_BIT(SREG, EXTI_u8_Global_INT_Bit_7);
		break;
	}
}

//PIE
void EXTI_void_EN_Dis(u8 Copy_u8INT_Index, u8 Copy_u8En_Dis)
{
	switch(Copy_u8INT_Index)
	{
	case EXTI_u8_INT_0:
		ASSIGN_Bit(GICR, EXTI_u8_Global_INT_Bit_6, Copy_u8En_Dis);
		break;

	case EXTI_u8_INT_1:
		ASSIGN_Bit(GICR, EXTI_u8_Global_INT_Bit_7, Copy_u8En_Dis);
		break;

	case EXTI_u8_INT_2:
		ASSIGN_Bit(GICR, EXTI_u8_Global_INT_Bit_5, Copy_u8En_Dis);
		break;
	}

}

void EXTI_void_Set_Level(u8 Copy_u8INT_Index, u8 Copy_u8INT_Level)
{
	switch(Copy_u8INT_Index)
	{
	case EXTI_u8_INT_0:
		ASSIGN_Bit(MCUCR, EXTI_u8_INT_0_Set_LVL_Bit_0, GET_BIT(Copy_u8INT_Level,0));
		ASSIGN_Bit(MCUCR, EXTI_u8_INT_0_Set_LVL_Bit_1, GET_BIT(Copy_u8INT_Level,1));
		break;
	case EXTI_u8_INT_1:
		ASSIGN_Bit(MCUCR, EXTI_u8_INT_1_Set_LVL_Bit_0, GET_BIT(Copy_u8INT_Level,0));
		ASSIGN_Bit(MCUCR, EXTI_u8_INT_1_Set_LVL_Bit_1, GET_BIT(Copy_u8INT_Level,1));
		break;
	case EXTI_u8_INT_2:
		ASSIGN_Bit(MCUCR, EXTI_u8_INT_2_set_LVL_Bit_0, Copy_u8INT_Level);
		break;
	}
}

void __vector_1 (void)
{
	if(AvoidCallBack[0]!= NULL){
		AvoidCallBack[0]();
	}
}

void __vector_2 (void)
{
	if(AvoidCallBack[1]!= NULL){
		AvoidCallBack[1]();
	}
}

void __vector_3 (void)
{
	if(AvoidCallBack[2]!= NULL){
		AvoidCallBack[2]();
	}
}

void EXTI_voidSet_Callback(u8 Copy_u8INT_Index, void (*PvoidCallBack)(void))
{
	AvoidCallBack[Copy_u8INT_Index] = PvoidCallBack;
}*/


