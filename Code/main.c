#define DELAY_VALUE 4000000
/*
#include <stdint.h>
#include <stdio.h>
#include "MCAL/GPIO/gpio.h"
#include "MCAL/SYSTICK/sysTick.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/UART/uart.h"
#include "driverlib/systick.h"
#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "HAL/MAGNETIC_SENSOR/magnetic_sensor.h"
#include "HAL/LI-FI/li-fi.h"
#include "HAL/BLUETOOTH/bluetooth.h"
#include "HAL/BUTTON/button.h"
*/

#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "MCAL/UART/uart.h"
#include <stdio.h>
#include "APPLICATION/application.h"
#include "MCAL/SYSTICK/sysTick.h"

void turnOnWhite(void);
void turnOnRed(void);
void turnOnBule(void);
void turnOnGreen(void);
void turnOffAll(void);
void init(void);
void read(uint8_ptr out1, uint8_ptr out2);
void Delay(void);

volatile uint8 counter = 0;

void toggle(void){
  MCAL_GPIO_TogglePin(GPIOF, PIN_2);
}

int main(){
 Application_Init();
 Application_Main_Logic();
  /*HAL_ULTRASONIC_SENSOR_Init();
  MCAL_UART0_Init();
  uint8 msg[20];
  uint32 time_ds;
  while(1){
    time_ds = HAL_ULTRASONIC_Measure_Distance();
    sprintf(msg, "\r\nDistance = %d cm", time_ds);
    MCAL_UART0_PrintString(msg);
     MCAL_SYSTICK_delayMs_P(1000);

  }*/
}


void init(void){
  pin_config_t config;
  
  MCAL_GPIO_Init(GPIOF, PORTF);
  
  config.pinNumber = PIN_1;
  config.direction = MCAL_GPIO_DIRECTION_OUTPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
  config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
  MCAL_GPIO_Pin_Init(GPIOF, &config);
  
  config.pinNumber = PIN_2;
  MCAL_GPIO_Pin_Init(GPIOF, &config);
  
  config.pinNumber = PIN_3;
  MCAL_GPIO_Pin_Init(GPIOF, &config);
  


}

void turnOnWhite(void){
  MCAL_GPIO_WritePin(GPIOF, PIN_1, HIGH);
  MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
  MCAL_GPIO_WritePin(GPIOF, PIN_3, HIGH);
}

void turnOnRed(void){
  MCAL_GPIO_WritePin(GPIOF, PIN_1, HIGH);
}

void turnOnBule(void){
  MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);

}

void turnOnGreen(void){
  MCAL_GPIO_WritePin(GPIOF, PIN_3, HIGH);
}


void turnOffAll(void){
  MCAL_GPIO_WritePin(GPIOF, PIN_1, LOW);
  MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
  MCAL_GPIO_WritePin(GPIOF, PIN_3, LOW);
}

void read(uint8_ptr out1, uint8_ptr out2){
  *out1 = 0;
  *out2 = 0;
  uint8 swt1 = 0, swt2 = 0;
  
  do{
    MCAL_GPIO_ReadPin(GPIOF, PIN_0, &swt1);
    MCAL_GPIO_ReadPin(GPIOF, PIN_4, &swt2);
    *out1 |= !swt1;
    *out2 |= !swt2;
  }while(!(swt1 && swt2));
}

void Delay(void){

volatile unsigned long i;

for(i=0;i<DELAY_VALUE;i++);

}

