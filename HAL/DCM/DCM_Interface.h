/*
 * DCM_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_DCM_DCM_INTERFACE_H_
#define HAL_DCM_DCM_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

typedef struct
{
	u8 pin;
	u8 port;
}DCM_t;

void motor_init(DCM_t motor);
void motor_on(DCM_t motor);
void motor_off(DCM_t motor);

#endif /* HAL_DCM_DCM_INTERFACE_H_ */
