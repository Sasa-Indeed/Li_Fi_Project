#ifndef _UART_H_
#define _UART_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../GPIO/gpio.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
typedef struct{
  uint8 		USART_mode;     /* Specifies the TX/RX mode.
                                         * This parameter must be set based on @ref USART_mode_define*/

  uint32 		baud_rate;      /* This configures the USART  baud rate
                                         * This parameter must be set based on @ref USART_baud_rate_define*/

  uint8 		data_lenght;    /* Specifies the number of data bits transmitted or received in a frame.
                                         * This parameter must be set based on @ref USART_data_Length_define */

  uint8 		parity;	        /* Specifies the parity mode.
                                         * This parameter must be set based on @ref USART_Parity_define*/

  uint8 		stop_bits;      /* Specifies the number of stop bits transmitted
                                         * This parameter must be set based on @ref USART_Stop_Bits_define*/

  uint8 		IRQ_enable;     /* Enable or disable UART IRQ TX/RX
                                         * This parameter must be set based on @ref USART_IRQ_Enable_define*/

  void(* p_IRQ_callback)(void);         /* The C Function() which will be called once the IRQ happen*/

}uart_config_t;




//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL UART Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_UART_Init
*
* Description  : This function disables the timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_UART0_Init(void);

uint8 MCAL_UART0_ReadChar(void);

void MCAL_UART0_PrintChar(uint8 data);

void MCAL_UART0_PrintString(uint8_ptr string);

void MCAL_UART1_Init(void);

uint8 MCAL_UART1_ReadChar(void);

void MCAL_UART1_PrintChar(uint8 data);

void MCAL_UART1_PrintString(uint8_ptr string);





#endif /* _UART_H_ */