#include "button.h"

void HAL_Button_Init(void){
  pin_config_t config;
  
  MCAL_GPIO_Init(BUTTON_PORT, BUTTON_PORT_NUMBER);
  
  config.pinNumber = START_BUTTON;
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  config.enableEXTI = MCAL_GPIO_ENABLEEXTI_DISABLE;
  MCAL_GPIO_Pin_Init(BUTTON_PORT, &config);



  config.pinNumber = STOP_BUTTON;
  MCAL_GPIO_Pin_Init(BUTTON_PORT, &config);  
}


//Return High if button is pressed
void HAL_Button_Read(uint8 pinNumber,uint8_ptr out1){
  *out1 = 0;
  uint8 swt1 = 0;
  
  do{
    MCAL_GPIO_ReadPin(BUTTON_PORT, pinNumber, &swt1);
    *out1 |= !swt1;
  }while(!(swt1));
}