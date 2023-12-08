#ifndef _GPIO_H_
#define _GPIO_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"

//--------------------------------
//Macros Configuration References
//--------------------------------

typedef struct{
  uint8 pinNumber;      /*For initializing the needed pin must be configured from @ref pinNumber*/
  
  uint8 direction;      /*For initializing the dircetion of the pin must be configured from @ref direction*/
  
  uint8 outputMode;     /*Configuring mode when in output mode must be configured from @ref output_modes*/
  
  uint8 outputSpeed;    /*Configuring speed when in output mode must be configured from @ref output_speeds*/
  
  uint8 alterFunc;      /*Configures pin for its alternative function must be configured from @ref alternative_function*/
}pin_config_t;

//@ref portNumber
#define PORTA					((uint8)0x01) 
#define PORTB					((uint8)0x02) 
#define PORTC					((uint8)0x04) 
#define PORTD					((uint8)0x08) 
#define PORTE					((uint8)0x10) 
#define PORTF					((uint8)0x20)

//@ref pinNumber
#define PIN_0					((uint8)0x01) // Pin 0 with shifting
#define PIN_1					((uint8)0x02) // Pin 1 with shifting
#define PIN_2					((uint8)0x04) // Pin 2 with shifting
#define PIN_3					((uint8)0x08) // Pin 3 with shifting
#define PIN_4					((uint8)0x10) // Pin 4 with shifting
#define PIN_5					((uint8)0x20) // Pin 5 with shifting
#define PIN_6					((uint8)0x40) // Pin 6 with shifting
#define PIN_7					((uint8)0x80) // Pin 7 with shifting

//@ref direction
#define MCAL_GPIO_DIRECTION_INPUT                    ((uint8)0x0)
#define MCAL_GPIO_DIRECTION_OUTPUT                   ((uint8)0x1)

//@ref output_modes
#define MCAL_GPIO_OUTPUT_MODE_NONE                   ((uint8)0x0)
#define MCAL_GPIO_OUTPUT_MODE_OPEN_DRAIN             ((uint8)0x1)
#define MCAL_GPIO_OUTPUT_MODE_PULL_UP                ((uint8)0x2)
#define MCAL_GPIO_OUTPUT_MODE_PULL_DOWN              ((uint8)0x3)

//@ref output_speeds
#define MCAL_GPIO_OUTPUT_SPEED_NONE                  ((uint8)0x0)
#define MCAL_GPIO_OUTPUT_SPEED_2mA_DRIVE             ((uint8)0x1)
#define MCAL_GPIO_OUTPUT_SPEED_4mA_DRIVE             ((uint8)0x2)
#define MCAL_GPIO_OUTPUT_SPEED_8mA_DRIVE             ((uint8)0x3)

//@ref alternative_function
#define MCAL_GPIO_ALTERFUNC_NONE                     ((uint8)0x0)
#define MCAL_GPIO_ALTERFUNC_UART0                    ((uint8)0x1)
#define MCAL_GPIO_ALTERFUNC_SSI0                     ((uint8)0x2)
#define MCAL_GPIO_ALTERFUNC_I2C0                     ((uint8)0x3)




//@ref value
#define LOW					        0
#define HIGH					        1

/* 
 * 
 *@ref GPIO :
 * GPIOA
 * GPIOB
 * GPIOC
 * GPIOD
 * GPIOE
 * GPIOF
 * 
 */


//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL GPIO Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_GPIO_Init
*
* Description  : This function initialize the clock of the GPIO
*
* PARAMETER 1 : The port which you want to initialize
*
* PARAMETER 2 : The port mask you want to initialize
* 
* Return Value : None
*
* Note!!!     : In parameter 1 and 2 must be from @ref GPIO, 
@ref portNumber Respectively
******************************************************************************/
void MCAL_GPIO_Init(vuint32_ptr PORTx, uint8 portNumber);


/****************************************************************************
* Function Name : MCAL_GPIO_Pin_Init
*
* Description   : This function initialize a pin
*
* PARAMETER 1   : The port on which the pin is located
*
* PARAMETER 2   : The configuration of the pin
* 
* Return Value  : None
*
* Note          : In parameter 1 must be from @ref GPIO
******************************************************************************/
void MCAL_GPIO_Pin_Init(vuint32_ptr PORTx, pin_config_t * config);


/****************************************************************************
* Function Name: MCAL_GPIO_WritePin
*
* Description  : This function writes on a specific pin according to the input
*
* PARAMETER 1  : The port on which the pin is located
*
* PARAMETER 2  : The pin to which to be written on
*
* PARAMETER 3  : The data which to be written on the pin
*
* Return Value : None
*
* Note!!!      : In parameter 1,2,3 must be from @ref GPIO, @ref pinNumber, 
* @ref value Respectively 
******************************************************************************/
void MCAL_GPIO_WritePin(vuint32_ptr PORTx, uint8 PINx, uint8 value);



/****************************************************************************
* Function Name: MCAL_GPIO_WritePort
*
* Description  : This function writes on the whole port according to the value
*
* PARAMETER 1  : The port to which to be written on
*
* PARAMETER 2  : The data which to be written on the port
*
* Return Value : None
*
* Note!!!      : In parameter 1,2 must be from @ref GPIO, @ref value
* Respectively 
******************************************************************************/
void MCAL_GPIO_WritePort(vuint32_ptr PORTx, uint8 value);



/****************************************************************************
* Function Name: MCAL_GPIO_TogglePin
*
* Description  : This function toggles a specific pin according to the input
*
* PARAMETER 1  : The port on which the pin is located
*
* PARAMETER 2  : The pin to which to be toggled
*
* Return Value : None
*
* Note!!!      : In parameter 1,2 must be from @ref GPIO, @ref pinNumber
* Respectively 
******************************************************************************/
void MCAL_GPIO_TogglePin(vuint32_ptr PORTx, uint8 PINx);



/****************************************************************************
* Function Name: MCAL_GPIO_ReadPin
*
* Description  : This function reads data from a specific pin according to the input
*
* PARAMETER 1  : The port on which the pin is located
*
* PARAMETER 2  : The pin to which to be read from
*
* PARAMETER 3  : The data which will be take the value from the pin
*
* Return Value : Returns indirectly the value of the pin in the third parameter
*
* Note!!!      : In parameter 1,2,3 must be from @ref GPIO, @ref pinNumber, 
* @ref value Respectively 
******************************************************************************/
void MCAL_GPIO_ReadPin(vuint32_ptr PORTx, uint8 PINx, uint8 *value);



/****************************************************************************
* Function Name: MCAL_GPIO_ReadPort
*
* Description  : This function reads from whole port according to the input
*
* PARAMETER 1  : The port to which the data will be read from
*
* PARAMETER 2  : The data which will have the value from the port
*
* Return Value : Returns indirectly the value of the port in the second parameter
*
* Note!!!      :  Parameter 1 must be from @ref GPIO
******************************************************************************/
void MCAL_GPIO_ReadPort(vuint32_ptr PORTx, uint8 *value);

#endif /* _GPIO_H_ */