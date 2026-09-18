/*
 * EEPROM_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_EEPROM_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data);
u8   EEPROM_u8ReadByte(u16 Copy_u16Address);

#endif /* MCAL_EEPROM_EEPROM_INTERFACE_H_ */
