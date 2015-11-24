/* ---------------------------------------------------------------------------------------------------
[FILE NAME]   : <macros.h>
[AUTHOR]	  : <Aisha Alabasiry>
[DATE CREATED]: <20/1/2015>
[DESCRIPTION] : <common_macros module header file for this Project>
--------------------------------------------------------------------------------------------------- */
#ifndef COMMON_MACRO_H_
#define COMMON_MACRO_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT_NUM) ( REG = REG | (1<<BIT_NUM) )

/*clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT_NUM) ( REG = REG & (~(1<<BIT_NUM)) )

/*check if any bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT_NUM) ( REG & (1<<BIT_NUM) )

/*check if any bit is clear in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT_NUM) ( !(REG & (1<<BIT_NUM)) )

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

#endif /* COMMON_MACRO_H_ */