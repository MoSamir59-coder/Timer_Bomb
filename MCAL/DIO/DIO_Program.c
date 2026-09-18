/*
 * DIO_Program.c


 *
 *  Created on: 20/8/2026
 *      Author: Mohamed__Samir
 */
#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_Set_Pin_Direction (u8 port , u8 pin , u8 direction)
{
	//Direction :
	//			output ->1
	//			input ->0
	if(direction == DIO_PIN_OUTPUT)
	{
		//set
		switch(port)
		{
			case DIO_PORTA : SET_BIT(DDRA_Register,pin);break;
			case DIO_PORTB : SET_BIT(DDRB_Register,pin);break;
			case DIO_PORTC : SET_BIT(DDRC_Register,pin);break;
			case DIO_PORTD : SET_BIT(DDRD_Register,pin);break;
		}
	}

	else if (direction == DIO_PIN_INPUT)
		{
				// Clear for DDRA, DDRB, DDRC, DDRD
			switch (port)
			{
				case DIO_PORTA: CLR_BIT(DDRA_Register, pin); break;
				case DIO_PORTB: CLR_BIT(DDRB_Register, pin); break;
				case DIO_PORTC: CLR_BIT(DDRC_Register, pin); break;
				case DIO_PORTD: CLR_BIT(DDRD_Register, pin); break;
			}
		}
		else
		{
			//Nothing
		}
}

void DIO_Set_Port_Direction (u8 port, u8 direction)
{
	//Direction :
	//			output ->1
	//			input ->0
	//set
	switch(port)
	{
		case DIO_PORTA : DDRA_Register = direction;break;
		case DIO_PORTB : DDRB_Register = direction;break;
		case DIO_PORTC : DDRC_Register = direction;break;
		case DIO_PORTD : DDRD_Register = direction;break;
	}
}

void DIO_Set_Port_Value (u8 port, u8 value)
{

	//set
	switch(port)
	{
		case DIO_PORTA : PORTA_Register = value;break;
		case DIO_PORTB : PORTB_Register = value;break;
		case DIO_PORTC : PORTC_Register = value;break;
		case DIO_PORTD : PORTD_Register = value;break;
	}
}


void DIO_Set_Pin_Value (u8 port , u8 pin , u8 value)
{
		//value :
		//			high ->1
		//			low ->0
	if(value == DIO_PIN_HIGH)
	{
		switch(port)
		{
			case DIO_PORTA : SET_BIT(PORTA_Register,pin);break;
			case DIO_PORTB : SET_BIT(PORTB_Register,pin);break;
			case DIO_PORTC : SET_BIT(PORTC_Register,pin);break;
			case DIO_PORTD : SET_BIT(PORTD_Register,pin);break;
		}
	}

	else if (value == DIO_PIN_LOW)
		{
			switch (port)
			{
				case DIO_PORTA: CLR_BIT(PORTA_Register, pin); break;
				case DIO_PORTB: CLR_BIT(PORTB_Register, pin); break;
				case DIO_PORTC: CLR_BIT(PORTC_Register, pin); break;
				case DIO_PORTD: CLR_BIT(PORTD_Register, pin); break;
			}
		}
	else
	{
		//Nothing
	}

}


u8 DIO_Get_Pin_Value(u8 port , u8 pin)
{
	u8 result = 0;

	switch (port)
	{
		case DIO_PORTA: result = GET_BIT(PINA_Register, pin); break;
		case DIO_PORTB: result = GET_BIT(PINB_Register, pin); break;
		case DIO_PORTC: result = GET_BIT(PINC_Register, pin); break;
		case DIO_PORTD: result = GET_BIT(PIND_Register, pin); break;
	}

	return result;
}

u16 DIO_Get_Port_Value(u8 port)
{
	u8 result = 1;

	switch (port)
	{
		case DIO_PORTA:
		{
			for(u8 i=0;i<=7;i++)
			{
				result = (result*2 + (GET_BIT(PINA_Register, i)));
			}
			break;
		}
		case DIO_PORTB:
		{
			for(u8 i=0;i<=7;i++)

			{
				result = (result*2 + (GET_BIT(PINB_Register, i)));
			}
			break;
		}
		case DIO_PORTC:
		{
			for(u8 i=0;i<=7;i++)
			{
				result = (result*2 + (GET_BIT(PINC_Register, i)));
			}
			break;
		}
		case DIO_PORTD:
		{
			for(u8 i=0;i<=7;i++)
			{
				result = (result*2 + (GET_BIT(PIND_Register, i)));
			}
			break;
		}
	}

	return (result - 256);
}

