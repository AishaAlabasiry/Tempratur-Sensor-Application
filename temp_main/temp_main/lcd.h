/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : <lcd.h>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <Standard Types header file for lcd>
--------------------------------------------------------------------------------------------------- */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "macros.h"
#include "configs.h"
#include "dio.h"

#define RS 4
#define RW 5
#define E  6

#define RS_PORT 'D'
#define RW_PORT 'D'
#define E_PORT  'D'

#define LCD_DATA0_PIN 0
#define LCD_DATA1_PIN 1
#define LCD_DATA2_PIN 2
#define LCD_DATA3_PIN 3

#define LCD_DATA4_PIN 4
#define LCD_DATA5_PIN 5
#define LCD_DATA6_PIN 6
#define LCD_DATA7_PIN 7

#define LCD_DATA0_PORT 'C'
#define LCD_DATA1_PORT 'C'
#define LCD_DATA2_PORT 'C'
#define LCD_DATA3_PORT 'C'

#define LCD_DATA4_PORT 'C'
#define LCD_DATA5_PORT 'C'
#define LCD_DATA6_PORT 'C'
#define LCD_DATA7_PORT 'C'


#define CLEAR_COMMAND				0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define TWO_LINE_LCD_FOUR_BIT_MODE  0x02
#define TWO_LINE_LCD                0x28
#define CURSOR_OFF                  0x0C
#define CURSOR_ON					0x0E
#define SET_CURSOR_LOCATION			0x80

#define DATA_BITS_MODE   8 /* change data bits mode to be 4 or 8 */

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_configurtions
[Description] 	: This function is responsible for define configurations 
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
static void LCD_configurations(void);
/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_init
[Description] 	: This function is responsible for initialization lcd
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_init(void);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_sendCommand
[Description] 	: This function is responsible for sending command to lcd
[Args]		    : uint8 Command
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_sendCommand (uint8 Command);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_sendData
[Description] 	: This function is responsible for sending data to lcd
[Args]		    : uint8 Data
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_sendData (uint8 Data);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_sendString
[Description] 	: This function is responsible for echo string on lcd
[Args]		    : const char pointer to array
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_sendString(const char *str);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_goToRowColumn
[Description] 	: This function is responsible for cursor to be at the desired position
[Args]		    : unsigned integer 8 bit row, unsigned integer 8 bit  col
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_goToRowColumn(uint8 row, uint8 col);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_sendStringRowColumn
[Description] 	: This function is responsible for echo string at the defined position
[Args]		    : uint8 row,uint8 col,const char *Str
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_sendStringRowColumn(uint8 row,uint8 col,const char *Str);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_integerToString
[Description] 	: This function is responsible for echo ASQii for decimal input
[Args]		    : integer num
[Returns] 		: This return shall indicate nothing
--------------------------------------------------------------------------------------------------------------- */
void LCD_integerToString(uint8 num);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_clear
[Description] 	: This function is responsible for clear lcd screen
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void LCD_clear(void);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_displayData
[Description] 	: This function is responsible for display data on lcd
[Args]		    : uint8 Data
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
static void LCD_displayData(uint8 Data);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : LCD_displayCommand
[Description] 	: This function is responsible for display command on lcd 
[Args]		    : uint8 command
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
static void LCD_displayCommand(uint8 command);

#endif /* LCD_H_ */
