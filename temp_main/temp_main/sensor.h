/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : temp.h
[AUTHOR]      : Aisha Alabasiry
[DATE CREATED]: 20/1/2015
[DESCRIPTION] : header file for temprature sensor 
--------------------------------------------------------------------------------------------------- */


#ifndef SENSOR_H_
#define SENSOR_H_

#include "adc.h"

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SENSOR_init
[Description] 	: This function is responsible for initialization temprature sensor
[Args]		    : void
[Returns] 		: This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void SENSOR_init(void);

/***************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : SENSOR_read
[Description]   : This function is responsible for  read temprature on the sensor 
	              and the previous state is released 
[Args] 			: uint8 a_chNum
[Returns] 		: This return shall indicate uint32
--------------------------------------------------------------------------------------------------------------- */
uint32 SENSOR_read(uint8 a_chNum);


#endif /* SENSOR_H_ */