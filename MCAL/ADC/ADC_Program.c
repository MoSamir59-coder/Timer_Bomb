/*
 * ADC_Program.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"

void ADC_init(void)
{
    /* 1. «Œ Ì«— «·‹ Voltage Reference (AVCC) */
    SET_BIT(ADMUX_REG, ADMUX_REFS0);
    CLR_BIT(ADMUX_REG, ADMUX_REFS1);

    /* 2. «Œ Ì«— «·‹ Right Adjust (⁄‘«‰ ‰ﬁ—√ «·‹ 10 »  ﬂ«„·Ì‰ ﬂ‹ u16) */
    CLR_BIT(ADMUX_REG, ADMUX_ADLAR);

    /* 3. «Œ Ì«— «·‹ Prescaler (ﬁ”„… ⁄·Ï 128) */
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS2);
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS1);
    SET_BIT(ADCSRA_REG, ADCSRA_ADPS0);

    /* 4.  ›⁄Ì· «·‹ ADC */
    SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}

u16 ADC_Get_Digital_Value_Pulling(u8 ChannelNb)
{
    /* 1.  ’›Ì— √Ê· 5 »  ›Ì ADMUX (⁄‘«‰ ‰„”Õ √Ì ﬁ‰«… ﬂ«‰  „Œ «—… ﬁ»· ﬂœÂ) */
    ADMUX_REG &= 0b11100000;

    /* 2. Ê÷⁄ —ﬁ„ «·ﬁ‰«… «·ÃœÌœ… */
    ADMUX_REG |= (ChannelNb & 0b00011111);

    /* 3. »œ¡ «· ÕÊÌ· (Start Conversion) */
    SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

    /* 4. «·«‰ Ÿ«— Õ Ï Ì‰ ÂÌ «· ÕÊÌ· («·‹ Flag Ì»ﬁÏ 1) - Polling */
    while (GET_BIT(ADCSRA_REG, ADCSRA_ADIF) == 0);

    /* 5. „”Õ «·‹ Flag (»ﬂ «»… 1 ⁄·ÌÂ Õ”» «·œ« « ‘Ì ) */
    SET_BIT(ADCSRA_REG, ADCSRA_ADIF);

    /* 6. ≈—Ã«⁄ «·ﬁ—«¡… („‰ 0 ·‹ 1023) */
    return ADC_DATA_REG;
}
