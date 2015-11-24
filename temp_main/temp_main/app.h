/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : app.h
[AUTHOR]      : Aisha Alabasiry
[DATE CREATED]: 20/1/2015
[DESCRIPTION] : Application layer header file for Temprature Sensor
--------------------------------------------------------------------------------------------------- */


#ifndef APP_H_
#define APP_H_

#include "lcd.h"
#include "sensor.h"

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : APP_init
[Description] 	: This function is responsible for initialization lcd and temprature sensor
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void APP_init(void);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : APP_start
[Description]   : This function is responsible for  read the temprature and send it to lcd 
	              and the previous state is released 
[Args] 			: void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void APP_start(void);


#endif /* APP_H_ */