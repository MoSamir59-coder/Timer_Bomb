/*
 * SPI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"

void SPI_MasterSlaveInit(void)
{
#if SPI_MODE == SPI_MODE_MASTER
	/*Set The Node To Be Master Node*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);

#elif SPI_MODE == SPI_MODE_SLAVE
	/*Set The Node To Be Master Node*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);

#endif

	/* Set clock to presclaer 64 */
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPR0);
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPR1);

	/* Deactivate Double rate */
	CLR_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X);

	/* CPOL: Falling, rising - CPHA: setup,sample */
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPHA);
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPOL);

	/* Date Order - LSB */
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORD);

	/* SPI interrupt enable */
	//SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE);

	/* SPI Enable */
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE);

}


u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	/* Send data */
	SPI_u8_SPDR_REG = Copy_u8Data;

	/* Receive data - Wait until SPIF is set (shift complete) */
	while(GET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPIF) == 0);

	return SPI_u8_SPDR_REG;
}
