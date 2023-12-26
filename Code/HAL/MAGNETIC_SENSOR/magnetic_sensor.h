#ifndef _MAGNETIC_SENSOR_H_
#define _MAGNETIC_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define MAGNETIC_SENSOR_PORT                               GPIOB
#define MAGNETIC_SENSOR_PORT_NUMBER                        PORTB
#define MAGNETIC_SENSOR_PIN                                PIN_5

//For interrupt
#define MAGNETIC_SENSOR_PIN_INT                            GPIO_INT_PIN_5
#define MAGNETIC_SENSOR_GPIO_INT                           GPIO_PORTB_BASE  // For Clearing interrupt



//------------------------------------------------------------------------------------------
//			APIs supported by "HAL MAGNETIC SENSOR Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_MAGNETIC_SENSOR_Init
*
* Description  : This function initializes the magnetic sensor
*
* PARAMETER1   : The call back for when the sensors detects it was opened
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_MAGNETIC_SENSOR_Init(void (* callBack)(void));


/****************************************************************************
* Function Name: HAL_MAGNETIC_SENSOR_Read
*
* Description  : This function reads the value of the magnetic sensor
*
* PARAMETERS   : None
* 
* Return Value : Returns HIGH if the door was still closed otherwise LOW
*
* Note!!!     : None
******************************************************************************/
uint8 HAL_MAGNETIC_SENSOR_Read(void);


/****************************************************************************
* Function Name: HAL_MAGNETIC_SENSOR_Off
*
* Description  : This function turns off the sensor
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_MAGNETIC_SENSOR_Off(void);


/****************************************************************************
* Function Name: HAL_MAGNETIC_SENSOR_On
*
* Description  : This function turns on the sensor
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_MAGNETIC_SENSOR_On(void);


#endif /* _MAGNETIC_SENSOR_H_ */