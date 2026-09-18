/*
 * GI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_GI_GI_INTERFACE_H_
#define MCAL_GI_GI_INTERFACE_H_

#define SREG *((volatile u8*) 0x5F)

void GI_Enble(void);
void GI_Disable(void);

#endif /* MCAL_GI_GI_INTERFACE_H_ */
