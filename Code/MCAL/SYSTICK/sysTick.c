#include "sysTick.h"

void (*calbackFunction)(void);

void MCAL_SYSTICK_Disable(void){
  CLEAR_BIT(SYSTICK_STCTRL_R,0);
}

void MCAL_SYSTICK_Enable(void){
  SET_BIT(SYSTICK_STCTRL_R,2);
  SET_BIT(SYSTICK_STCTRL_R,0);
}

void MCAL_SYSTICK_EnableInterrupt(void (*func)(void)){
  SET_BIT(SYSTICK_STCTRL_R,1);
  calbackFunction = func;
}

uint32 MCAL_SYSTICK_PeriodGet(void){
  return SYSTICK_STRELOAD_R & 0xFFFFFF;
}

void MCAL_SYSTICK_PeriodSet(uint32 period){
  SYSTICK_STRELOAD_R = (period & 0xFFFFFF);
}
uint32 MCAL_SYSTICK_ValueGet(void){
  return SYSTICK_STCURRENT_R & 0xFFFFFF;
}

boolean MCAL_SYSTICK_Is_Time_out(void){
  return READ_BIT(SYSTICK_STCTRL_R,16);
}

void MCAL_SYSTICK_delayMs(uint16 delay){
  MCAL_SYSTICK_Disable();
  MCAL_SYSTICK_PeriodSet(((delay)*(SYSTEM_CLK_4)) - 1);
  SYSTICK_STCURRENT_R = 0;
  MCAL_SYSTICK_Enable();
}

void SysTick_Handler(void){
  calbackFunction();
}