/*
 * EXTI_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCSR  *((volatile u8*)   	0x54) 	/*INT2*/
#define MCUCR   *((volatile u8*)   	0x55)	/* INT0,1 */
#define GICR    *((volatile u8*)   	0X5B)		/* PIE */
#define GIFR 	*((volatile u8*)	0x5A) 	 /* Flags */

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
