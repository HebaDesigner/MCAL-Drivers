#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"util/delay.h"
#include "DIO_Interface.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_u8_CTRL_PORT  Group_B
#define LCD_u8_DATA_PORT  Group_C


#define LCD_u8_RS_PIN  DIO_u8_Pin_0
#define LCD_u8_RW_PIN  DIO_u8_Pin_1
#define LCD_u8_Enable_PIN  DIO_u8_Pin_2


#define LCD_u8_DATA_PIN_0  DIO_u8_Pin_0
#define LCD_u8_DATA_PIN_1  DIO_u8_Pin_1
#define LCD_u8_DATA_PIN_2  DIO_u8_Pin_2
#define LCD_u8_DATA_PIN_3  DIO_u8_Pin_3
#define LCD_u8_DATA_PIN_4  DIO_u8_Pin_4
#define LCD_u8_DATA_PIN_5  DIO_u8_Pin_5
#define LCD_u8_DATA_PIN_6  DIO_u8_Pin_6
#define LCD_u8_DATA_PIN_7  DIO_u8_Pin_7



#endif /* LCD_CONFIG_H_ */
