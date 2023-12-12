#include "smoke_sensor.h"

void HAL_SMOKE_SENSOR_Init(void){
  pin_config_t config;

  MCAL_GPIO_Init(SMOKE_SENSOR_PORT, SMOKE_SENSOR_PORT_NUMBER);

  config.pinNumber = SMOKE_SENSOR_PIN;
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_PULL_UP;

  MCAL_GPIO_Pin_Init(SMOKE_SENSOR_PORT, &config);
  
}

uint8 HAL_SMOKE_SENSOR_Read(void){
  uint8 data;
  MCAL_GPIO_ReadPin(SMOKE_SENSOR_PORT, SMOKE_SENSOR_PIN, &data);
  if(data == LOW){
    return HIGH;
  }else{
    return LOW;
  }
}