/*
 * WDT_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_Interface.h"
#include "WDT_Private.h"
#include "WDT_Config.h"

void WDT_Init(void)
{

    SET_BIT(WDTCR, WDP0);
    SET_BIT(WDTCR, WDP1);
    SET_BIT(WDTCR, WDP2);
}

void WDT_Enable(void)
{
    SET_BIT(WDTCR, WDE);
}

void WDT_Disable(void)
{

	WDTCR = (1<<WDTOE) | (1<<WDE);
    WDTCR = 0x00;
}
