/* ---------------------------------------------------------------------------------------------------
[FILE NAME]	  : <dio.h>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <DIO module header file for lcd>
--------------------------------------------------------------------------------------------------- */
#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
#include "macros.h"

#define INPUT 0
#define OUTPUT 1

#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/****************************************************************************************************************/
/* ---------------------------------------------------------------------------------------------------------------
[Structure Name]: DioConfig
[Structure Description]:
This structure is responsible for describing each individual PIN contains:
 *	1. the PORT Which the pin belongs to 'A 'B' 'C' or 'D'
 *	2. the number of the pin in the PORT
 *	3. the direction of pin --> INPUT or OUTPUT
 *	4. the value of the pin
--------------------------------------------------------------------------------------------------------------- */
typedef struct 
{
	uint8 port; 
	uint8 pinNum; 
	uint8 direction; 
	uint8 pinValue; 
}DioConfig;

/***************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_setDirection
[Description]   : This function is responsible for configure the PIN to input or output pin.
[Args]          : constant pointer to structure
[Returns]       : This return shall indicate void
--------------------------------------------------------------------------------------------------------------- */
void DIO_setDirection(const DioConfig * a_s_configMsg_Ptr );


 /****************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
 [Function Name] : DIO_writePin
 [Description]   : This function is responsible for write 1 or 0 on the pin .
 [Args]          : constant pointer to structure
 [Returns]       : This return shall indicate void
 --------------------------------------------------------------------------------------------------------------- */
 void DIO_writePin(const DioConfig * a_s_state_Ptr);
 

 /****************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_readPin
[Description]   : This function is responsible for read the pin.
[Args]          : constant pointer to structure
[Returns]       : This return shall indicate output from pin is low or high 
--------------------------------------------------------------------------------------------------------------- */
uint8 DIO_readPin(const DioConfig * a_s_state_Ptr);

 /****************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
 [Function Name] : DIO_writePort
 [Description]   : This function is responsible for read the port.
 [Args]          : constant unsigned integer and pointer to structure
 [Returns]       : This return shall indicate void
 --------------------------------------------------------------------------------------------------------------- */
void DIO_writePort(const uint8 a_port , uint8 * a_portValue);

 /****************************************************************************************************************/
 /* ---------------------------------------------------------------------------------------------------------------
 [Function Name] : DIO_readPort
 [Description]   : This function is responsible for read the port.
 [Args]          : unsigned integer a_port
 [Returns]       : This return shall indicate output 
 --------------------------------------------------------------------------------------------------------------- */
uint8 DIO_readPort(uint8 a_port);
#endif /* DIO_H_ */