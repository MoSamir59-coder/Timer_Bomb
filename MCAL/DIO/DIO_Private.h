/*
 * DIO_Private.h


 *
 *  Created on: 20/8/2026
 *      Author: Mohamed__Samir
 */



#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

// Group A
#define PORTA_Register  *((volatile u8*)0x3B) //output value
#define DDRA_Register   *((volatile u8*)0x3A) //direction
#define PINA_Register   *((volatile u8*)0x39) //input value

// Group B
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

// Group C
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)


// Group D
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
