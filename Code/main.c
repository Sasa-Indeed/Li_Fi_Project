#define DELAY_VALUE 4000000

#include <stdint.h>
#include <stdio.h>
#include "MCAL/GPIO/gpio.h"
#include "MCAL/SYSTICK/sysTick.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/UART/uart.h"
#include "driverlib/systick.h"
#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"


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
  
  init(); 
  turnOffAll();
  //HAL_SMOKE_SENSOR_Init();
  MCAL_UART_Init1();
  HAL_ULTRASONIC_Init();
 /* timer_config config;
  config.timerWidth = TIMER_WIDTH_16_32;
  config.counterSize = TIMER_SIZE_16_32_32CONFIGURATION;
  config.mode = TIMER_MODE_PERIODIC;
  config.countDirection = TIMER_COUNT_DIRECTION_DOWN;
  config.timerAlpha = TIMER_ALPHA_A;
  config.enableInterrupt = TIMER_INTERRUPT_ENABLE_A;
  config.callBackFunc = toggle;
  MCAL_TIMER_Init(TIMER0, &config);
  MCAL_TIMER_DelayMs(TIMER0, 1000);*/
  uint8 ch;
  uint32 time_ds;
  uint8 msg[20];

   timer_config config;
  //MCAL_SYSTICK_delayMs(1000);
  //MCAL_SYSTICK_EnableInterrupt(toggle);
  
  config.timerWidth = TIMER_WIDTH_16_32;
  config.timeNumber = TIMER_NUMBER_2;
  config.counterSize = TIMER_SIZE_16_32_32CONFIGURATION;
  config.mode = TIMER_MODE_PERIODIC;
  config.countDirection = TIMER_COUNT_DIRECTION_DOWN;
  config.timerAlpha = TIMER_ALPHA_A;
  config.enableInterrupt = TIMER_INTERRUPT_ENABLE_NONE;
  
  MCAL_TIMER_Init(TIMER2, &config);
    
   
   /* MCAL_GPIO_TogglePin(GPIOF, PIN_3);*/
      /*
    if(counter >= 5){
      MCAL_GPIO_TogglePin(GPIOF, PIN_1);
      counter = 0;
    }
  
    MCAL_UART_PrintString("Enter \"r\", \"g\", or \"b\":\n\r");
    ch = MCAL_UART_ReadChar();
    MCAL_UART_PrintChar(ch);
    MCAL_UART_PrintString("\n\r");
    switch(ch){
    case 'r':
      turnOnRed();
      break;
      
    case 'b':
      turnOnBule();
      break;
      
    case 'g':
      turnOnGreen();
      break;
      
    default:
      turnOffAll();
      break;
    }

if(HAL_SMOKE_SENSOR_Read() == HIGH){
      MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
    }else{
      MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
    }
    MCAL_GPIO_TogglePin(GPIOF, PIN_1);
    MCAL_TIMERA_DelayMs_P(TIMER1, 1000);
    */
  
  // SysTickIntRegister(toggle);
   //SysTickPeriodSet(7999999);
   //SysTickEnable();
   

  while(1){
    time_ds = HAL_ULTRASONIC_Measure_Distance();
    sprintf(msg, "\r\nDistance = %d cm", time_ds);
    MCAL_UART_PrintString1(msg);
    MCAL_TIMERA_DelayMs_P(TIMER2, 2000);
  }
  

  

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

  config.pinNumber = PIN_0;  
  config.direction = MCAL_GPIO_DIRECTION_INPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
  MCAL_GPIO_Pin_Init(GPIOF, &config);

  config.pinNumber = PIN_4;
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

