#ifndef _GPIO_H_
#define _GPIO_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define SYSTEM_CLK              16000000U




//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL sysTick Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_GPIO_Init
*
* Description  : This function initialize the clock of the GPIO
*
* PARAMETER 1 : The port which you want to initialize
*
* PARAMETER 2 : The port mask you want to initialize
* 
* Return Value : None
*
* Note!!!     : In parameter 1 and 2 must be from @ref GPIO, 
@ref portNumber Respectively
******************************************************************************/

void MCAL_SysTickDisable(void);

void MCAL_SysTickEnable(void);

void MCAL_SysTickEnableInterrupt(void (*func)(void));

uint32 MCAL_SysTickPeriodGet(void);

void MCAL_SysTickPeriodSet(uint32 period);

uint32 MCAL_SysTickValueGet(void);

boolean MCAL_SysTick_Is_Time_out(void);

void MCAL_SYSTICK_delayMs(uint16 delay);


#endif /* _GPIO_H_ */