/*
 * ADC_int.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_ADC_V1_ADC_INT_H_
#define MCAL_ADC_V1_ADC_INT_H_

#define ENABLE_BIT   0b1
#define DISABLE_BIT  0b0
#define LEFT_ADJ     0b1
#define RIGTH_ADJ    0b0

/*
 * Voltage Reference : the MAX analog voltage taken by ADC
 */
#define AREF_MODE      0b00  //AREF, Internal Vref turned off
#define AVCC_MODE      0b01  //AVCC with external capacitor at AREF pin
#define INTERNAL_MODE  0b11  //Internal 2.56V
							//Voltage Reference with external capacitor at AREF pin
/*
 * Prescaler select bits
 */
typedef enum {
	ADC_PRESCALER_2_0 ,
	ADC_PRESCALER_2_1 ,
	ADC_PRESCALER_4   ,
	ADC_PRESCALER_8   ,
	ADC_PRESCALER_16  ,
	ADC_PRESCALER_32  ,
	ADC_PRESCALER_64  ,
	ADC_PRESCALER_128
}ADC_PRESCALER;


typedef enum {
	 ADC0_PIN ,  // PORTA PIN0
	 ADC1_PIN ,  // PORTA PIN1
	 ADC2_PIN ,  // PORTA PIN2
	 ADC3_PIN ,  // PORTA PIN3
	 ADC4_PIN ,  // PORTA PIN4
	 ADC5_PIN ,  // PORTA PIN5
	 ADC6_PIN ,  // PORTA PIN6
	 ADC7_PIN    // PORTA PIN7
}ADC_PINS;



void ADC_vidInit (void);
u16 ADC_u16ReadChannel (ADC_PINS Copy_ADCPinsChannel);

#endif /* MCAL_ADC_V1_ADC_INT_H_ */
