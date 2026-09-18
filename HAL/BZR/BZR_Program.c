/*
 * BZR_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "BZR_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void buzzer_init(buzzer_t buzzer)
{
	DIO_Set_Pin_Direction(buzzer.port, buzzer.pin, DIO_PIN_OUTPUT);
	DIO_Set_Pin_Value(buzzer.port, buzzer.pin, DIO_PIN_LOW);
}


void buzzer_on(buzzer_t buzzer)
{
	DIO_Set_Pin_Value(buzzer.port, buzzer.pin, DIO_PIN_HIGH);
}


void buzzer_off(buzzer_t buzzer)
{
	DIO_Set_Pin_Value(buzzer.port, buzzer.pin, DIO_PIN_LOW);
}
