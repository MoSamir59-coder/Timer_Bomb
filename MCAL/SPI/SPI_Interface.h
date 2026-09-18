/*
 * SPI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/*********************************************************************************/
/* Function: SPI_voidMasterInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Master Node					       	    **/
/*********************************************************************************/
void SPI_MasterSlaveInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Slave Node					       	    **/
/*********************************************************************************/
void SPI_voidSlaveInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns u8        	                        				    **/
/* Desc:This Function Transmit/recieve data							       	    **/
/*********************************************************************************/
/* Copy_u8Data Options:	Data assigned directly						       	    **/
/*********************************************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data);



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
