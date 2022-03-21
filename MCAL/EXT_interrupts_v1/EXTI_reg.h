/*
 * EXTI_reg.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_EXT_INTERRUPTS_V1_EXTI_REG_H_
#define MCAL_EXT_INTERRUPTS_V1_EXTI_REG_H_

typedef struct {

	u8 INT0_BITS : 2 ;
	u8 INT1_BITS : 2 ;
	u8 reserved  : 4 ;
}MCU_REG;


#define GICR_REG   *((volatile u8 *) 0x5B)
#define GIFR_REG   *((volatile u8 *) 0x5A)
#define MCUCR_REG  ((volatile MCU_REG *) 0x55)
#define MCUCSR_REG *((volatile u8 *) 0x54)

#endif /* MCAL_EXT_INTERRUPTS_V1_EXTI_REG_H_ */
