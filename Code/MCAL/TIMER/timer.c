#include "timer.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"


void (* callbackFunc)(void);

void MCAL_TIMER_Disable(timer_typedef * TIMERx, uint8 timerAlpha){
  if(timerAlpha == TIMER_ALPHA_A){
    CLEAR_BIT(TIMERx->GPTMCTL, 0);
  } else if(timerAlpha == TIMER_ALPHA_B){
    CLEAR_BIT(TIMERx->GPTMCTL, 8);
  }
}


void MCAL_TIMER_Enable(timer_typedef * TIMERx, uint8 timerAlpha){
   if(timerAlpha == TIMER_ALPHA_A){
    SET_BIT(TIMERx->GPTMCTL, 0);
  } else if(timerAlpha == TIMER_ALPHA_B){
    SET_BIT(TIMERx->GPTMCTL, 8);
  }
}

void MCAL_TIMER_Init(timer_typedef * TIMERx, timer_config* config){
  
  //Enalbing Clock
  if(config->timerWidth == TIMER_WIDTH_16_32){
    SET_BIT(SYSCTL_RCGCTIMER_R, config->timeNumber); 
    while((SYSCTL_PRTIMER_R & (1 << config->timeNumber)) == 0);
  }else if(config->timerWidth == TIMER_WIDTH_32_64){
    SET_BIT(SYSCTL_RCGCWTIMER_R, config->timeNumber);
    while((SYSCTL_PRWTIMER_R & (1 << config->timeNumber)) == 0);
  }
  
  MCAL_TIMER_Disable(TIMERx, config->timerAlpha);
  
  TIMERx->GPTMCFG = 0x00000000;
  
  if(config->counterSize == TIMER_SIZE_16_32_32CONFIGURATION || config->counterSize == TIMER_SIZE_32_64_64CONFIGURATION){
    TIMERx->GPTMCFG |= config->counterSize;
    TIMERx->GPTMTAMR |= config->mode;
    TIMERx->GPTMTAMR |= config->countDirection;
    if(TIMERx->GPTMIMR |= config->enableInterrupt == TIMER_INTERRUPT_ENABLE_A){
      IntMasterEnable();
      TIMERx->GPTMIMR |= config->enableInterrupt;
      SET_BIT(TIMERx->GPTMICR, 0);
      IntEnable(INT_TIMER0A);
      callbackFunc = config->callBackFunc;
    }
  }else if(config->counterSize == TIMER_SIZE_16_32_16CONFIGURATION || config->counterSize == TIMER_SIZE_32_64_32CONFIGURATION){
    TIMERx->GPTMCFG |= config->counterSize;
    
    if(config->timerAlpha == TIMER_ALPHA_A){
      TIMERx->GPTMTAMR |= config->mode;
      if(config->mode == TIMER_MODE_CAPTURE_EDGE_TIME){
        TIMERx->GPTMCTL |= config->captureEdge;
      }
      TIMERx->GPTMTAMR |= config->countDirection;
    } else if(config->timerAlpha == TIMER_ALPHA_B){
      TIMERx->GPTMTBMR |= config->mode;
      TIMERx->GPTMTBMR |= config->countDirection;
    }
    
  }

  
  MCAL_TIMER_Enable(TIMERx, config->timerAlpha);
}



void MCAL_TIMERA_DelayMs_P(timer_typedef * TIMERx, uint32 delay){
  CLEAR_BIT(TIMERx->GPTMCTL, 0);                        //Disable timer
  SET_BIT(TIMERx->GPTMICR, 0);                          //Clear interrupt flag
  TIMERx->GPTMTAILR = (delay * CPU_CLOCK_MS) - 1;       //Setting delay
  SET_BIT(TIMERx->GPTMCTL, 0);                          //Enabling Timer
  while(READ_BIT(TIMERx->GPTMRIS, 0) == 0);             //Busy wait
}

void MCAL_TIMERB_DelayMs_P(timer_typedef * TIMERx, uint32 delay){
  CLEAR_BIT(TIMERx->GPTMCTL, 8);                        //Disable timer
  SET_BIT(TIMERx->GPTMICR, 8);                          //Clear interrupt flag
  TIMERx->GPTMTAILR = (delay * CPU_CLOCK_MS) - 1;       //Setting delay
  SET_BIT(TIMERx->GPTMCTL, 8);                          //Enabling delay
  while(READ_BIT(TIMERx->GPTMRIS, 8) == 0);             //Busy wait
}

void MCAL_TIMER_DelayMs(timer_typedef * TIMERx, uint32 delay){
  CLEAR_BIT(TIMERx->GPTMCTL, 0);                        //Disable timer
  SET_BIT(TIMERx->GPTMICR, 0);                          //Clear interrupt flag
  TIMERx->GPTMTAILR = (delay * CPU_CLOCK_MS) - 1;       //Setting delay
  SET_BIT(TIMERx->GPTMCTL, 0);                          //Enabling Timer
}

void MCAL_TIMERA_Delay_MicroSecond_P(timer_typedef * TIMERx, uint32 delay){
  uint32 i;
  
  CLEAR_BIT(TIMERx->GPTMCTL, 0);                        //Disable timer
  SET_BIT(TIMERx->GPTMICR, 0);                          //Clear interrupt flag
  TIMERx->GPTMTAILR = 15;                               //Setting delay of one microsecond
  SET_BIT(TIMERx->GPTMCTL, 0);                          //Enabling Timer
  
  for(i = 0; i < delay; i++){
    while(READ_BIT(TIMERx->GPTMRIS, 0) == 0);
    SET_BIT(TIMERx->GPTMICR, 0);
  }
}


uint32 MCAL_TIMER_Measure_Capture_Time(vuint32_ptr writePort, uint8 writePIN, vuint32_ptr readPort, uint8 readPIN,
                                       timer_typedef * delay, timer_typedef * capture){
  uint32 lastEdge, thisEdge;
  uint8 pinData;
  
  /*Giving a 10 us trigger pulse*/
  MCAL_GPIO_WritePin(writePort, writePIN, LOW);         /*Making the pin low*/
  MCAL_TIMERA_Delay_MicroSecond_P(delay, 10);           /*10 microseconds delay*/
  MCAL_GPIO_WritePin(writePort, writePIN, HIGH);        /*Making the pin high*/
  MCAL_TIMERA_Delay_MicroSecond_P(delay, 10);           /*10 microseconds delay*/
  MCAL_GPIO_WritePin(writePort, writePIN, LOW);         /*Making the pin low*/
  
  while(1){
    capture->GPTMICR = 0x4;                             /*Clearing the capture flag*/
    while((capture->GPTMRIS & 0x4) == 0);               /*Wait till flag is captured*/
    MCAL_GPIO_ReadPin(readPort, readPIN, &pinData);     /*Reading pin and checking if rising edge detected*/
    if(pinData){
      /*Detecting falling edge*/
      lastEdge = capture->GPTMTAR;                      /*Saving the timestamp of the rising edge*/
      capture->GPTMICR = 0x4;                           /*Clearing the capture flag*/
      while((capture->GPTMRIS & 0x4) == 0);             /*Wait till flag is captured*/
      thisEdge = capture->GPTMTAR;                      /*Saving the timestamp of the falling edge*/
      return thisEdge - lastEdge;                       /*The difference between the falling and the rising 
                                                        will give the pulse time size*/
    }
  }
  
}


void TIMER0A_Handler(void){
  SET_BIT(TIMER0->GPTMICR, 0);
  callbackFunc();
}