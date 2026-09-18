/*
 * EEPROM_Priavte.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_EEPROM_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_EEPROM_PRIVATE_H_

/* EEPROM Registers Addresses */
#define EEARH_REG   *((volatile u8*)0x3F) /* Address Register High */
#define EEARL_REG   *((volatile u8*)0x3E) /* Address Register Low */
#define EEDR_REG    *((volatile u8*)0x3D) /* Data Register */
#define EECR_REG    *((volatile u8*)0x3C) /* Control Register */

/* EEPROM Control Register Bits */
#define EERE    0   /* Read Enable */
#define EEWE    1   /* Write Enable */
#define EEMWE   2   /* Master Write Enable */
#define EERIE   3   /* Interrupt Enable */

#endif /* MCAL_EEPROM_EEPROM_PRIVATE_H_ */
