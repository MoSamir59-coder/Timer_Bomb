/*
 * SR_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_SR_SR_INTERFACE_H_
#define HAL_SR_SR_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

typedef struct
{
	u8 DATA_PORT;
	u8 DATA_PIN;
	u8 CLOCK_PORT;
	u8 CLOCK_PIN;
	u8 STROBE_PORT;
	u8 STROBE_PIN;
}SR_t ;


void SR_init(SR_t SR);
void SR_send_byte(SR_t SR, u8 data);

#endif /* HAL_SR_SR_INTERFACE_H_ */
