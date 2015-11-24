/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : <lcd.c>
[AUTHOR]      : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <Standard Types header file for lcd>
--------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES -------------------------------------------*/
#include "lcd.h"

/*------------------------------------------ Global Variables --------------------------------------*/
static DioConfig g_s_lcdDataConfig[DATA_BITS_MODE];
static DioConfig g_s_lcdCommandConfig[3];

/*------------------------------------- FUNCTION Definitions ---------------------------------------*/


static void LCD_configurations(void)
{
	int count;
	for(count=0;count<3;count++) /* cotrol pins configuration */
	{
		g_s_lcdCommandConfig[count].direction = OUTPUT; /* set control pin directions to be output pins */
		g_s_lcdCommandConfig[count].pinValue  = LOGIC_LOW; /* initialize pins at first with zero */
	}
	g_s_lcdCommandConfig[0].pinNum  = RS;
	g_s_lcdCommandConfig[0].port    = RS_PORT;
	
	g_s_lcdCommandConfig[1].pinNum  = RW;
	g_s_lcdCommandConfig[1].port    = RW_PORT;
	
	g_s_lcdCommandConfig[2].pinNum  = E;
	g_s_lcdCommandConfig[2].port    = E_PORT;
	
	for(count=0;count<DATA_BITS_MODE;count++) /* data pins configurations */
	{
		g_s_lcdDataConfig[count].direction = OUTPUT; /* set data pin directions to be output pins */
		g_s_lcdDataConfig[count].pinValue  = LOGIC_LOW; /* initialize pins at first with zero */
		
	}
	#if (DATA_BITS_MODE==8) 
		g_s_lcdDataConfig[0].pinNum = LCD_DATA0_PIN;
		g_s_lcdDataConfig[1].pinNum = LCD_DATA1_PIN;
		g_s_lcdDataConfig[2].pinNum = LCD_DATA2_PIN;
		g_s_lcdDataConfig[3].pinNum = LCD_DATA3_PIN;
		g_s_lcdDataConfig[4].pinNum = LCD_DATA4_PIN;
		g_s_lcdDataConfig[5].pinNum = LCD_DATA5_PIN;
		g_s_lcdDataConfig[6].pinNum = LCD_DATA6_PIN;
		g_s_lcdDataConfig[7].pinNum = LCD_DATA7_PIN;
		g_s_lcdDataConfig[0].port = LCD_DATA0_PORT;
		g_s_lcdDataConfig[1].port = LCD_DATA1_PORT;
		g_s_lcdDataConfig[2].port = LCD_DATA2_PORT;
		g_s_lcdDataConfig[3].port = LCD_DATA3_PORT;
		g_s_lcdDataConfig[4].port = LCD_DATA4_PORT;
		g_s_lcdDataConfig[5].port = LCD_DATA5_PORT;
		g_s_lcdDataConfig[6].port = LCD_DATA6_PORT;
		g_s_lcdDataConfig[7].port = LCD_DATA7_PORT;
	#elif (DATA_BITS_MODE==4)
		g_s_lcdDataConfig[0].pinNum = LCD_DATA4_PIN;
		g_s_lcdDataConfig[1].pinNum = LCD_DATA5_PIN;
		g_s_lcdDataConfig[2].pinNum = LCD_DATA6_PIN;
		g_s_lcdDataConfig[3].pinNum = LCD_DATA7_PIN;
		g_s_lcdDataConfig[0].port = LCD_DATA4_PORT;
		g_s_lcdDataConfig[1].port = LCD_DATA5_PORT;
		g_s_lcdDataConfig[2].port = LCD_DATA6_PORT;
		g_s_lcdDataConfig[3].port = LCD_DATA7_PORT;
	#endif
}
void LCD_init(void) /* lcd intialization */
{
	int loop;
	LCD_configurations();
	for (loop=0;loop<3;loop++) /* set dirctoins for control pins */
	{
		DIO_setDirection(& g_s_lcdCommandConfig[loop]); 
	}
		
	for (loop=0;loop<DATA_BITS_MODE;loop++)
	{
		DIO_setDirection(& g_s_lcdDataConfig[loop]); /* set dirctoins for data pins */
	}
	
	#if (DATA_BITS_MODE == 8)
		LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); 
	#elif (DATA_BITS_MODE == 4)
		LCD_sendCommand(TWO_LINE_LCD_FOUR_BIT_MODE);
		LCD_sendCommand(TWO_LINE_LCD);
	#endif
	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND); /* clear */
}

void LCD_sendCommand (uint8 a_command) /*sending a_command to lcd */
{
	#if (DATA_BITS_MODE == 8)
	{
		LCD_displayCommand(a_command); 
	}
	#elif (DATA_BITS_MODE == 4)
	{
		LCD_displayCommand(a_command>>4); /* shift the data on the high nibble to the low nibble to echo it on lcd*/
		LCD_displayCommand(a_command); /* echo low nipple data on lcd */
	}
	#endif
}


