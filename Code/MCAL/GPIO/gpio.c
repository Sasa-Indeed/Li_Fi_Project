#include "gpio.h"

void MCAL_GPIO_Init(vuint32_ptr PORTx, uint8 portNumber){

  //1. Initializing clock
  SYSCTL_RCGCGPIO_R |= portNumber;
  
  //2. Busy wait until port is ready
  while((SYSCTL_PRGPIO_R & portNumber) == 0);
}

void MCAL_GPIO_Pin_Init(vuint32_ptr PORTx, pin_config_t * config){
  
   //1. Unlocking port 
  *((uint32_ptr)((uint8_ptr)PORTx + GPIOLOCK_BASE))  = 0x4C4F434B;
  
  //2. Commiting changes 
  *((uint32_ptr)((uint8_ptr)PORTx + GPIOCR_BASE)) |= config->pinNumber;
  
  if(config->alterFunc == MCAL_GPIO_ALTERFUNC_NONE){
    //3. Configuring direction 
    if(config->direction == MCAL_GPIO_DIRECTION_INPUT){
      *((uint32_ptr)((uint8_ptr)PORTx + GPIODIR_BASE)) &= ~config->pinNumber;   //Configuring pin as input
    }else {
      *((uint32_ptr)((uint8_ptr)PORTx + GPIODIR_BASE)) |= config->pinNumber;    //Configuring pin as output
    }
    
    //4. Configuring output options 
    switch(config->outputMode){
    case MCAL_GPIO_OUTPUT_MODE_OPEN_DRAIN :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOODR_BASE)) |= config->pinNumber;
      break;
     
    case MCAL_GPIO_OUTPUT_MODE_PULL_UP :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPUR_BASE)) |= config->pinNumber;
      break;
    
    case MCAL_GPIO_OUTPUT_MODE_PULL_DOWN :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPDR_BASE)) |= config->pinNumber;
      break;
      
    default:
      break;
    }
    
    //5. Configuring output speed 
    switch(config->outputSpeed){
    case MCAL_GPIO_OUTPUT_SPEED_2mA_DRIVE :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIODR2R_BASE)) |= config->pinNumber;
      break;
     
    case MCAL_GPIO_OUTPUT_SPEED_4mA_DRIVE :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIODR4R_BASE)) |= config->pinNumber;
      break;
    
    case MCAL_GPIO_OUTPUT_SPEED_8mA_DRIVE :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIODR8R_BASE)) |= config->pinNumber;
      break;
      
    default:
      break;
    }
  }else{
    //Enabling Alternative Function to the pin
    *((uint32_ptr)((uint8_ptr)PORTx + GPIOAFSEL_BASE)) |= config->pinNumber;
    
    switch(config->pinNumber){
    case PIN_0 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= config->alterFunc;
      break;
     
    case PIN_1 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 4);
      break;
    
    case PIN_2 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 8);
      break;
      
    case PIN_3 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 12);
      break;
      
    case PIN_4 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 16);
      break;
      
    case PIN_5 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 20);
      break;
      
    case PIN_6 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 24);
      break;
      
    case PIN_7 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 28);
      break;
      
    default:
      break;
    }
  }
  
  //6. Enabling pins  
  *((uint32_ptr)((uint8_ptr)PORTx + GPIODEN_BASE)) |= config->pinNumber;
}

void MCAL_GPIO_WritePin(vuint32_ptr PORTx, uint8 PINx, uint8 value){
  if(value == HIGH){
    *((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)) |= PINx; //Writing logical one 
  }else{
    *((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)) &= ~PINx; //Writing logical zero
  }
}



void MCAL_GPIO_WritePort(vuint32_ptr PORTx, uint8 value){
  *((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)) = value; //Writing on the whole port
}




void MCAL_GPIO_TogglePin(vuint32_ptr PORTx, uint8 PINx){
   *((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)) ^= PINx; //Toggling a pin
}



void MCAL_GPIO_ReadPin(vuint32_ptr PORTx, uint8 PINx, uint8 *value){
  *value = ((*((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)) & PINx) != LOW) ? HIGH : LOW; //Reading a pin 
}




void MCAL_GPIO_ReadPort(vuint32_ptr PORTx, uint8 *value){
  *value = *((uint32_ptr)((uint8_ptr)PORTx + GPIODATA_BASE)); //Reading the whole port
}

