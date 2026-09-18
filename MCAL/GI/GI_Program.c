/*
 * GI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h""
#include "GI_Interface.h"

void GI_Enble(void)
{
	SET_BIT(SREG,7);
}

void GI_Disable(void)
{
	CLR_BIT(SREG,7);
}
