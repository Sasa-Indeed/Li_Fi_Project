#include "gpio.h"


#define INT_GPIOA               16          // GPIO Port A
#define INT_GPIOB               17          // GPIO Port B
#define INT_GPIOC               18          // GPIO Port C
#define INT_GPIOD               19          // GPIO Port D
#define INT_GPIOE               20          // GPIO Port E
#define INT_GPIOF               46          // GPIO Port F


void GPIOA_IntHandler(void);
void GPIOB_IntHandler(void);
void GPIOC_IntHandler(void);
void GPIOD_IntHandler(void);
void GPIOE_IntHandler(void);
void GPIOF_IntHandler(void);


typedef void (*voidFunctionPointer)(void);
voidFunctionPointer callBackFuncs[6];

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
    
    
    if(config->enableEXTI == MCAL_GPIO_ENABLEEXTI_ENABLE){
      switch(config->portNumber){
      case PORTA: // GPIO A
        GPIOIntEnable(GPIO_PORTA_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTA_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[0] = config->callBackFunc;
        IntRegister(INT_GPIOA, GPIOA_IntHandler);
        IntEnable(INT_GPIOA);
        break;
      
      case PORTB: // GPIO B
        GPIOIntEnable(GPIO_PORTB_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTB_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[1] = config->callBackFunc;
        IntRegister(INT_GPIOB, GPIOB_IntHandler);
        IntEnable(INT_GPIOB);
        break;
        
      case PORTC: // GPIO C
        GPIOIntEnable(GPIO_PORTC_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTC_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[2] = config->callBackFunc;
        IntRegister(INT_GPIOC, GPIOC_IntHandler);
        IntEnable(INT_GPIOC);
        break;
      
      case PORTD:// GPIO D
        GPIOIntEnable(GPIO_PORTD_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTD_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[3] = config->callBackFunc;
        IntRegister(INT_GPIOD, GPIOD_IntHandler);
        IntEnable(INT_GPIOD);
        break;
      
      case PORTE:// GPIO E
        GPIOIntEnable(GPIO_PORTE_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTE_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[4] = config->callBackFunc;
        IntRegister(INT_GPIOE, GPIOE_IntHandler);
        IntEnable(INT_GPIOE);
        break;
      
      case PORTF:// GPIO F
        GPIOIntEnable(GPIO_PORTF_BASE, config->EXTIPinNumber);
        GPIOIntTypeSet(GPIO_PORTF_BASE, config->EXTIPinNumber, config->edgeTrigger);
        callBackFuncs[5] = config->callBackFunc;
        IntRegister(INT_GPIOF, GPIOF_IntHandler);
        IntEnable(INT_GPIOF);
        break;
      }
      
      IntMasterEnable();
    }
    
  }else{
    //Enabling Alternative Function to the pin
    *((uint32_ptr)((uint8_ptr)PORTx + GPIOAFSEL_BASE)) |= config->pinNumber;
    
    if(config->alterFuncIO == MCAL_GPIO_ALTERFUNCIO_ENABLE){
      if(config->direction == MCAL_GPIO_DIRECTION_INPUT){
        *((uint32_ptr)((uint8_ptr)PORTx + GPIODIR_BASE)) &= ~config->pinNumber;   //Configuring pin as input
      }else {
        *((uint32_ptr)((uint8_ptr)PORTx + GPIODIR_BASE)) |= config->pinNumber;    //Configuring pin as output
      }
    }
    
    switch(config->pinNumber){
    case PIN_0 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= config->alterFunc;
      break;
     
    case PIN_1 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 4);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 4);
      break;
    
    case PIN_2 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 8);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 8);
      break;
      
    case PIN_3 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 12);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 12);
      break;
      
    case PIN_4 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 16);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 16);
      break;
      
    case PIN_5 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 20);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 20);
      break;
      
    case PIN_6 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF << 24);
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) |= (config->alterFunc << 24);
      break;
      
    case PIN_7 :
      *((uint32_ptr)((uint8_ptr)PORTx + GPIOPCTL_BASE)) &= ~(0xF<< 28);
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


void GPIOA_IntHandler(void){
  callBackFuncs[0]();
}

void GPIOB_IntHandler(void){
  callBackFuncs[1]();
}

void GPIOC_IntHandler(void){
  callBackFuncs[2]();
}

void GPIOD_IntHandler(void){
  callBackFuncs[3]();
}

void GPIOE_IntHandler(void){
  callBackFuncs[4]();
}

void GPIOF_IntHandler(void){
  callBackFuncs[5]();
}

void MCAL_GPIO_Disable_Interrupt(uint8 portNumber, uint8 EXTIPinNumber){
  switch(portNumber){
  case PORTA: // GPIO A
    GPIOIntDisable(GPIO_PORTA_BASE, EXTIPinNumber);
    break;
  
  case PORTB: // GPIO B
    GPIOIntDisable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
    
  case PORTC: // GPIO C
    GPIOIntDisable(GPIO_PORTC_BASE, EXTIPinNumber);
    break;
  
  case PORTD:// GPIO D
    GPIOIntDisable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  
  case PORTE:// GPIO E
    GPIOIntDisable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  
  case PORTF:// GPIO F
    GPIOIntDisable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  }
}


void MCAL_GPIO_Enale_Interrupt(uint8 portNumber, uint8 EXTIPinNumber){
  switch(portNumber){
  case PORTA: // GPIO A
    GPIOIntEnable(GPIO_PORTA_BASE, EXTIPinNumber);
    break;
  
  case PORTB: // GPIO B
    GPIOIntEnable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
    
  case PORTC: // GPIO C
    GPIOIntEnable(GPIO_PORTC_BASE, EXTIPinNumber);
    break;
  
  case PORTD:// GPIO D
    GPIOIntEnable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  
  case PORTE:// GPIO E
    GPIOIntEnable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  
  case PORTF:// GPIO F
    GPIOIntEnable(GPIO_PORTB_BASE, EXTIPinNumber);
    break;
  }
}


