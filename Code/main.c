#define DELAY_VALUE 4000000

#include "MCAL/GPIO/gpio.h"
#include "MCAL/SYSTICK/sysTick.h"

void turnOnWhite(void);
void turnOnRed(void);
void turnOnBule(void);
void turnOnGreen(void);
void turnOffAll(void);
void init(void);
void read(uint8_ptr out1, uint8_ptr out2);
void Delay(void);

void toggle(void){
  static uint8 count = 5;
  if(count == 0){
    MCAL_GPIO_TogglePin(GPIOF, PIN_3);
    count = 5;
  }else{
    count--;
  }
}

int main(){
  
  init(); 
  turnOffAll();

  
  MCAL_SYSTICK_delayMs(1000);
  MCAL_SYSTICK_EnableInterrupt(toggle);
  
  while(1){
    
  }

  
  return 0;
}


void init(void){
  pin_config_t config;
  
  MCAL_GPIO_Init(GPIOF, PORTF);
  
  config.pinNumber = PIN_1;
  config.direction = MCAL_GPIO_DIRECTION_OUTPUT;
  config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
  config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
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

