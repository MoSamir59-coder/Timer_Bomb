/*
 * LCD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


#include "../../MCAL/DIO/DIO_Interface.h"

void LCD_init(void);
void LCD_send_command(u8 Command);
void LCD_send_data(u8 Data);
void LCD_send_string(const char *String);
void LCD_go_to_XY(u8 X, u8 Y);
void LCD_send_number(u32 Number);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
