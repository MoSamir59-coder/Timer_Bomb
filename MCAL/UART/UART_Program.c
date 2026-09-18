/*
 * UART_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */



/***************************************************************************************/
/***************************************************/
/*              Header files Inclusions            */
/***************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"




void UART_init(void)
{
	UBRRL  = (u8)MyUBRR;
	UBRRH  = (u8)(MyUBRR>>8);

	/* UCSRA Configuration */
	CLR_BIT(UCSRA, U2X);

	/* UCSRB Configuration */
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	CLR_BIT(UCSRB, UCSZ2);

	/* UCSRC Configuration */
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) | (0<<USBS) | (0<<UPM0) | (0<<UPM1);
}

void UART_send_data(u8 Datau8)
{
	/* UDR TX is not empty */
	while(GET_BIT(UCSRA,UDRE) == 0);

	UDR = Datau8;
}

u8 UART_receive_data(void)
{
	/* Unread data */
	while(GET_BIT(UCSRA, RXC) == 0 );

	return UDR;
}

void UART_print_data(u8 PrintData[])
{
	u8 i = 0;
	while(PrintData[i] != '\0')
	{
		UART_send_data(PrintData[i]);
		i++;
	}
}

u8 UART_receive_data_unblock(u8 *pData)
{
    u8 Local_u8Status = 0;

    /* ÝÍÕ åá Êã ÇÓÊÞÈÇá ÏÇÊÇ ÌÏíÏÉ ÈÏæä ÊæÞÝ (No Blocking) */
    if (GET_BIT(UCSRA, RXC) == 1)
    {
        *pData = UDR;
        Local_u8Status = 1; /* Êã ÇáÇÓÊÞÈÇá ÈäÌÇÍ */
    }

    return Local_u8Status;
}


//====================================================================================================

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
extern void UART_TransmitDataFrames(u8 UART_Frames[])
{
	}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
// interrupt for Rx Complete//
void __vector_13 (void)
{
	// Check the bit(7) (RxCn) is a flag to figure that if the receive operation is completed or not //
	UART_u8ReceivedFlag=1;
}
//==================================================================================================
// interrupt for Tx Complete//
void __vector_15 (void)
{
	// Check the bit(7) (RxCn) is a flag to figure that if the receive operation is completed or not //
	UART_u8TransmitFlag=1;
}
//====================================================================================================
extern u8 UART_u8GetReceivedFlag(void)
{
	return UART_u8ReceivedFlag;
}
extern void UART_voidClrReceivedFlag(void)
{
	UART_u8ReceivedFlag=0;
}
//======================================================================================================
extern u8 UART_u8GetTransmitFlag(void)
{
	return UART_u8TransmitFlag;
}
extern void UART_voidClrTransmitFlag(void)
{
	UART_u8TransmitFlag=0;
}
*/
