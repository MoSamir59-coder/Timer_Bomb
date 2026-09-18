/*
 * DIO_Interface.h

 *
 *  Created on: 20/8/2026
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3


#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7

#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT  1
#define DIO_PIN_LOW     0
#define DIO_PIN_HIGH    1

#define DIO_PORT_INPUT  0x00
#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_LOW    0x00
#define DIO_PORT_HIGH   0xFF




//function declaration
void DIO_Set_Pin_Direction (u8 port , u8 pin , u8 direction);
void DIO_Set_Port_Direction (u8 port , u8 direction);
void DIO_Set_Port_Value(u8 port ,u8 value);
void DIO_Set_Pin_Value (u8 port , u8 pin , u8 value);
u8 DIO_Get_Pin_Value (u8 port , u8 pin);
u16 DIO_Get_Port_Value (u8 port);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
