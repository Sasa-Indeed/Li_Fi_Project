#include "ultrasonic_sensor.h"



void HAL_ULTRASONIC_SENSOR_Init(void){
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
  
  //Enabling timer0A of capture mode
  timer_config t_config;  
  t_config.timerWidth = TIMER_WIDTH_16_32;
  t_config.counterSize = TIMER_SIZE_16_32_16CONFIGURATION;
  t_config.timeNumber = TIMER_NUMBER_0;
  t_config.mode = TIMER_MODE_CAPTURE_EDGE_TIME;
  t_config.countDirection = TIMER_COUNT_DIRECTION_UP;
  t_config.captureEdge = TIMER_CAPTURE_EDGE_BOTH;
  t_config.timerAlpha = TIMER_ALPHA_A;
  t_config.enableInterrupt = TIMER_INTERRUPT_ENABLE_NONE;
  
  MCAL_TIMER_Init(CAPTURE_TIMER, &t_config);
  
  //Making sure everything is reset to remove unknown behavoir
  t_config.timerAlpha = 0;
  t_config.mode = 0;
  t_config.timerUse = 0;
  t_config.countDirection = 0;
  t_config.counterSize = 0;
  t_config.timeNumber = 0;
  t_config.timerWidth = 0;
  t_config.prescalerSize = 0;
  t_config.enableInterrupt = 0;
  t_config.captureEdge = 0;
  
  
  //For delay timer
  t_config.timerWidth = TIMER_WIDTH_16_32;
  t_config.timeNumber = TIMER_NUMBER_1;
  t_config.counterSize = TIMER_SIZE_16_32_32CONFIGURATION;
  t_config.mode = TIMER_MODE_PERIODIC;
  t_config.countDirection = TIMER_COUNT_DIRECTION_DOWN;
  t_config.timerAlpha = TIMER_ALPHA_A;
  t_config.enableInterrupt = TIMER_INTERRUPT_ENABLE_NONE;
  
  MCAL_TIMER_Init(DELAY_TIMER, &t_config);
  
}


uint32 HAL_ULTRASONIC_Measure_Distance(void){
  uint32 time;
  time = MCAL_TIMER_Measure_Capture_Time(TRIGGER_PORT, TRIGGER_PIN, ECHO_PORT, 
                                         ECHO_PIN, DELAY_TIMER, CAPTURE_TIMER);
  return (time * 10625)/10000000;
}