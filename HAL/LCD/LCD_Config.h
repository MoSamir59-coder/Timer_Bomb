/*
 * LCD_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"


/* Control Pins */
#define LCD_RS_PORT     DIO_PORTB
#define LCD_RS_PIN      DIO_PIN0

#define LCD_EN_PORT     DIO_PORTB
#define LCD_EN_PIN      DIO_PIN1

/* Data Pins (4-bit mode) */
#define LCD_D4_PORT     DIO_PORTB
#define LCD_D4_PIN      DIO_PIN2

#define LCD_D5_PORT     DIO_PORTB
#define LCD_D5_PIN      DIO_PIN3

#define LCD_D6_PORT     DIO_PORTB
#define LCD_D6_PIN      DIO_PIN4

#define LCD_D7_PORT     DIO_PORTB
#define LCD_D7_PIN      DIO_PIN5


#endif /* HAL_LCD_LCD_CONFIG_H_ */
