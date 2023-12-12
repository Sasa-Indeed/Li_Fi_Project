#include "ultrasonic_sensor.h"

void Timer0ACapture_init(void);
void Delay_MicroSecond(int time);





void Timer0ACapture_init(void){
  pin_config_t config;
  
  //Enabling the pin for echo pin
  MCAL_GPIO_Init(ECHO_PORT, ECHO_PORT_NUMBER);
  config.pinNumber = ECHO_PIN;
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = 0x7;
  MCAL_GPIO_Pin_Init(ECHO_PORT, &config);
  
  //Enabling the pin for trigger pin
  MCAL_GPIO_Init(TRIGGER_PORT, TRIGGER_PORT_NUMBER);
  config.pinNumber = TRIGGER_PIN;
  config.direction = MCAL_GPIO_DIRECTION_OUTPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  MCAL_GPIO_Pin_Init(TRIGGER_PORT, &config);

}