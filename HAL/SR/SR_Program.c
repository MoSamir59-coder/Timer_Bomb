/*
 * SR_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "SR_Config.h"
#include "SR_Interface.h"

void SR_init(SR_t SR)
{
    DIO_Set_Pin_Direction(SR.DATA_PORT, SR.DATA_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(SR.CLOCK_PORT, SR.CLOCK_PIN, DIO_PIN_OUTPUT);
    DIO_Set_Pin_Direction(SR.STROBE_PORT, SR.STROBE_PIN, DIO_PIN_OUTPUT);
}

void SR_send_byte(SR_t SR, u8 data)
{
    s8 counter;

    DIO_Set_Pin_Value(SR.STROBE_PORT, SR.STROBE_PIN, DIO_PIN_LOW);

    for(counter = 7; counter >= 0; counter--)
    {
        u8 Bit = GET_BIT(data, counter);
        DIO_Set_Pin_Value(SR.DATA_PORT, SR.DATA_PIN, Bit);

        DIO_Set_Pin_Value(SR.CLOCK_PORT, SR.CLOCK_PIN, DIO_PIN_HIGH);
        DIO_Set_Pin_Value(SR.CLOCK_PORT, SR.CLOCK_PIN, DIO_PIN_LOW);
    }

    DIO_Set_Pin_Value(SR.STROBE_PORT, SR.STROBE_PIN, DIO_PIN_HIGH);
    DIO_Set_Pin_Value(SR.STROBE_PORT, SR.STROBE_PIN, DIO_PIN_LOW);
}
