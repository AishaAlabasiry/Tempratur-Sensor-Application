/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : <dio.c>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <DIO Module for general use>
--------------------------------------------------------------------------------------------------- */
/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "dio.h"

/*------------------------------------------ Global Variables --------------------------------------*/

/*------------------------------------- FUNCTION Definitions ---------------------------------------*/

void DIO_setDirection(const DioConfig *a_s_configMsg_Ptr )
{
	volatile uint8 *DDR_Ptr;
	
	/* point to the required DDR Register */
	switch(a_s_configMsg_Ptr->port)
	{
		case 'A': DDR_Ptr = &DDRA;
		break;
		case 'B': DDR_Ptr = &DDRB;
		break;
		case 'C': DDR_Ptr = &DDRC;
		break;
		case 'D': DDR_Ptr = &DDRD;
		break;
	}
	if(a_s_configMsg_Ptr->direction == OUTPUT)
	{
		/* set the corresponding bit in the DDR register to configure it as output pin */
		SET_BIT(*DDR_Ptr,a_s_configMsg_Ptr->pinNum);
	}
	else if(a_s_configMsg_Ptr->direction ==INPUT )
	{
		/* clear the corresponding bit in the DDR register to configure it as input pin */
		CLEAR_BIT(*DDR_Ptr,a_s_configMsg_Ptr->pinNum);
	}
}

/*******************************************************************************************************************/
void DIO_writePin(const DioConfig * a_s_state_Ptr)
{
	/* point to the required PORT Register */
	volatile uint8 * port_Ptr;
	
	switch(a_s_state_Ptr->port)
	{
		case 'A': port_Ptr = &PORTA;
		break;
		case 'B': port_Ptr = &PORTB;
		break;
		case 'C': port_Ptr = &PORTC;
		break;
		case 'D': port_Ptr = &PORTD;
		break;
	}
	if(a_s_state_Ptr->pinValue == LOGIC_HIGH)
	{
		/*set the corresponding pin in the PORT register*/
		SET_BIT(*port_Ptr,a_s_state_Ptr->pinNum);
	}
	else if(a_s_state_Ptr->pinValue == LOGIC_LOW)
	{
		/*clear the corresponding pin in the PORT register*/
		CLEAR_BIT(*port_Ptr,a_s_state_Ptr->pinNum);
	}
}
/*******************************************************************************************************************/
uint8 DIO_readPin(const  DioConfig *a_s_state_Ptr)
{
	volatile uint8 * pin_ptr;
	uint8 output;
	
	/* point to the required PIN Register */
	switch(a_s_state_Ptr->port)
	{
		case 'A': pin_ptr = &PORTA;
		break;
		case 'B': pin_ptr = &PORTB;
		break;
		case 'C': pin_ptr = &PORTC;
		break;
		case 'D': pin_ptr = &PORTD;
		break;
	}
	if(BIT_IS_SET(*pin_ptr,a_s_state_Ptr->pinNum))
	{
		/*check if the corresponding bit is set in the PIN register*/
		output =  LOGIC_HIGH;
	}
	else if(BIT_IS_CLEAR(*pin_ptr,a_s_state_Ptr->pinNum))
	{
		/*check if the corresponding bit is clear in the PIN register*/
		output = LOGIC_LOW;
	}
	return output;
}
/********************************************************************************************************************/

void DIO_writePort(const uint8 a_port , uint8 * a_portValue)
{
	/* point to the required PORT Register */
	volatile uint8 * port_Ptr;
	
	switch(a_port)
	{
		case 'A': port_Ptr = &PORTA;
		break;
		case 'B': port_Ptr = &PORTB;
		break;
		case 'C': port_Ptr = &PORTC;
		break;
		case 'D': port_Ptr = &PORTD;
		break;
	}
	*port_Ptr = a_portValue ;
}
/*******************************************************************************************************************/
uint8 DIO_readPort( uint8 a_port)
{
	volatile uint8 * port_Ptr;
	uint8 output;
	
	/* point to the required PIN Register */
	switch(a_port)
	{
		case 'A': port_Ptr = &PORTA;
		break;
		case 'B': port_Ptr = &PORTB;
		break;
		case 'C': port_Ptr = &PORTC;
		break;
		case 'D': port_Ptr = &PORTD;
		break;
	}
	output = *port_Ptr ;
	return output;
}
/********************************************************************************************************************/