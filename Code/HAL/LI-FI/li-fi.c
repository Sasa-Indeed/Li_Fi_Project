#include "li-fi.h"


void HAL_LI_FI_Init(void){
  pin_config_t config;
  
  MCAL_GPIO_Init(LI_FI_PORT, LI_FI_PORT_NUMBER);
  
  config.pinNumber = LI_FI_PIN;
  config.direction = MCAL_GPIO_DIRECTION_OUTPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  MCAL_GPIO_Pin_Init(LI_FI_PORT, &config);
  
}


void HAL_LI_FI_On(void){
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
}

void HAL_LI_FI_Off(void){
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);
}


void HAL_LI_FI_Smoke_Message(void){
  uint8 i = 7;
  
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);
}

void HAL_LI_FI_Door_Message(void){
  uint8 i = 5;
  
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);
}

void HAL_LI_FI_Ultrasonic_Message(void){
  uint8 i = 3;
  
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);
}


void HAL_LI_FI_System_On_Message(void){
  uint8 i = 9;
  
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);
}

void HAL_LI_FI_System_Off_Message(void){
  uint8 i = 11;
  
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, HIGH);
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
  MCAL_GPIO_WritePin(LI_FI_PORT, LI_FI_PIN, LOW);

}