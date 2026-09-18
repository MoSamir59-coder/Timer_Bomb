/*
 * EXTI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

void (*EXTI_pf[3])(void) = {0, 0, 0};


void EXTI_Init(u8 exti_index, EXTI_SenceControl_t sense_control)
{
	/* Validation */
	if ((exti_index == EXTI_INDEX0) || (exti_index == EXTI_INDEX1) || (exti_index == EXTI_INDEX2))
	{
		if(exti_index == EXTI_INDEX0)
		{
			switch(sense_control)
			{
				case EXTI_LOW_LEVEL: 			CLR_BIT(MCUCR,0); CLR_BIT(MCUCR,1);   break;
				case EXTI_ANY_LOGICAL_CHANGE: 	SET_BIT(MCUCR,0); CLR_BIT(MCUCR,1);   break;
				case EXTI_FALLING_EDGE: 		CLR_BIT(MCUCR,0); SET_BIT(MCUCR,1);   break;
				case EXTI_RISING_EDGE: 			SET_BIT(MCUCR,0); SET_BIT(MCUCR,1);   break;
				default: 						break;
			}
		}
		else if(exti_index == EXTI_INDEX1)
		{
			switch(sense_control)
			{
			case EXTI_LOW_LEVEL: 			CLR_BIT(MCUCR,2); CLR_BIT(MCUCR,3);   break;
			case EXTI_ANY_LOGICAL_CHANGE: 	SET_BIT(MCUCR,2); CLR_BIT(MCUCR,3);   break;
			case EXTI_FALLING_EDGE: 		CLR_BIT(MCUCR,2); SET_BIT(MCUCR,3);   break;
			case EXTI_RISING_EDGE: 			SET_BIT(MCUCR,2); SET_BIT(MCUCR,3);   break;
			default: 						break;
			}
		}
		else if(exti_index == EXTI_INDEX2)
		{
			switch(sense_control)
			{
			case EXTI_FALLING_EDGE: 		CLR_BIT(MCUCSR,6);   break;
			case EXTI_RISING_EDGE: 			SET_BIT(MCUCSR,6);   break;
			default: 						break;
			}
		}
	}
}


void EXTI_Enable(u8 exti_index)
{
	switch(exti_index)
	{
	case EXTI_INDEX0: SET_BIT(GICR,6); break;
	case EXTI_INDEX1: SET_BIT(GICR,7); break;
	case EXTI_INDEX2: SET_BIT(GICR,5); break;
	default: 		  break;
	}
}

void EXTI_Disable(u8 exti_index)
{
	switch(exti_index)
	{
	case EXTI_INDEX0: CLR_BIT(GICR,6); break;
	case EXTI_INDEX1: CLR_BIT(GICR,7); break;
	case EXTI_INDEX2: CLR_BIT(GICR,5); break;
	default: 		  break;
	}
}

/* for pulling */
u8 EXTI_GetFlag(u8 exti_index)
{
	u8 returnFlag;
	switch(exti_index)
	{
	case EXTI_INDEX0: returnFlag = GET_BIT(GIFR,6); break;
	case EXTI_INDEX1: returnFlag = GET_BIT(GIFR,7); break;
	case EXTI_INDEX2: returnFlag = GET_BIT(GIFR,5); break;
	default: 		  break;
	}
	return returnFlag;
}

void EXTI_ClearFlag(u8 exti_index)
{
	switch(exti_index)
	{
	case EXTI_INDEX0: CLR_BIT(GIFR,6); break;
	case EXTI_INDEX1: CLR_BIT(GIFR,7); break;
	case EXTI_INDEX2: CLR_BIT(GIFR,5); break;
	default: 		  break;
	}
}


void EXTI_SetCallBack(u8 exti_index, void (*pf)(void))
{
	if(0 != pf)
		EXTI_pf[exti_index] = pf;
}

/* ISR of EXTI0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI_pf[0]();
}

/* ISR of EXTI1 */
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	EXTI_pf[1]();
}

/* ISR of EXTI2 */
void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	EXTI_pf[2]();
}
