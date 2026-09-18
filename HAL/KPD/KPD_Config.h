/*
 * KPD_Config.h
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#include"../../MCAL/DIO/DIO_Interface.h"

/*  ⁄—Ì› »‰«  «·’›Ê› (Rows) - Output */
#define KPD_ROW0_PORT   DIO_PORTA
#define KPD_ROW0_PIN    DIO_PIN4

#define KPD_ROW1_PORT   DIO_PORTA
#define KPD_ROW1_PIN    DIO_PIN5

#define KPD_ROW2_PORT   DIO_PORTA
#define KPD_ROW2_PIN    DIO_PIN6

#define KPD_ROW3_PORT   DIO_PORTA
#define KPD_ROW3_PIN    DIO_PIN7

/*  ⁄—Ì› »‰«  «·√⁄„œ… (Columns) - Input Pull-up */
#define KPD_COL0_PORT   DIO_PORTD
#define KPD_COL0_PIN    DIO_PIN4

#define KPD_COL1_PORT   DIO_PORTB
#define KPD_COL1_PIN    DIO_PIN6

#define KPD_COL2_PORT   DIO_PORTD
#define KPD_COL2_PIN    DIO_PIN6

#define KPD_COL3_PORT   DIO_PORTD
#define KPD_COL3_PIN    DIO_PIN7

/* Œ—Ìÿ… «·“—«Ì— (Matrix) */
#define KPD_KEYS        { {'7','8','9','/'}, \
                          {'4','5','6','*'}, \
                          {'1','2','3','-'}, \
                          {'C','0','=','+'} }

#endif /* HAL_KPD_KPD_CONFIG_H_ */
