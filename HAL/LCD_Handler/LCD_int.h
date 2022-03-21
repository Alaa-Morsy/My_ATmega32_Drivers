/*
 * LCD_int.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Farid
 */

#ifndef HAL_LCD_HANDLER_LCD_INT_H_
#define HAL_LCD_HANDLER_LCD_INT_H_

/************ MACROS *********/
#define MAX_STRING     16
#define ERR_MESSAGE    6
#define ROW_1          127
#define ROW_2          191
#define NUM_TO_CHAR    48
#define NUM_POSITIVE    0
#define NUM_NEG         1


/*
 * Description :
 * 			Initialize the LCD according to LCD_MODE
 * 			whether 4 or 8 bits
 */
void LCD_vidInit(void);
/*
 * Description    :
 * 			Send the command to LCD_DATA_PORT
 * 			after configuration of RS , RW , E pins
 * Input Arguments :
 * 			Copy_u8cmd -> the command
 */
void LCD_vidSendCmd(u8 Copy_u8Cmd);
/*
 * Description :
 * 			Send the DATA to LCD_DATA_PORT
 * 			after configuration of RS , RW , E pins
 *
 * 	Input Arguments :
 * 			Copy_u8Data -> the Data to be shown on LCD
 */
void LCD_vidWriteChar(u8 Copy_u8Data);
/*
 * Description :
 * 			Send String to LCD
 * 			after configuration of RS , RW , E pins
 *
 * 	Input Arguments :
 * 			Copy_u8string -> the string to be shown on LCD
 * 			Copy_u8length -> the string length without '\0'
 */
void LCD_vidSendString ( u8 * Copy_u8string , u8 Copy_u8length);

/*
 * Description :
 * 			change the Cursor to the coordinators given
 * 			after configuration of RS , RW , E pins
 *
 * 	Input Arguments :
 * 			 Copy_u8row -> the LCD row ONE or TWO
 * 			 Copy_u8column -> the LCD column from 1 to 16
 */
void LCD_vidGoTo (u8 Copy_u8row , u8 Copy_u8column);

/*
 * Description :
 * 			shift the text left
 * 			after configuration of RS , RW , E pins
 */
void LCD_vidShiftLeft (void);

/*
 * Description :
 * 			shift the text Right
 * 			after configuration of RS , RW , E pins
 */
void LCD_vidShiftRight (void);

/*
 * Description :
 * 			converting a number to a string and display it on LCD
 * 			after configuration of RS , RW , E pins
 * Input Arguments :
 * 			Copy_u16int -> the number to be displayed
 * 			 Copy_u8sign -> the sign of the number
 * 			 				0 -> positive
 * 			 				1 -> negative display as -5
 */

void LCD_vidWriteInt  (u16 Copy_u16int );

void LCD_vidClrDisplay (void);

void LCD_vidReturnHome(void);

#endif /* HAL_LCD_HANDLER_LCD_INT_H_ */