void LCD_sendData (uint8 a_data) /*echo a_data to on lcd */
{
	#if (DATA_BITS_MODE == 8)
	{
		LCD_displayData(a_data);
	}
	#elif (DATA_BITS_MODE == 4)
	{
		LCD_displayData(a_data>>4);
		LCD_displayData(a_data);
	}
	#endif
}


static void LCD_displayCommand(uint8 a_command)
{
	int loop;
	 g_s_lcdCommandConfig[0].pinValue = LOGIC_LOW;
	 DIO_writePin(& g_s_lcdCommandConfig[0]);			/* CLEAR_BIT(LCD_CTRL_PORT,RS); Instruction Mode RS=0 */
	 g_s_lcdCommandConfig[1].pinValue = LOGIC_LOW;
	 DIO_writePin(& g_s_lcdCommandConfig[1]);			/* CLEAR_BIT(LCD_CTRL_PORT,RW); write data to LCD so RW=0 */
	 _delay_ms(1);										/* delay for processing Tas = 50ns */
	 g_s_lcdCommandConfig[2].pinValue = LOGIC_HIGH;
	 DIO_writePin(& g_s_lcdCommandConfig[2]);			/* SET_BIT(LCD_CTRL_PORT,E);Enable LCD E=1 */
	 _delay_ms(1);										/* delay for processing Tpw - Tdws = 190ns */
	 
	 for (loop=0;loop<DATA_BITS_MODE;loop++)
	 {
		 g_s_lcdDataConfig[loop].pinValue = (a_command>>loop) & 1;
		 DIO_writePin(& g_s_lcdDataConfig[loop]);
	 }
	 
	 _delay_ms(1);										/* delay for processing Tdsw = 100ns */
	 g_s_lcdCommandConfig[2].pinValue = LOGIC_LOW;
	 DIO_writePin(& g_s_lcdCommandConfig[2]);			/* CLEAR_BIT(LCD_CTRL_PORT,E); disable LCD E=0 */
	 _delay_ms(1);									    /* delay for processing Th = 13ns */
	
}

static void LCD_displayData(uint8 a_data)
{
	 int loop;
	 g_s_lcdCommandConfig[0].pinValue = LOGIC_HIGH;
	 DIO_writePin(& g_s_lcdCommandConfig[0]);			/* CLEAR_BIT(LCD_CTRL_PORT,RS); Instruction Mode RS=0 */
	 g_s_lcdCommandConfig[1].pinValue = LOGIC_LOW;
	 DIO_writePin(& g_s_lcdCommandConfig[1]);			/* CLEAR_BIT(LCD_CTRL_PORT,RW); write data to LCD so RW=0 */
	 _delay_ms(1);										/* delay for processing Tas = 50ns */
	 g_s_lcdCommandConfig[2].pinValue = LOGIC_HIGH;
	 DIO_writePin(& g_s_lcdCommandConfig[2]);			/* SET_BIT(LCD_CTRL_PORT,E);Enable LCD E=1 */
	 _delay_ms(1);										/* delay for processing Tpw - Tdws = 190ns */
	 
	 for (loop=0;loop<DATA_BITS_MODE;loop++)
	 {
		 g_s_lcdDataConfig[loop].pinValue = (a_data>>loop) & 1;
		 DIO_writePin(& g_s_lcdDataConfig[loop]);
	 }
	 
	 _delay_ms(1);										/* delay for processing Tdsw = 100ns */
	 g_s_lcdCommandConfig[2].pinValue = LOGIC_LOW;
	 DIO_writePin(& g_s_lcdCommandConfig[2]);			/* CLEAR_BIT(LCD_CTRL_PORT,E); disable LCD E=0 */
	 _delay_ms(1);
}

void LCD_sendString(const char *str)
{
	uint8 i=0;
	while(str[i]!= '\0')
	
	{
		LCD_sendData(str[i]);
		i++;
	}
}

void LCD_goToRowColumn(uint8 row, uint8 col)
{
	volatile uint8 address;
	
	/* first of all calculate the required address */
	switch(row)
	{
	case 0 : address=col;
	break;
	case 1 : address=col+0x40;
	break;
	case 2 : address=col+0x10;
	break;
	case 3 : address=col+0x50;
	break;
	}
		/* to write to a specific address in the LCD 
	     * we need to apply the corresponding command 0b10000000+Address */
LCD_sendCommand(address|SET_CURSOR_LOCATION);
}

void LCD_sendStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	
	LCD_sendString(Str); /* display the string */
}

void LCD_intgerToString(uint8 a_data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(a_data,buff,10); /* 10 for decimal */
	LCD_sendString(buff);
}

void LCD_clear(void)
{
	LCD_sendCommand(CLEAR_COMMAND); /* clear */
}
