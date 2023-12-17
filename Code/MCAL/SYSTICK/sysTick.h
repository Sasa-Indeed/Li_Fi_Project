#ifndef _SYSTICK_H_
#define _SYSTICK_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define SYSTEM_CLK              16000000U
#define SYSTEM_CLK_4            16000U



//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL sysTick Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_SYSTICK_Disable
*
* Description  : This function disables the system timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_SYSTICK_Disable(void);


/****************************************************************************
* Function Name: MCAL_SYSTICK_Enable
*
* Description  : This function enables the system timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_SYSTICK_Enable(void);


/****************************************************************************
* Function Name: MCAL_SYSTICK_EnableInterrupt
*
* Description  : This function enables the the interrupt 
*
* PARAMETER1 : The callback function
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_SYSTICK_EnableInterrupt(void (*func)(void));


/****************************************************************************
* Function Name: MCAL_SYSTICK_PeriodGet
*
* Description  : This function returns the reload value 
*
* PARAMETERS : None
* 
* Return Value : Reload value from STRELOAD register
*
* Note!!!     : None
******************************************************************************/
uint32 MCAL_SYSTICK_PeriodGet(void);


/****************************************************************************
* Function Name: MCAL_SYSTICK_PeriodSet
*
* Description  : This function sets the reload value
*
* PARAMETERS : The reload value
* 
* Return Value : None
*
* Note!!!     : If the value is greater than 0xFFFFFF it will be set 
* to 0xFFFFFF
******************************************************************************/
void MCAL_SYSTICK_PeriodSet(uint32 period);


/****************************************************************************
* Function Name: MCAL_SYSTICK_ValueGet
*
* Description  : This function returns the current value 
*
* PARAMETERS : None
* 
* Return Value : Current value from STCURRENT register
*
* Note!!!     : None
******************************************************************************/
uint32 MCAL_SYSTICK_ValueGet(void);


/****************************************************************************
* Function Name: MCAL_SYSTICK_Is_Time_out
*
* Description  : This function returns whether the timer reached to Zero or not
*
* PARAMETERS : None
* 
* Return Value : Returns 0 if count flag is zero returns 1 if count flag is 1
*
* Note!!!     : None
******************************************************************************/
boolean MCAL_SYSTICK_Is_Time_out(void);


/****************************************************************************
* Function Name: MCAL_SYSTICK_delayMs
*
* Description  : This function Makes a delay in mS
*
* PARAMETER1 : The delay required in ms (miliseconds)
* 
* Return Value : None
*
* Note!!!     : It has a max delay of 1.04857s
******************************************************************************/
void MCAL_SYSTICK_delayMs(uint16 delay);


/****************************************************************************
* Function Name: MCAL_SYSTICK_delayMs_P
*
* Description  : This function Makes a delay in mS
*
* PARAMETER1 : The delay required in ms (miliseconds)
* 
* Return Value : None
*
* Note!!!     : It has a max delay of 1.04857s and works with polling
******************************************************************************/
void MCAL_SYSTICK_delayMs_P(uint16 delay);


#endif /* _SYSTICK_H_ */