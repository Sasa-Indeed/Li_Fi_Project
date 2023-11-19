#include "gpio.h"

void MCAL_GPIO_Init(gpio_typedef * PORTx, uint8 portNumber){

  //1. Initializing clock
  SYSCTL_RCGCGPIO_R |= portNumber;
  
  //2. Busy wait until port is ready
  while((SYSCTL_PRGPIO_R & portNumber) == 0);
  
  //3. Unlocking port 
  PORTx->GPIOLOCK  = 0x4C4F434B;
}

void MCAL_GPIO_Pin_Init(gpio_typedef * PORTx, pin_config_t * config){

  
  //2. Commiting changes
  PORTx->GPIOCR |= config->pinNumber;
  
  //3. Configuring direction
  if(config->direction == MCAL_GPIO_DIRECTION_INPUT){
    PORTx->GPIODIR &= ~config->pinNumber;   //Configuring pin as output
  }else {
    PORTx->GPIODIR |= config->pinNumber;    //Configuring pin as input
  }
  
  //4. Configuring output options
  switch(config->outputMode){
  case MCAL_GPIO_OUTPUT_MODE_OPEN_DRAIN :
    PORTx->GPIOODR |= config->pinNumber;
    break;
   
  case MCAL_GPIO_OUTPUT_MODE_PULL_UP :
    PORTx->GPIOPUR |= config->pinNumber;
    break;
  
  case MCAL_GPIO_OUTPUT_MODE_PULL_DOWN :
    PORTx->GPIOPDR |= config->pinNumber;
    break;
    
  default:
    break;
  }
  
  //5. Configuring output speed
  switch(config->outputSpeed){
  case MCAL_GPIO_OUTPUT_SPEED_2mA_DRIVE :
    PORTx->GPIODR2R |= config->pinNumber;
    break;
   
  case MCAL_GPIO_OUTPUT_SPEED_4mA_DRIVE :
    PORTx->GPIODR4R |= config->pinNumber;
    break;
  
  case MCAL_GPIO_OUTPUT_SPEED_8mA_DRIVE :
    PORTx->GPIODR8R |= config->pinNumber;
    break;
    
  default:
    break;
  }
  
  //6. Enabling pins 
  PORTx->GPIODEN |= config->pinNumber;
}

void MCAL_GPIO_WritePin(gpio_typedef * PORTx, uint8 PINx, uint8 value){
  if(value == HIGH){
    PORTx->GPIODATA |= PINx; //Writing logical one
  }else{
    PORTx->GPIODATA &= ~PINx; //Writing logical zero
  }
}



void MCAL_GPIO_WritePort(gpio_typedef * PORTx, uint8 value){
  PORTx->GPIODATA = value; //Writing on the whole port
}




void MCAL_GPIO_TogglePin(gpio_typedef * PORTx, uint8 PINx){
   PORTx->GPIODATA ^= PINx; //Toggling a pin
}



void MCAL_GPIO_ReadPin(gpio_typedef * PORTx, uint8 PINx, uint8 *value){
  *value = ((PORTx->GPIODATA & PINx) != LOW) ? HIGH : LOW; //Reading a pin 
}




void MCAL_GPIO_ReadPort(gpio_typedef * PORTx, uint8 *value){
  *value = PORTx->GPIODATA; //Reading the whole port
}

