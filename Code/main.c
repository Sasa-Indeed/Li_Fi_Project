#define DELAY_VALUE 4000000

#include "MCAL/GPIO/gpio.h"

void turnOnWhite(void);
void turnOnRed(void);
void turnOnBule(void);
void turnOnGreen(void);
void turnOffAll(void);
void init(void);
void read(uint8_ptr out1, uint8_ptr out2);
void Delay(void);


int main(){
  
  init(); 
  turnOffAll();
  
  
 uint8 swt1 = 0, swt2 = 0; 
  
  turnOnWhite();
  uint8 counter = 0; 

  while(1){
  read(&swt2, &swt1);
  
  if((swt1 && swt2)){
    counter = 0;
  }else if(swt2 == HIGH){
    counter = (counter == 3) ? 0 : counter + 1;
  }else if(swt1 == HIGH){
    counter = (counter == 0) ? 3 : counter - 1;
  }else{
    continue;
  }
  
  switch(counter){
  case 0 :
    turnOffAll();
    turnOnWhite();
    break;
  
  case 1 :
    turnOffAll();
    turnOnRed();
    break;
    
  case 2 :
    turnOffAll();
    turnOnGreen();
    break;
    
  case 3 :
    turnOffAll();
    turnOnBule();
    break;
  }

}
  
  /*while(1){
      MCAL_GPIO_WritePin(GPIOF, PIN_1, HIGH);
      Delay();
      MCAL_GPIO_WritePin(GPIOF, PIN_2, HIGH);
      Delay();
      MCAL_GPIO_WritePin(GPIOF, PIN_3, HIGH);
      Delay();
      MCAL_GPIO_WritePin(GPIOF, PIN_1, LOW);
      Delay();
      MCAL_GPIO_WritePin(GPIOF, PIN_2, LOW);
      Delay();
      MCAL_GPIO_WritePin(GPIOF, PIN_3, LOW);
      Delay();
  }*/
  
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

