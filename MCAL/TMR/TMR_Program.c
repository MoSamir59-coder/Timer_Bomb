/*
 * TMR_Program.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "TMR_Config.h"
#include "TMR_Interface.h"
#include "TMR_Private.h"

static u16 Timer_u16OnPeriod=0,Timeru16OffPeriod=0;
static void(*Timer_pfNotification[2])(void);

void Timer_voidInit(void)
{
#if (TIMER0_INIT_STATE == TIMER_u8_INIT_STATE_DISABLE)

	CLR_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);
#elif(TIMER0_INIT_STATE == TIMER_u8_INIT_STATE_ENABLE)
     	//Check if OVF INT is enabled
	#if (TIMER0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_TOIE0);
	#elif(TIMER0_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_TOIE0);
	#endif
			//Check if CTC INT is enabled
	#if (TIMER0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_OCIE0);
	#elif(TIMER0_CTC_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_OCIE0);
	#endif
     	//Choose The Mode of the timer and the prescaler
     #if (TIMER0_MODE == TIMER0_FAST_PWM)
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	//Set Fast Pwm Mode
     	SET_BIT(TCCR0,TCCR0_WGM00);
     	SET_BIT(TCCR0,TCCR0_WGM01);
     #elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	//Set Phase Correct Pwm mode
     	SET_BIT(TCCR0,TCCR0_WGM00);
     	CLR_BIT(TCCR0,TCCR0_WGM01);
     #elif TIMER0_INIT_STATE == TIMER0_NORMAL_MODE
     	TCNT0 = TIMER0_u8_PRELOAD_VALUE;
    	//Set Phase Correct Normal mode
     	CLR_BIT(TCCR0,TCCR0_WGM00);
     	CLR_BIT(TCCR0,TCCR0_WGM01);
	 #elif TIMER0_INIT_STATE == TIMER0_CTC_MODE
     	OCR0 = TIMER_u8_OCR0_INIT_VALUE;
     	//Set Phase Correct Pwm mode
     	SET_BIT(TCCR0,TCCR0_WGM01);
     	CLR_BIT(TCCR0,TCCR0_WGM00);
     #endif
     #if TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_CLEAR
     	SET_BIT(TCCR0,TCCR0_COM01);
     	CLR_BIT(TCCR0,TCCR0_COM00);
	 #elif TIMER_u8_OC0_PIN_MODE == TIMER_u8_OCX_SET
     	SET_BIT(TCCR0,TCCR0_COM01);
     	SET_BIT(TCCR0,TCCR0_COM00);
     #endif
     /* Select the Prescaler value to start the timer to count */
     	TCCR0 |= TIMER0_CLOCK_SOURCE;
#endif
#if TIMER1_INIT_STATE == TIMER_u8_INIT_STATE_DISABLE
    	CLR_BIT(TCCR1B,TCCR1B_CS10);
    	CLR_BIT(TCCR1B,TCCR1B_CS11);
    	CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_INIT_STATE == TIMER_u8_INIT_STATE_ENABLE
    	//Check OVF Int
	#if (TIMER1_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
    	SET_BIT(TIMSK,TIMSK_TOIE1);
	#elif (TIMER1_OVF_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
    	CLR_BIT(TIMSK,TIMSK_TOIE1);
	#endif
    	//Check CTC INT
	#if (TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_OCIE1A);
	#elif (TIMER1_CTC_CHANNEL_A_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_OCIE1A);
	#endif
	#if (TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT == TIMER_INTERRUPT_ENABLE)
		SET_BIT(TIMSK,TIMSK_OCIE1B);
	#elif (TIMER1_CTC_CHANNEL_B_INTERRUPT_INIT == TIMER_INTERRUPT_DISABLE)
		CLR_BIT(TIMSK,TIMSK_OCIE1B);
	#endif
    	//Choose The Timer 1 Mode
	#if TIMER1_MODE == TIMER1_FAST_PWM_ICR1_TOP
    	//Set Top Value In ICR1 Reg
    	ICR1 = TIMER1_u16_ICR1_VALUE;

    	SET_BIT(TCCR1B,TCCR1B_WGM13);
    	SET_BIT(TCCR1B,TCCR1B_WGM12);
    	SET_BIT(TCCR1A,TCCR1A_WGM11);
    	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	#elif TIMER1_MODE  == TIMER1_NORMAL_MODE

    	CLR_BIT(TCCR1B,TCCR1B_WGM13);
    	CLR_BIT(TCCR1B,TCCR1B_WGM12);
    	CLR_BIT(TCCR1A,TCCR1A_WGM11);
    	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	#endif
	#if TIMER_u8_OC1A_PIN_MODE == TIMER_u8_OCX_CLEAR
    	SET_BIT(TCCR1A,TCCR1A_COM1A1);
    	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	#endif
	#if TIMER_u8_OC1B_PIN_MODE == TIMER_u8_OCX_CLEAR
    	SET_BIT(TCCR1A,TCCR1A_COM1B1);
    	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	#endif

    /* Set the prescaler value as configured at the configuration file */
    	TCCR1B |= TIMER1_CLOCK_SOURCE;
