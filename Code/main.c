#define DELAY_VALUE 4000000

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
  timer_config config;
  HAL_Button_Init();
  uint8 data;

  // HAL_SMOKE_SENSOR_Init();
 // HAL_BLUETOOTH_Init();
 // uint8 i = 0;
 //HAL_MAGNETIC_SENSOR_Init();
  //MCAL_UART1_Init();
 //HAL_ULTRASONIC_Init();
 //uint32 ds;
 /* timer_config config;
  config.timerWidth = TIMER_WIDTH_16_32;
  config.counterSize = TIMER_SIZE_16_32_32CONFIGURATION;
  config.mode = TIMER_MODE_PERIODIC;
  config.countDirection = TIMER_COUNT_DIRECTION_DOWN;
  config.timerAlpha = TIMER_ALPHA_A;
  config.enableInterrupt = TIMER_INTERRUPT_ENABLE_A;
  config.callBackFunc = toggle;
  MCAL_TIMER_Init(TIMER0, &config);
  MCAL_TIMER_DelayMs(TIMER0, 1000);
  uint8 ch;
  uint32 time_ds;
  uint8 msg[20];

   timer_config config;
  //MCAL_SYSTICK_delayMs(1000);
  //MCAL_SYSTICK_EnableInterrupt(toggle);*/
  
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
   
  //HAL_LCD_Init();
  while(1){
    /*time_ds = HAL_ULTRASONIC_Measure_Distance();
    sprintf(msg, "\r\nDistance = %d cm", time_ds);
    MCAL_UART_PrintString1(msg);
    MCAL_TIMERA_DelayMs_P(TIMER2, 2000);*/
   // MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
   // MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
    //Door();
    //CAL_TIMERA_DelayMs_P(TIMER2, 2000);
    //fire();
    //MCAL_TIMERA_DelayMs_P(TIMER2, 2000);
    //Ultra();
    //MCAL_TIMERA_DelayMs_P(TIMER2, 2000);
    //Door();
    //HAL_LCD_On();
   // HAL_LCD_Off();
    /*if(HAL_MAGNETIC_SENSOR_Read() == HIGH){
      MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
    }else{
      MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
    }
    MCAL_TIMERA_DelayMs_P(TIMER2, 1000);
    */
    
     /* if(i == 0){
        HAL_BLUETOOTH_Send_Message("Smoke Detected!!!\n");
        i++;
      }else if(i == 1){
        HAL_BLUETOOTH_Send_Message("Door was Opened!!!\n");
        i++;
      }else if(i == 2){
        HAL_BLUETOOTH_Send_Message("Proximity Warning!!!\n");
        i++;
      }else{
        i = 0;
      }
      
      MCAL_TIMERA_DelayMs_P(TIMER2, 1000);*/
      HAL_Button_Read(STOP_BUTTON, &data);
      
      if(data == HIGH){
        MCAL_GPIO_TogglePin(GPIOF, PIN_3);
      }
    


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

