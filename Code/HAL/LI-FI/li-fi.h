#ifndef _LED_H_
#define _LED_H_

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
//			APIs supported by "HAL LED Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_UART_Init
*
* Description  : This function disables the timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_LI_FI_Init(void);
void HAL_LI_FI_On(void);
void HAL_LI_FI_Off(void);


void HAL_LI_FI_Smoke_Message(void);
void HAL_LI_FI_Door_Message(void);
void HAL_LI_FI_Ultrasonic_Message(void);

void HAL_LI_FI_System_On_Message(void);
void HAL_LI_FI_System_Off_Message(void);



#endif /* _LED_H_ */