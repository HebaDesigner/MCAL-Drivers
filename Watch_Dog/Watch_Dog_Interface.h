/*
 * Watch_Dog_Interface.h
 * WatchDog driver for the microcontroller ATMega 32
 * Created on: Jun 16, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef WATCH_DOG_INTERFACE_H_
#define WATCH_DOG_INTERFACE_H_

#define  Watch_Dog_Clk                                              WD_clk_1024
/*Options:
 *               clk_16 (From prescaler)
 *               clk_32 (From prescaler)
 *               clk_64 (From prescaler)
 *               clk_128 (From prescaler)
 *               clk_256 (From prescaler)
 *               clk_512 (From prescaler)
 *               clk_1024 (From prescaler)
 *               clk_2048 (From prescaler)
 */
#define	WD_clk_16	        	                                    0b00000000		//clk_16 (From prescaler)
#define	WD_clk_32	        	                                    0b00000001		//clk_32 (From prescaler)
#define	WD_clk_64		                                            0b00000010		//clk_64 (From prescaler)
#define	WD_clk_128		                                            0b00000011		//clk_128 (From prescaler)
#define	WD_clk_256	    	                                        0b00000100		//clk_256 (From prescaler)
#define	WD_clk_512		                                            0b00000101		//clk_512 (From prescaler)
#define	WD_clk_1024		                                            0b00000110		//clk_1024 (From prescaler)
#define	WD_Clk_2048		                                            0b00000111		//clk_2048 (From prescaler)


void WDT_voidSleep(u8 Copy_u8SleepTime);
void WDT_voidEnable(void);
void WDT_voidDisable(void);


#endif /* WATCH_DOG_INTERFACE_H_ */
