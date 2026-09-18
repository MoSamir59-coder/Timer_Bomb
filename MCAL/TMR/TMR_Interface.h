/*
 * TMR_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_TMR_TMR_INTERFACE_H_
#define MCAL_TMR_TMR_INTERFACE_H_

#define TIMER_OVF0_INT_INDEX              0
#define TIMER_CTC0_INT_INDEX              1

void Timer_voidInit(void);
void Timer_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex);
void Timer_voidSetPWM(u16 Copy_u16CompareValue);
void Timer_voidGetTimer1CounterValue(u16 * Copy_u16CounterValue);
void Timer_voidICUEnable(void);
void Timer_voidICUDiable(void);
u8   TImer_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod);
u8   TImer_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod);
u8   TImer_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle);


#endif /* MCAL_TMR_TMR_INTERFACE_H_ */
