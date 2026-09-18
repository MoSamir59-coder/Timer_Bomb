/*
 * SSD_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "SSD_Interface.h"
#include "../SR/SR_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void ssd_init(SR_t SR)
{
	SR_init(SR);
}

void ssd_display(SR_t SR, u8 type, u8 value)
{
	if(type == common_cathode)
	{
		SR_send_byte(SR, numbers[value]);
	}

	else if (type == common_anode)
	{
		SR_send_byte(SR, ~(numbers[value]));
	}
}
