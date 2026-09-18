/*
 * ADC_Config.h
 *
 *  Created on: ??˛/??˛/????
 *      Author: Mohamed__Samir
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*
 * Voltage Reference Options:
 * 1- AREF (External)
 * 2- AVCC (5V from MCU)
 * 3- Internal 2.56V
 * «Õ‰« Â‰” Œœ„ AVCC ·√‰ «·»Ê Ì‰‘„ — ÂÌ Ê’· ⁄·Ï «·‹ 5V
 */
#define ADC_VOLTAGE_REF     AVCC

/*
 * Prescaler:
 * «·‹ ADC „Õ «Ã ﬂ·Êﬂ „‰ 50kHz ·‹ 200kHz ⁄‘«‰ Ì‘ €· »œﬁ….
 * ·Ê «·ﬂ—Ì” «·… » «⁄ ﬂ 8MHz √Ê 16MHz° Â‰ﬁ”„ ⁄·Ï 128
 */
#define ADC_PRESCALER       128


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
