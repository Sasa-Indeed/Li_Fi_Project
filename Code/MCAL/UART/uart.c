#include "uart.h"

void MCAL_UART_Init(uart_config_t * config){
  
  //Enabling the pins
  pin_config_t pconfig;

  MCAL_GPIO_Init(GPIOA, PORTA);
  
  pconfig.pinNumber = PIN_0;
  pconfig.alterFunc = MCAL_GPIO_ALTERFUNC_UART0;
  MCAL_GPIO_Pin_Init(GPIOA, &pconfig);
  
  pconfig.pinNumber = PIN_1;
  MCAL_GPIO_Pin_Init(GPIOA, &pconfig);
  
  SET_BIT(SYSCTL_RCGCUART_R, 0);
   
  //2. Busy wait until port is ready
  while((SYSCTL_PRUART_R & 0x1) == 0);
  
  CLEAR_BIT(UART0_CTL_R, 0);
  
  /* Baud rate
   * BRD = 16,000,000 / (16 * 9600) = 104.166666666667
   * UARTFBRD{DIVFRAC} = integer(0.166667 * 64 +0.5) = 11*/
  //Integer part
  UART0_IBRD_R = 104;
  //Fraction Part
  UART0_FBRD_R = 11;
  
  //Enabling 8-bit data lenght
  UART0_LCRH_R = (0x3 << 5);
  
  //Using system clock
  UART0_CC_R = 0x0;
  
  //Enabling uart and configuring it for TX & RX
  UART0_CTL_R |= (1<<0) | (1<<8) | (1<<9);
}