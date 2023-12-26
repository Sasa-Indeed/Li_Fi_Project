#ifndef _SMOKE_SENSOR_H_
#define _SMOKE_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"
//Deleted systick

//--------------------------------
//Macros Configuration References
//--------------------------------
#define SMOKE_SENSOR_PORT                               GPIOA
#define SMOKE_SENSOR_PORT_NUMBER                        PORTA
#define SMOKE_SENSOR_PIN                                PIN_7

//For Interrupt
#define SMOKE_SENSOR_PIN_INT                            GPIO_INT_PIN_7
#define SMOKE_SENSOR_GPIO_INT                           GPIO_PORTA_BASE // For Clearing interrupt



//------------------------------------------------------------------------------------------
//			APIs supported by "HAL SMOKE SENSOR Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_SMOKE_SENSOR_Init
*
* Description  : This function initializes the smoke sensor
*
* PARAMETER1   : The call back for when the sensors detects smoke
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_SMOKE_SENSOR_Init(void (* callBack)(void));


/****************************************************************************
* Function Name: HAL_SMOKE_SENSOR_Read
*
* Description  : This function reads the value of the Smoke sensor
*
* PARAMETERS   : None
* 
* Return Value : Returns HIGH if there is no smoke detected otherwise LOW
*
* Note!!!     : None
******************************************************************************/
uint8 HAL_SMOKE_SENSOR_Read(void);


/****************************************************************************
* Function Name: HAL_SMOKE_SENSOR_Off
*
* Description  : This function turns off the sensor
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_SMOKE_SENSOR_Off(void);


/****************************************************************************
* Function Name: HAL_SMOKE_SENSOR_On
*
* Description  : This function turns on the sensor
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_SMOKE_SENSOR_On(void);

#endif /* _SMOKE_SENSOR_H_ */