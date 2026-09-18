/*
 * EEPROM_Program.c
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "EEPROM_Private.h"
#include "EEPROM_Interface.h"

void EEPROM_voidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data)
{
    /* 1. «·«‰ Ÿ«— Õ Ï  ‰ ÂÌ √Ì ⁄„·Ì… ﬂ «»… ”«»ﬁ… (EEWE Ì’»Õ 0) */
    while (GET_BIT(EECR_REG, EEWE) == 1);

    /* 2. Ê÷⁄ «·⁄‰Ê«‰ ›Ì —ÌÃ” —«  «·⁄‰«ÊÌ‰ (High Ê Low) */
    EEARH_REG = (u8)(Copy_u16Address >> 8);
    EEARL_REG = (u8)Copy_u16Address;

    /* 3. Ê÷⁄ «·»Ì«‰«  ›Ì —ÌÃ” — «·»Ì«‰«  */
    EEDR_REG = Copy_u8Data;

    /* 4.  ›⁄Ì· Master Write Enable */
    SET_BIT(EECR_REG, EEMWE);

    /* 5.  ›⁄Ì· Write Enable ·»œ¡ «·ﬂ «»… (ÌÃ» √‰ Ì „ Œ·«· 4 Clock Cycles) */
    SET_BIT(EECR_REG, EEWE);
}

u8 EEPROM_u8ReadByte(u16 Copy_u16Address)
{
    /* 1. «·«‰ Ÿ«— Õ Ï  ‰ ÂÌ √Ì ⁄„·Ì… ﬂ «»… ”«»ﬁ… */
    while (GET_BIT(EECR_REG, EEWE) == 1);

    /* 2. Ê÷⁄ «·⁄‰Ê«‰ «·„ÿ·Ê» ﬁ—«¡ Â */
    EEARH_REG = (u8)(Copy_u16Address >> 8);
    EEARL_REG = (u8)Copy_u16Address;

    /* 3.  ›⁄Ì· Read Enable ·»œ¡ «·ﬁ—«¡… */
    SET_BIT(EECR_REG, EERE);

    /* 4. ≈—Ã«⁄ «·»Ì«‰«  „‰ —ÌÃ” — «·»Ì«‰«  */
    return EEDR_REG;
}
