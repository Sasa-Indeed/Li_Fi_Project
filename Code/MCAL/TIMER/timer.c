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


void TIMER0A_Handler(void){
  SET_BIT(TIMER0->GPTMICR, 0);
  callbackFunc();
}