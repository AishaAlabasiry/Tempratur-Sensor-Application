/* ---------------------------------------------------------------------------------------------------
[FILE NAME]	  : <app.c>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <Application layer for this project it is required to echo the temprature on the LCD>
--------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "app.h"
/*------------------------------------------ Global Variables --------------------------------------*/

/*------------------------------------- FUNCTION Definitions ---------------------------------------*/


void APP_init()
{
	/* Initialize LCD Driver */
	LCD_init();
	LCD_clear(); /*clear LCD at the beginning */
	LCD_sendString("Temp = ");
	LCD_goToRowColumn(0,10);
	LCD_sendData('C');
	SENSOR_init();
}

void APP_start()
{
	uint8 temp;
	while (1)
	{
		temp = SENSOR_read(0);
		LCD_goToRowColumn(0,7);
		LCD_intgerToString(temp); /*display the temp on LCD screen */
	}
		
}