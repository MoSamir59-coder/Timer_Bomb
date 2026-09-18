/*
 * BZR_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_BZR_BZR_INTERFACE_H_
#define HAL_BZR_BZR_INTERFACE_H_

#include "../../LIB/STD_Types.h"

typedef struct
{
    u8 port;
    u8 pin;
} buzzer_t;

void buzzer_init(buzzer_t buzzer);
void buzzer_on(buzzer_t buzzer);
void buzzer_off(buzzer_t buzzer);


#endif /* HAL_BZR_BZR_INTERFACE_H_ */
