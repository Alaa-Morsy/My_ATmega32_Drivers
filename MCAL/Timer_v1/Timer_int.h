/*
 * Timer_int.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_V1_TIMER_INT_H_
#define MCAL_TIMER_V1_TIMER_INT_H_

/*
 * Timer/Counter
 */
#define TIMER0_8BIT    0
#define TIMER1_16BIT   1
#define TIMER2_8BIT    2


/*
 * Clock Modes
 */
#define NORMAL_CLK_MODE         0b00
#define PWM_PHASE_CORRECT_MODE  0b01
#define CTC_CLK_MODE            0b10
#define PWM_FAST_MODE           0b11

/*
 * Compare Output Modes
 */
#define DISCONNECT_onCOMPARE   0b00
#define TOGGLE_onCOMPARE       0b01
#define CLEAR_onCOMPARE        0b10
#define SET_onCOMPARE          0b11

/*
 * CLOCK selection Modes
 */
#define STOP_CLK              0b000
#define SYS_CLK               0b001
#define PRESCALER_8_CLK       0b010
#define PRESCALER_64_CLK      0b011
#define PRESCALER_256_CLK     0b100
#define PRESCALER_1024_CLK    0b101
#define EXTERNAL_CLK_FALLING  0b110
#define EXTERNAL_CLK_RISING   0b111
/*
 * Prescaler
 */
typedef enum {
	TimerClkSlct_e_sysClk      = 1 ,
    TimerClkSlct_e_Pre_8       = 2 ,
	TimerClkSlct_e_Pre_64      = 3 ,
	TimerClkSlct_e_Pre_256     = 4 ,
	TimerClkSlct_e_Pre_1024    = 5 ,
	TimerClkSlct_e_Ext_falling = 6 ,
	TimerClkSlct_e_Ext_rising  = 7
}TimerClkSlct_e;

/*
 * Interrupt Types
 */
#define OVERFLOW_CLK_INT     0
#define OnCOMPARE_CLK_INT    1
/*
 * Enable Interrupts
 */
#define ENABLE_CLK_INT      1
#define DISABLE_CLK_INT     0

void TIMER_voidInit(u8 Copy_u8TimerSelect);  // initialize Timer 0 , 2 Mode from Configuration
void TIMER_vidClkSlct (u8 Copy_u8TimerSelect , TimerClkSlct_e Copy_TimerClkSlct_e_clkSource); //determine the timer operation clock
/*
 * Description: Timer Initialization
 * Input :
 *       Copy_u8TimerSelect ->  TIMER0_8BIT , TIMER2_8BIT
 *       Copy_u8TimerMode   -> NORMAL_CLK_MODE , PWM_PHASE_CORRECT_MODE, CTC_CLK_MODE
                               , PWM_FAST_MODE
 *       Copy_u8TimerOnCompare -> DISCONNECT_onCOMPARE  ,
                                  TOGGLE_onCOMPARE      ,
                                  CLEAR_onCOMPARE       ,
                                  SET_onCOMPARE
 * Output :
 *      RT_OK , RT_NOK
 */
u8 Timer_u8Init8bitTimer (u8 Copy_u8TimerSelect , u8 Copy_u8TimerMode , u8 Copy_u8TimerOnCompare);

/*
 * Description: Timer Interrupts Activation
 * Input :
 *       Copy_u8TimerSelect ->  TIMER0_8BIT  , TIMER2_8BIT
 *       Copy_u8InterruptMode -> OVERFLOW_CLK_INT , OnCOMPARE_CLK_INT
         Copy_u8EnableCLKInt ->  ENABLE_CLK_INT , DISABLE_CLK_INT
 */
void Timer_vidInterrupt8bitTimer (u8 Copy_u8TimerSelect ,u8 Copy_u8InterruptMode , u8 Copy_u8EnableCLKInt);
/*
 * Description: putting the Preload value
 * Input :
 *       Copy_u8TimerSelect ->  TIMER0_8BIT  , TIMER2_8BIT
 *       Copy_u8PreLoad     -> preload value .. to make the counter ticks from here
 */

void Timer_vidCounterPreLoad_8bit(u8 Copy_u8TimerSelect ,u8 Copy_u8PreLoad);

/*
 * Description: putting the compare value
 * Input :
 *       Copy_u8TimerSelect ->  TIMER0_8BIT  , TIMER2_8BIT
 *       Copy_u8OnCompareValue    -> On Compare value .. to check on that count
 */

void Timer_vidOnCompareValue(u8 Copy_u8TimerSelect ,u8 Copy_u8OnCompareValue);



#endif /* MCAL_TIMER_V1_TIMER_INT_H_ */
