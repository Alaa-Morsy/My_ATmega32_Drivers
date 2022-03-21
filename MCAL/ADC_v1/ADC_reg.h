/*
 * ADC_reg.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_ADC_V1_ADC_REG_H_
#define MCAL_ADC_V1_ADC_REG_H_



typedef struct {
	u8 MUX_4BITS  : 5 ;
	u8 ADLAR_BIT  : 1 ;
	u8 REFS_2BITS : 2 ;

}ADMUX_REG_TYPE;

typedef struct {
	u8 ADPS_3BITS :3 ;
	u8 ADIE_1BIT : 1;
	u8 ADIF_1BIT :1 ;
	u8 ADATE_1BIT :1 ;
	u8 ADSC_1BIT : 1;
	u8 ADEN_1BIT : 1;

}ADCSRA_REG_TYPE;

typedef struct{
	u8 REG_5BITS :5 ;
	u8 ADTS_3BITS :3;
}SFIOR_REG_TYPE;

#define ADCL_REG     *((volatile u8*)0x24)
#define ADCH_REG     *((volatile u8*)0x25)
#define ADC_REG      *((volatile u16*)0x24)
#define ADCSRA_REG    ((volatile ADCSRA_REG_TYPE* )0x26)
#define ADMUX_REG     ((volatile ADMUX_REG_TYPE* )0x27)
#define SFIOR_REG     ((volatile SFIOR_REG_TYPE* )0x50)

#endif /* MCAL_ADC_V1_ADC_REG_H_ */