#endif
}


void Timer_voidSetPWM(u16 Copy_u16CompareValue)
{
	OCR1A = Copy_u16CompareValue;
}

void Timer_voidSetCallBack(void(*Copy_pfNotification)(void),u8 Copy_u8TimerIntIndex)
{
	Timer_pfNotification[Copy_u8TimerIntIndex] = Copy_pfNotification;
}

void Timer_voidICUEnable(void)
{
#if (TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_RAISING_EDGE)
	SET_BIT(TCCR1B,TCCR1B_ICES1);
#elif(TIMER_u8_ICP_INIT_STATE == TIMER_u8_ICP_FALLING_EDGE)
	CLR_BIT(TCCR1B,TCCR1B_ICES1);
#endif
	/* Enable Interrupt of ICU */
	SET_BIT(TIMSK,5);
}
void Timer_voidICUDiable(void)
{
	CLR_BIT(TIMSK,5);
}
/*u8   TImer_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
	if(Copy_pu16OnPeriod != NULL)
	{
		*Copy_pu16OnPeriod = Timer_u16OnPeriod;
		Local_u8ReturnState  = STD_TYPES_u8_ERROR_OK;
	}
	return Local_u8ReturnState;
}
u8   TImer_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
	if(Copy_pu32TotalPeriod != NULL)
	{
		*Copy_pu32TotalPeriod = (u32)(Timer_u16OnPeriod + Timeru16OffPeriod);
		Local_u8ReturnState  = STD_TYPES_u8_ERROR_OK;
	}
	return Local_u8ReturnState;
}
u8   TImer_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle)
{
	u8 Local_u8ReturnState = STD_TYPES_u8_ERROR_NOK;
	if(Copy_pu8DutyCycle != NULL)
	{
		*Copy_pu8DutyCycle =(u8)(((u32)Timer_u16OnPeriod * 100) / (Timer_u16OnPeriod + Timeru16OffPeriod));
		Local_u8ReturnState  = STD_TYPES_u8_ERROR_OK;
	}
	return Local_u8ReturnState;
}*/
void Timer_voidGetTimer1CounterValue(u16 * Copy_u16CounterValue)
{
	*Copy_u16CounterValue = TCNT1;
}

/* ISR Function for Timer0 OVF */
void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	static u32 Local_u8Counter = 0;
	Local_u8Counter++;
	if(Local_u8Counter == TIMER0_u32_NUMBER_OF_OVF)
	{
		TCNT0           = TIMER0_u8_PRELOAD_VALUE;
		Local_u8Counter = 0;
		Timer_pfNotification[TIMER_OVF0_INT_INDEX]();
	}

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    static u8 Local_u8Counter = 0;
    Local_u8Counter++;

    /* 4 „—«  * 0.25 „··Ì À«‰Ì… = 1 „··Ì À«‰Ì… */
    if(Local_u8Counter == 4)
    {
        Local_u8Counter = 0;
        if(Timer_pfNotification[TIMER_CTC0_INT_INDEX] != NULL)
        {
            Timer_pfNotification[TIMER_CTC0_INT_INDEX]();
        }
    }
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
//	static u16 Local_u16CounterValue = 0;
	static u16 Local_u16Old_Value    = 0;
	static u8  Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		Timeru16OffPeriod = ICR1 - Local_u16Old_Value;
		//Change Edge of ICP into Falling Edge
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
		Local_u8Flag = 1;
	}
	else
	{
		Timer_u16OnPeriod = ICR1 - Local_u16Old_Value;
		//Change Edge of ICP into Raising Edge
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		Local_u8Flag = 0;
	}
	Local_u16Old_Value = ICR1;
}


