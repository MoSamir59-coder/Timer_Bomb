/*
 * EXTI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI_INDEX0		0
#define EXTI_INDEX1		1
#define EXTI_INDEX2		2



typedef enum
{
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
}EXTI_SenceControl_t;

void EXTI_Init(u8 exti_index, EXTI_SenceControl_t sense_control);

void EXTI_Enable(u8 exti_index);
void EXTI_Disable(u8 exti_index);

void EXTI_SetCallBack(u8 exti_index, void(*pf)(void));

u8 EXTI_GetFlag(u8 exti_index);
void EXTI_ClearFlag(u8 exti_index);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
