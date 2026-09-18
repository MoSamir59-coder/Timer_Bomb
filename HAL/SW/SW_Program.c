/*
 * SW_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "SW_Private.h"
#include "SW_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void sw_init(sw_t sw)
{
	DIO_Set_Pin_Direction(sw.port,sw.pin,DIO_PIN_INPUT);
	if(sw.type == sw_pull_up)
	{
		DIO_Set_Pin_Value(sw.port,sw.pin,DIO_PIN_HIGH);
	}
	else if(sw.type == sw_pull_down)
	{
		DIO_Set_Pin_Value(sw.port,sw.pin,DIO_PIN_LOW);
	}
}

void sws_init(sw_t sw)
{
	DIO_Set_Port_Direction(sw.port,DIO_PIN_INPUT);
	if(sw.type == sw_pull_up)
	{
		DIO_Set_Port_Value(sw.port,DIO_PIN_HIGH);
	}
	else if(sw.type == sw_pull_down)
	{
		DIO_Set_Port_Value(sw.port,DIO_PIN_LOW);
	}
}

u8 sw_get_pressed(sw_t sw)
{
	return DIO_Get_Pin_Value(sw.port,sw.pin);
}

u16 sws_get_pressed(sw_t sw)
{
	return DIO_Get_Port_Value(sw.port);
}
