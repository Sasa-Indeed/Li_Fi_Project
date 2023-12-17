#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/UART/uart.h"

//--------------------------------
//Macros Configuration References
//--------------------------------



//------------------------------------------------------------------------------------------
//			APIs supported by "HAL BLUETOOTH Driver"
//------------------------------------------------------------------------------------------
void HAL_BLUETOOTH_Init(void);
uint8 HAL_BLUETOOTH_Read_Char(void);
void HAL_BLUETOOTH_Send_Message(uint8_ptr string);




#endif /* _BLUETOOTH_H_ */