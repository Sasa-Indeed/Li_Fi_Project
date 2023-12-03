#include "sysTick.h"

void (*interruptFunc)(void);

void MCAL_SysTickDisable(void){
  CLEAR_BIT(SYSTICK_STCTRL_R,0);
}

void MCAL_SysTickEnable(void){
  SET_BIT(SYSTICK_STCTRL_R,0);
}

void MCAL_SysTickEnableInterrupt(void (*func)(void)){
  SET_BIT(SYSTICK_STCTRL_R,1);
}

uint32 MCAL_SysTickPeriodGet(void){
  return SYSTICK_STRELOAD_R & 0xFFFFFF;
}

void MCAL_SysTickPeriodSet(uint32 period){
  SYSTICK_STRELOAD_R = (period & 0xFFFFFF);
}
uint32 MCAL_SysTickValueGet(void){
  return SYSTICK_STCURRENT_R & 0xFFFFFF;
}

boolean MCAL_SysTick_Is_Time_out(void){
  return READ_BIT(SYSTICK_STCTRL_R,16);
}

void MCAL_SYSTICK_delayMs(uint16 delay){
  MCAL_SysTickDisable();
  MCAL_SysTickPeriodSet((delay/1000)/(1/SYSTEM_CLK) - 1);
  SYSTICK_STCURRENT_R = 0;
  MCAL_SysTickEnable();
  do{
    MCAL_SysTickValueGet();
  }while(MCAL_SysTick_Is_Time_out()!= 1);
}

void SysTick_Handler(void){
  interruptFunc();
}