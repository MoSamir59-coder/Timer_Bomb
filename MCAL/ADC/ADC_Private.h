/*
 * ADC_Private.h
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/* ADC Registers */
#define ADMUX_REG           *((volatile u8*)0x27)
#define ADCSRA_REG          *((volatile u8*)0x26)
#define ADCH_REG            *((volatile u8*)0x25)
#define ADCL_REG            *((volatile u8*)0x24)
#define ADC_DATA_REG        *((volatile u16*)0x24) /* ·ﬁ—«¡… «·‹ 10 »  „—… Ê«Õœ… */

/* ADMUX Bits */
#define ADMUX_REFS1         7
#define ADMUX_REFS0         6
#define ADMUX_ADLAR         5

/* ADCSRA Bits */
#define ADCSRA_ADEN         7   /* ADC Enable */
#define ADCSRA_ADSC         6   /* Start Conversion */
#define ADCSRA_ADATE        5   /* Auto Trigger Enable */
#define ADCSRA_ADIF         4   /* Interrupt Flag */
#define ADCSRA_ADIE         3   /* Interrupt Enable */
#define ADCSRA_ADPS2        2   /* Prescaler Bit 2 */
#define ADCSRA_ADPS1        1   /* Prescaler Bit 1 */
#define ADCSRA_ADPS0        0   /* Prescaler Bit 0 */
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
