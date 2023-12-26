#ifndef _LI_FI_H_
#define _LI_FI_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/SYSTICK/sysTick.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define LI_FI_PORT                               GPIOB
#define LI_FI_PORT_NUMBER                        PORTB
#define LI_FI_PIN                                PIN_3


//------------------------------------------------------------------------------------------
//			APIs supported by "HAL li-fi Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_LI_FI_Init
*
* Description  : This function initializes the li-fi system
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Init(void);


/****************************************************************************
* Function Name: HAL_LI_FI_On
*
* Description  : This function turns on the LED connected to the system
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_On(void);


/****************************************************************************
* Function Name: HAL_LI_FI_Off
*
* Description  : This function turns off the LED connected to the system
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Off(void);


/****************************************************************************
* Function Name: HAL_LI_FI_Smoke_Message
*
* Description  : This function sends the code of smoke alarm thorough the LED
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Smoke_Message(void);


/****************************************************************************
* Function Name: HAL_LI_FI_Door_Message
*
* Description  : This function sends the code of door alarm thorough the LED
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Door_Message(void);

/****************************************************************************
* Function Name: HAL_LI_FI_Ultrasonic_Message
*
* Description  : This function sends the code of proximity alarm thorough the LED
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Ultrasonic_Message(void);


/****************************************************************************
* Function Name: HAL_LI_FI_System_On_Message
*
* Description  : This function sends the code of turning on the system thorough the LED
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_System_On_Message(void);


/****************************************************************************
* Function Name: HAL_LI_FI_System_Off_Message
*
* Description  : This function sends the code of turning off the system thorough the LED
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_System_Off_Message(void);

#endif /* _LI_FI_H_ */