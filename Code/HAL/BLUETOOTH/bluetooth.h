#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/UART/uart.h"



//------------------------------------------------------------------------------------------
//			APIs supported by "HAL BLUETOOTH Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_BLUETOOTH_Init
*
* Description  : This function initializes the Bluetooth module
*
* PARAMETERS   : None
*
* Return Value : None
*
* Note!!!      : None
******************************************************************************/
void HAL_BLUETOOTH_Init(void);

/****************************************************************************
* Function Name: HAL_BLUETOOTH_Read_Char
*
* Description  : This function reads a character from the Bluetooth module
*
* PARAMETERS   : None
*
* Return Value : The character which was read
*
* Note!!!      : None
******************************************************************************/
uint8 HAL_BLUETOOTH_Read_Char(void);

/****************************************************************************
* Function Name: HAL_BLUETOOTH_Send_Message
*
* Description  : This function sends a string via Bluetooth module
*
* PARAMETER1   : The string you want to send
*
* Return Value : None
*
* Note!!!      : None
******************************************************************************/
void HAL_BLUETOOTH_Send_Message(uint8_ptr string);




#endif /* _BLUETOOTH_H_ */