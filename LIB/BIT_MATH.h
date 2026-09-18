/*
 * BIT_MATH.h


 *
 *  Created on: 20/8/2026
 *      Author: Mohamed__Samir
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define REGISTER_SIZE	8

#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)	reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)	reg|=(1<<bit)
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit


#endif /* LIB_BIT_MATH_H_ */
