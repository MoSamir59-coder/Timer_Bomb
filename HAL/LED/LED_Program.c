/*
 * LED_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#include "LED_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"



void led_init(led_t led)
{
	DIO_Set_Pin_Direction(led.port,led.pin, DIO_PIN_OUTPUT);

}

void leds_init(led_t led)
{
	DIO_Set_Port_Direction(led.port, DIO_PORT_OUTPUT);

}

void led_on(led_t led)
{
	DIO_Set_Pin_Value(led.port,led.pin, DIO_PIN_HIGH);
}

void led_off(led_t led)
{
	DIO_Set_Pin_Value(led.port,led.pin,DIO_PIN_LOW);
}

void leds_on(led_t led,u8 value)
{
	DIO_Set_Port_Value(led.port,value);
}

void leds_off(led_t led,u8 value)
{
	DIO_Set_Port_Value(led.port,value);
}

void led_toggle(led_t led)
{
    u8 pin_value = DIO_Get_Pin_Value(led.port, led.pin);
    if(pin_value == DIO_PIN_HIGH)
    {
    	DIO_Set_Pin_Value(led.port, led.pin, DIO_PIN_LOW);
    }
    else
    {
    	DIO_Set_Pin_Value(led.port, led.pin, DIO_PIN_HIGH);
    }
}
