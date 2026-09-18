/*
 * STP_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_STP_STP_CONFIG_H_
#define HAL_STP_STP_CONFIG_H_

/*
 Options:-

 	 1-DIO_PORTA
 	 2-DIO_PORTB
 	 3-DIO_PORTC
 	 4-DIO_PORTD

 */

#define STEPPER_PORT  DIO_PORTB

/*
 Options:-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 */

#define STEPPER_BLUE_PIN     DIO_PIN0
#define STEPPER_PINK_PIN     DIO_PIN1
#define STEPPER_YELLOW_PIN   DIO_PIN2
#define STEPPER_ORANGE_PIN   DIO_PIN3

//====================================================================//
/*
 Options:-

 	 1-DIO_PORTA
 	 2-DIO_PORTB
 	 3-DIO_PORTC
 	 4-DIO_PORTD

 */

#define STEPPER_Proteus_PORT  DIO_PORTD
/*
 Options:-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 */
/*	C1,C2,C3,C4 ===> ULNA2003A stepper motor driver
 *	   					 __________
 * 		C1---left Top --| Stepper  |-- Right Top----C4
 * 						|  Motor   |
 * 		C3---left Bot --|          |-- Right Bot----C3
 * 						____________
 */

#define STEPPER_Proteus_Left_Top_PIN     DIO_PIN0
#define STEPPER_Proteus_Left_Bot_PIN     DIO_PIN1
#define STEPPER_Proteus_Right_Bot_PIN    DIO_PIN2
#define STEPPER_Proteus_Right_Top_PIN  	 DIO_PIN3


#endif /* HAL_STP_STP_CONFIG_H_ */
