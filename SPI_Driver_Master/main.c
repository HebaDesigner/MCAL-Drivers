/*
 *  SPI_Driver_Master
 *  main.c
 *  Created on: Jun 17, 2023
 *  Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"avr/delay.h"
#include"DIO_Interface.h"
#include"SPI_Interface.h"
#include"CLCD_interface.h"

//Master Program

void main(void)
{

	DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_7 ,DIO_u8_Output);      //SCK Master Output
	DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_6 ,DIO_u8_Input);      // MISO Master Input Slave Output
	DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_5 ,DIO_u8_Output);    // MOSI Master Output Slave Input

	DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_4 ,DIO_u8_Input);  // SS for Master Input pull up
	DIO_u8_SetPin_value(Group_B,DIO_u8_Pin_4,DIO_u8_High);

	CLCD_voidInit();
	SPI_voidInitMaster();

	while(1)
	{
		SPI_u8Transceive(1);
		_delay_ms(1000);
	}
}


/*void main(void)
{
	//DIO_u8_SetPort_Dir(Group_B, DIO_u8_PORT_Output);
		DIO_u8_SetPort_Dir(Group_D, DIO_u8_PORT_Output);

		DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_7 ,DIO_u8_Input);
		DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_6 ,DIO_u8_Output);
		DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_5 ,DIO_u8_Input);
		DIO_u8_SetPin_Dir(Group_B, DIO_u8_Pin_4 ,DIO_u8_Input);



		LCD_void_int_8Bit();

	//slave
	     //clc:I/P
	    //Miso:O/P
	   //Mosi:I/P
	   //SS:I/P
	//Master
		//clc:O/P-----B7
		//Miso:I/P----B6
		//Mosi:O/P----B5
		//SS:xxxx-----B4
	SPI_Slave_Init();
	u8 chr, state = 0;

	while(1)
	{
		chr = SPI_Transfer('S');
		if(chr == 'M'){
		DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_3,DIO_u8_High);
		_delay_ms(1000);
		}
		//DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_4,DIO_u8_High);}
		/*if(chr == 'A'){
		DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_5,TOG_BIT(state,0));
		_delay_ms(1000);

		}
		if(chr == 'F'){

		DIO_u8_SetPin_value(Group_D,DIO_u8_Pin_4,TOG_BIT(state,0));
		_delay_ms(1000);

		}

	}

	SPI_Master_Init();
		while(1)
		{
			u8 chr;
			chr = SPI_Transfer("M");
		LCD_Void_Write_String(chr,0,0);

		}

}*/


