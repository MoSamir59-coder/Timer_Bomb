/*
 * SRV_Program.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TMR/TMR_Interface.h"
#include "SRV_Interface.h"

void SRVO_init(void)
{
    /* »‰… OC1A ›Ì ATmega32 ÂÌ PD5° ·«“„  ﬂÊ‰ Output */
	DIO_Set_Pin_Direction(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
}

void SRVO_set_angle(u8 angle)
{
    /*
     * „⁄«œ·…  ÕÊÌ· «·“«ÊÌ… „‰ (0 ·‹ 180) ≈·Ï ﬁÌ„… OCR1A „‰ (1000 ·‹ 2000)
     * Value = 1000 + (Angle * 1000 / 180)
     */
    u16 Local_u16CompareValue = 1000 + ((u32)angle * 1000 / 180);

    /* «” Œœ«„ «·œ«·… «·Ã«Â“… „‰ œ—«Ì›— «· «Ì„— » «⁄ﬂ */
    Timer_voidSetPWM(Local_u16CompareValue);
}
