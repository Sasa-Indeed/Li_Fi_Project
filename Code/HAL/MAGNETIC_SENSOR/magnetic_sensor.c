#include "magnetic_sensor.h"
#include "../../MCAL/SYSTICK/sysTick.h"


void HAL_MAGNETIC_SENSOR_Init(void (* callBack)(void)){
  pin_config_t config;

  MCAL_GPIO_Init(MAGNETIC_SENSOR_PORT, MAGNETIC_SENSOR_PORT_NUMBER);

  config.pinNumber = MAGNETIC_SENSOR_PIN;
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
  //For enabling external interrupt
  config.portNumber = MAGNETIC_SENSOR_PORT_NUMBER;
  config.enableEXTI = MCAL_GPIO_ENABLEEXTI_ENABLE;
  config.EXTIPinNumber = MAGNETIC_SENSOR_PIN_INT;
  config.edgeTrigger = GPIO_RISING_EDGE;
  config.callBackFunc = callBack;
  
  
  MCAL_GPIO_Pin_Init(MAGNETIC_SENSOR_PORT, &config);
   
}

/*If the door was opened it returns HIGH if the door was closed it returns LOW*/
uint8 HAL_MAGNETIC_SENSOR_Read(void){
  uint8 data;
  MCAL_GPIO_ReadPin(MAGNETIC_SENSOR_PORT, MAGNETIC_SENSOR_PIN, &data);
  return data;
}



void HAL_MAGNETIC_SENSOR_Off(void){
  MCAL_GPIO_Disable_Interrupt(MAGNETIC_SENSOR_PORT_NUMBER, MAGNETIC_SENSOR_PIN_INT);
}

void HAL_MAGNETIC_SENSOR_On(void){
  MCAL_GPIO_Enale_Interrupt(MAGNETIC_SENSOR_PORT_NUMBER, MAGNETIC_SENSOR_PIN_INT);
}