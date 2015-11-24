/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : adc.h
[AUTHOR]      : Aisha Alabasiry
[DATE CREATED]: 20/1/2015
[DESCRIPTION] : Application layer header file for Temprature Sensor
--------------------------------------------------------------------------------------------------- */
#ifndef ADC_H_
#define ADC_H_

#include "configs.h"
#include "std_types.h"
#include "macros.h"

#define AVCC 0
#define AREF 1
#define internal 2

 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : ADC_init
[Description]   : This function is responsible for initialize ADC
[Args]          : Vref, Clock
[Returns]       : This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void ADC_init(uint8 a_vref,uint8 a_clock);

 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : ADC_read
[Description]   : This function is responsible for reading the data on specified channel 
[Args]          : uint8 channel_num
[Returns]       : This return shall indicate uint32
--------------------------------------------------------------------------------------------------------------- */
uint32 ADC_read(uint8 a_channelNum);

#endif /* ADC_H_ */