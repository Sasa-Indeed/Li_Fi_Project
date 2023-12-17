#include "bluetooth.h"

void HAL_BLUETOOTH_Init(void){
  MCAL_UART1_Init();
}


uint8 HAL_BLUETOOTH_Read_Char(void){
  return MCAL_UART1_ReadChar();
}

void HAL_BLUETOOTH_Send_Message(uint8_ptr string){
  MCAL_UART1_PrintString(string);
}

