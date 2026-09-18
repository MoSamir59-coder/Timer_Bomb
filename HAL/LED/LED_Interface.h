/*
 * LED_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"




typedef struct
{
	u8 port;
	u8 pin;
} led_t;


void led_init(led_t led);

void leds_init(led_t led);

void led_on(led_t led);

void led_off(led_t led);

void led_toggle(led_t led);

void leds_on(led_t led,u8 value);

void leds_off(led_t led,u8 value);

#endif /* HAL_LED_LED_INTERFACE_H_ */
