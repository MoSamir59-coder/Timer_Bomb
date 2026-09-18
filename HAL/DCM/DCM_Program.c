/*
 * DCM_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "DCM_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"


void motor_init (DCM_t moter)
{
	//if((moter.port >= DIO_PORTA) && (moter.port <= DIO_PORTD) && ( moter.pin >= DIO_PIN0) && ( moter.pin >= DIO_PIN7) )
	{
		DIO_Set_Pin_Direction(moter.port , moter.pin , DIO_PIN_OUTPUT);
		DIO_Set_Pin_Value(moter.port , moter.pin , DIO_PIN_LOW);
	}
}
void motor_on(DCM_t moter)
{

	//if((moter.port >= DIO_PORTA) && (moter.port <= DIO_PORTD) && ( moter.pin >= DIO_PIN0) && ( moter.pin >= DIO_PIN7) )
	{
		DIO_Set_Pin_Value(moter.port , moter.pin, DIO_PIN_HIGH);
	}
}
void motor_off(DCM_t moter)
{
	//if((moter.port >= DIO_PORTA) && (moter.port <= DIO_PORTD) && ( moter.pin >= DIO_PIN0) && ( moter.pin >= DIO_PIN7) )
	{
		DIO_Set_Pin_Value(moter.port , moter.pin , DIO_PIN_LOW);
	}
}
