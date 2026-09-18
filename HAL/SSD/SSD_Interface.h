/*
 * SSD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../SR/SR_Interface.h"


#define common_cathode 0
#define common_anode   1



static u8 numbers[10] = {0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111} ;


void ssd_init(SR_t SR);

void ssd_display(SR_t SR, u8 type, u8 value);




#endif /* HAL_SSD_SSD_INTERFACE_H_ */
