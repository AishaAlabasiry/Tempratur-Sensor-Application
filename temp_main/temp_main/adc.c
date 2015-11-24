/* ---------------------------------------------------------------------------------------------------
[FILE NAME]	  : < adc.c >
[AUTHOR]      : < Aisha Alabasiry >
[DATE CREATED]: < 20/1/2015 >
[DESCRIPTION] : < Application layer for Temprature Sensor>
--------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "adc.h"
#include "sensor.h"
/*------------------------------------------ Global Variables --------------------------------------*/

/*------------------------------------- FUNCTION Definitions ---------------------------------------*/

void ADC_init(uint8 a_vref,uint8 a_clock)
{
	/* Bits Description:
	 * ADEN=1 enable ADC
	 * ADPS2:0=011 to choose ADC_a_clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */ 
	SET_BIT(ADCSRA,ADEN); /* ADCSRA |= (1<<ADEN) */ 
	CLEAR_BIT(ADMUX,ADLAR); /* START WRITING FROM 0 IN ADLAR TO 2 IN ADHAR */
	switch(a_vref)
	{
		case 0 :
		CLEAR_BIT(ADMUX,6); /* AREF, Internal a_vref turned off , by clear REFS0*/
		CLEAR_BIT(ADMUX,7); /* and clear REFS1*/
		break;
		case 1 :
		SET_BIT(ADMUX,6); /* AVCC with external capacitor at AREF pin , by set REFS0*/
		CLEAR_BIT(ADMUX,7); /* and clear REFS1*/
		break;
		case 3 :
		SET_BIT(ADMUX,6); /*Internal 2.56V Voltage Reference with external capacitor at AREF pin, by set REFS0*/
		SET_BIT(ADMUX,7); /* and set REFS1*/
		break;
	}   
	
	switch(a_clock)
	{
		case 0 :
			CLEAR_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =2 */
			CLEAR_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS0);
			break;
		case 1 :
			CLEAR_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =2 */
			CLEAR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
			break;
		case 2 :
			CLEAR_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =4 */
			SET_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS0);
			break;
		case 3 :
			CLEAR_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =8 */
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
			break;
		case 4 :
			SET_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =16 */
			CLEAR_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS0);
			break;
		case 5 :
			SET_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =32 */
			SET_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS0);
			break;
		case 6 :
			SET_BIT(ADCSRA,ADPS2); /* set division factor for ADC Prescaler Selections =64 */
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
			break;
	}
}

uint32 ADC_read(uint8 a_channelNum)
{
	a_channelNum &=0x07; /* must be from 0 --> 7 */
	
	ADMUX &= 0xF8; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	
	ADMUX = ADMUX | a_channelNum; /*choose the correct channel by setting the channel number in MUX4:0 bits */
	
	ADCSRA |= (1<<ADSC); /* start conversion write '1' to ADSC */
	
	while(BIT_IS_CLEAR (ADCSRA ,ADIF)); /* wait for conversion to complete ADIF becomes '1'*/
	
	ADCSRA |=(1<<ADIF); /* clear ADIF by write'1' to it :) */
	
	return ADC; /* return the data register */
}