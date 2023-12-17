#include "smoke_sensor.h"


void smoke_sensor_handler(void);


void HAL_SMOKE_SENSOR_Init(void (* callBack)(void)){
  pin_config_t config;

  MCAL_GPIO_Init(SMOKE_SENSOR_PORT, SMOKE_SENSOR_PORT_NUMBER);

  config.pinNumber = SMOKE_SENSOR_PIN;
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
  //For enabling external interrupt
  config.portNumber = PORTA;
  config.enableEXTI = MCAL_GPIO_ENABLEEXTI_ENABLE;
  config.EXTIPinNumber = SMOKE_SENSOR_PIN_INT;
  config.edgeTrigger = GPIO_RISING_EDGE;
  config.callBackFunc = callBack;
  
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

void smoke_sensor_handler(void){
  GPIOIntClear(GPIO_PORTA_BASE, SMOKE_SENSOR_PIN);
  MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
  MCAL_SYSTICK_delayMs_P(1000);
  MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
}