/*
 * WDT_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

#define WDTCR		*((volatile u8*)0x41)

#define WDP0		0
#define WDP1		1
#define WDP2		2
#define WDE			3
#define WDTOE		4

void WDT_Init(void);
void WDT_Enable(void);
void WDT_Disable(void);




#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
