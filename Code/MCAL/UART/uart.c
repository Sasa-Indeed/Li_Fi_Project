#include "uart.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

void MCAL_UART_Init(void){
  
  //Enabling the pins
  pin_config_t pconfig;

  MCAL_GPIO_Init(GPIOA, PORTA);
  
  pconfig.pinNumber = PIN_0;
  pconfig.alterFunc = MCAL_GPIO_ALTERFUNC_UART0;
  pconfig.alterFuncIO = MCAL_GPIO_ALTERFUNCIO_DISABLE;
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
  
void MCAL_UART_Init1(void){
  
  //
  // Enable the GPIOB peripheral
  //
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  //
  // Wait for the GPIOB module to be ready.
  //
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
  //
  // Configure GPIO Port B pins 0 and 1 to be used as UART1.
  //
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  //
  // Enable UART1 functionality on GPIO Port B pins 0 and 1.
  //
  GPIOPinConfigure(GPIO_PB0_U1RX);
  GPIOPinConfigure(GPIO_PB1_U1TX);
   
  
  SET_BIT(SYSCTL_RCGCUART_R, 1);
  //2. Busy wait until port is ready
  while((SYSCTL_PRUART_R & 0x2) == 0);
  
  CLEAR_BIT(UART1_CTL_R, 0);
  
  /* Baud rate
   * BRD = 16,000,000 / (16 * 9600) = 104.166666666667
   * UARTFBRD{DIVFRAC} = integer(0.166667 * 64 +0.5) = 11*/
  //Integer part
  UART1_IBRD_R = 104;
  //Fraction Part
  UART1_FBRD_R = 11;
  
  //Enabling 8-bit data lenght
  UART1_LCRH_R = (0x3 << 5);
  
  //Using system clock
  UART1_CC_R = 0x0;
  
  //Enabling uart and configuring it for TX & RX
  UART1_CTL_R |= (1<<0) | (1<<8) | (1<<9);
}


uint8 MCAL_UART_ReadChar(void){
  uint8 data;
  while(READ_BIT(UART0_FR_R, 4) != 0);
  data = UART0_DR_R;
  return data;
}

void MCAL_UART_PrintChar(uint8 data){
  while(READ_BIT(UART0_FR_R, 5) != 0);
  UART0_DR_R = data;
}

void MCAL_UART_PrintString(uint8_ptr string){
  uint8_ptr st = string;
  while(*st){
    MCAL_UART_PrintChar(*(st++));
  }
}

uint8 MCAL_UART_ReadChar1(void){
  uint8 data;
  while(READ_BIT(UART1_FR_R, 4) != 0);
  data = UART1_DR_R;
  return data;
}

void MCAL_UART_PrintChar1(uint8 data){
  while(READ_BIT(UART1_FR_R, 5) != 0);
  UART1_DR_R = data;
}

void MCAL_UART_PrintString1(uint8_ptr string){
  uint8_ptr st = string;
  while(*st){
    MCAL_UART_PrintChar1(*(st++));
  }
}