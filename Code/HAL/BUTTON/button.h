#ifndef _BUTTON_H_
#define _BUTTON_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"
//Removed systick

//--------------------------------
//Macros Configuration References
//--------------------------------
#define BUTTON_PORT                               GPIOF
#define BUTTON_PORT_NUMBER                        PORTF

//@ref Buttons
#define START_BUTTON                              PIN_4
#define STOP_BUTTON                               PIN_0

//For interrupt
#define BUTTON_START_PIN_INT                      GPIO_INT_PIN_4
#define BUTTON_START_GPIO_INT                     GPIO_PORTF_BASE  // For Clearing interrupt




//------------------------------------------------------------------------------------------
//			APIs supported by "HAL BUTTON Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_Button_Init
*
* Description  : This function initializes the button
*
* PARAMETER1   : The call back for the start button
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_Button_Init(void (* startButtoncallBack)(void));


/****************************************************************************
* Function Name: HAL_Button_Read
*
* Description  : This function reads the input from the button
*
* PARAMETER1   : The pin in which the button is located
*
* PARAMETER2   : The data will be stored in this value
* 
* Return Value : None
*
* Note!!!     : In parameter 1 must be from @ref Buttons, 
 Returns High if button pressed
******************************************************************************/
void HAL_Button_Read(uint8 pinNumber,uint8_ptr out1);




#endif /* _LED_H_ */