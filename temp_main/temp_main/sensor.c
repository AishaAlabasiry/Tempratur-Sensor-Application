/* ---------------------------------------------------------------------------------------------------
[FILE NAME]	  : <sensor.c>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <this layer contains sensor functions >
--------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "sensor.h"

/*------------------------------------------ Global Variables --------------------------------------*/

/*------------------------------------- FUNCTION Definitions ---------------------------------------*/



void SENSOR_init()
{
	ADC_init(0, 3);	 /* AREF, Internal Vref turned off by clear REFS0 ,set division factor for ADC Prescaler Selections =8 */
}

uint32 SENSOR_read(uint8 a_chNum)
{
	uint32 temp;
	temp= ADC_read(a_chNum); /* Read channel zero where the temp sensor is connect */
	temp = (temp*150*5)/(1023*1.5);
	
	return temp;
		
}