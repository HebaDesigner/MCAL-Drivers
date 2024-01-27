/*
 * Config.h
 * EXTI driver for the microcontroller ATMega 32
 * Created on: Jun 2, 2023
 * Author: Heba Atef Ahmed
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:
 * 1- Low_Level
 * 2- On_Change
 * 3- Falling_Edge
 * 4- Rising_Edge
 */
//set sense control for INT0 for falling Edge
#define INT0_SENSE             Falling_Edge

/*Options:
 * 1- Low_Level
 * 2- On_Change
 * 3- Falling_Edge
 * 4- Rising_Edge
 */
//set sense control for INT1 for falling Edge
#define INT1_SENSE             Falling_Edge

/*Options:
 * 1- Falling_Edge
 * 2- Rising_Edge
 */
//set sense control for INT2 for falling Edge
#define INT2_SENSE             Falling_Edge

/*Options:
 * 1- Enabled
 * 2- Disabled
 */
#define INT0_INITIAL_STATE    Enabled_INT0
#define INT1_INITIAL_STATE    Enabled_INT1
#define INT2_INITIAL_STATE    Enabled_INT2

#endif /* EXTI_CONFIG_H_ */
