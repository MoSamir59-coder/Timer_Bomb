/*
 * KPD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "../../LIB/STD_Types.h"

#define KPD_NO_PRESSED_KEY  0xFF

void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);


///*************************************************************
/*void Anim_BinaryCounter();
void Anim_Snake();
void Anim_Outward();
void Anim_Inward();
void Anim_Alternate();
void Anim_PingPong();
void Anim_ShiftRight();
void Anim_ShiftLeft();
void Anim_AllBlink();
u8 KPD_GetPressed3(void);*/

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
