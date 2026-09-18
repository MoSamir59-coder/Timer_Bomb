/*
 * KPD_Program.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>


#include "KPD_Config.h"
#include "KPD_Private.h"
#include "KPD_Interface.h"

void KPD_voidInit(void)
{
    /*  ÂÌ∆… «·’›Ê› ﬂ‹ Output */
	DIO_Set_Pin_Direction(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_OUTPUT);
	DIO_Set_Pin_Direction(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_OUTPUT);
	DIO_Set_Pin_Direction(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_OUTPUT);
	DIO_Set_Pin_Direction(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_OUTPUT);

    /* Ê÷⁄ 5V „»œ∆Ì ⁄·Ï «·’›Ê› ⁄‘«‰ „Ì‘ €·Ê‘ ﬂ·Â„ „—… Ê«Õœ… */
	DIO_Set_Pin_Value(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_HIGH);
	DIO_Set_Pin_Value(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_HIGH);
	DIO_Set_Pin_Value(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_HIGH);
	DIO_Set_Pin_Value(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_HIGH);

    /*  ÂÌ∆… «·√⁄„œ… ﬂ‹ Input */
    DIO_Set_Pin_Direction(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_INPUT);
    DIO_Set_Pin_Direction(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_INPUT);
    DIO_Set_Pin_Direction(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_INPUT);
    DIO_Set_Pin_Direction(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_INPUT);

    /*  ›⁄Ì· «·‹ Pull-up Resistor «·œ«Œ·Ì ··√⁄„œ… */
    DIO_Set_Pin_Value(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_HIGH);
    DIO_Set_Pin_Value(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_HIGH);
    DIO_Set_Pin_Value(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_HIGH);
    DIO_Set_Pin_Value(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_HIGH);
}

u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
    u8 Local_u8RowCounter, Local_u8ColCounter, Local_u8PinState;

    static const u8 Local_u8KPDArr[4][4] = KPD_KEYS;
    static const u8 Local_u8RowPorts[4]  = {KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
    static const u8 Local_u8RowPins[4]   = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
    static const u8 Local_u8ColPorts[4]  = {KPD_COL0_PORT, KPD_COL1_PORT, KPD_COL2_PORT, KPD_COL3_PORT};
    static const u8 Local_u8ColPins[4]   = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};

    for (Local_u8RowCounter = 0; Local_u8RowCounter < 4; Local_u8RowCounter++)
    {
        /*  ›⁄Ì· «·’› «·Õ«·Ì (‰Õÿ ⁄·ÌÂ LOW) */
    	DIO_Set_Pin_Value(Local_u8RowPorts[Local_u8RowCounter], Local_u8RowPins[Local_u8RowCounter], DIO_PIN_LOW);

        /* ﬁ—«¡… «·√⁄„œ… */
        for (Local_u8ColCounter = 0; Local_u8ColCounter < 4; Local_u8ColCounter++)
        {
            Local_u8PinState = DIO_Get_Pin_Value(Local_u8ColPorts[Local_u8ColCounter], Local_u8ColPins[Local_u8ColCounter]);

            /* ·Ê «·“—«— «‰œ«” («·⁄„Êœ ÂÌﬁ—« LOW) */
            if (Local_u8PinState == DIO_PIN_LOW)
            {
                Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];

                /* Polling ·Õœ „« «·Œ»Ì— Ì‘Ì· ’»«⁄Â „‰ ⁄·Ï «·“—«— (⁄‘«‰ «·“—«— „Ì Õ”»‘ „— Ì‰) */
                while (Local_u8PinState == DIO_PIN_LOW)
                {
                    Local_u8PinState = DIO_Get_Pin_Value(Local_u8ColPorts[Local_u8ColCounter], Local_u8ColPins[Local_u8ColCounter]);
                }

                /* Debouncing »”Ìÿ ·Õ· „‘ﬂ·… «·—⁄‘… «·„Ìﬂ«‰ÌﬂÌ… ··“—«— */
                _delay_ms(20);
                return Local_u8PressedKey;
            }
        }

        /* ≈—Ã«⁄ «·’› ·Õ«· Â «·ÿ»Ì⁄Ì… (HIGH) ﬁ»· „« ‰‰ﬁ· ··’› «··Ì »⁄œÂ */
        DIO_Set_Pin_Value(Local_u8RowPorts[Local_u8RowCounter], Local_u8RowPins[Local_u8RowCounter], DIO_PIN_HIGH);
    }

    return Local_u8PressedKey;
}
