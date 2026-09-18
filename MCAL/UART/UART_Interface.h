/*
 * UART_Interface.h

 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "UART_Private.h"
#include "UART_Config.h"


#define PARITY_ENABLE			1
#define PARITY_DISABLE			0

#define PARITY_EVEN			0
#define PARITY_ODD			1


#define SYNCHRONOUS			0
#define ASYNCHRONOUS		1

#define START_BIT			0

#define DATA5				0
#define DATA6				1
#define DATA7				2
#define DATA8				3
#define DATA9				4


#define STOP_BIT1			0
#define STOP_BIT2			1





void UART_init(void);

void UART_send_data(u8 data);

u8 UART_receive_data(void);

void UART_print_data(u8 print_data[]);

u8 UART_receive_data_unblock(u8 *pData);



#endif /* MCAL_UART_UART_INTERFACE_H_ */
