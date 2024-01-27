/*
 *  SPI_Driver_Master
 *  SPI_Program.c
 *  Created on: Jun 17, 2023
 *  Author: Heba Atef Ahmed
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_Interface.h"
#include"SPI_Private.h"
#include"SPI_Interface.h"


void SPI_voidInitMaster(void)
{
	//Master Mode
	SET_BIT(SPCR,SPCR_MSTR);

	//Clock Prescaller devide By 16
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	//SPI Enable
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	//Slave Mode
	CLR_BIT(SPCR,SPCR_MSTR);

	//SPI Enable
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	//Send the Data
	SPDR = Copy_u8Data;

	//Wait (busy waiting) until Transfer Complete
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);

	//Get The Exchanged Data
	return SPDR;
}





/*void SPI_Master_Init(void){
	SPCR = 0b01010001;     // SPI Interrupt Disable
	                      //SPI Enable
	                    // MSB First
	                   // Master Mode
	                  //CPole =0, CPHA=0
	                 //Prescaller dr/16

}
void SPI_Slave_Init(void)
{
	SPCR = 0b01000000;        // SPI Interrupt Disable
		                     //SPI Enable
		                    // MSB First
		                   // Slave Mode
		                  //CPole =0, CPHA=0
		                 //Prescaller don't care

}

u8 SPI_Transfer(u8 Data)
{
	SPDR = Data;
	while(GET_BIT(SPSR,7) == 0);   //Check For Transsmission Complete Flag
	return SPDR;
}*/



