/*
 * SW_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_SW_SW_INTERFACE_H_
#define HAL_SW_SW_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#define sw_pressed_up	0
#define sw_pressed_down	1

#define sw_notpressed_up 1
#define sw_notpressed_down 0

#define sw_pull_down	0
#define sw_pull_up		1

typedef struct
{
	u8 port;
	u8 pin;
	u8 type;
}sw_t;




void sw_init(sw_t sw);
void sws_init(sw_t sw);
u8 sw_get_pressed(sw_t sw);
u16 sws_get_pressed(sw_t sw);


#endif /* HAL_SW_SW_INTERFACE_H_ */
