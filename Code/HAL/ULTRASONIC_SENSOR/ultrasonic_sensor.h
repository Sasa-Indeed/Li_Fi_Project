#ifndef _ULTRASONIC_SENSOR_H_
#define _ULTRASONIC_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/TIMER/timer.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define ECHO_PORT                       GPIOB
#define ECHO_PORT_NUMBER                PORTB
#define ECHO_PIN                        PIN_6

#define TRIGGER_PORT                    GPIOB
#define TRIGGER_PORT_NUMBER             PORTB
#define TRIGGER_PIN                     PIN_2

#define CAPTURE_TIMER                   TIMER0
#define DELAY_TIMER                     TIMER1


//------------------------------------------------------------------------------------------
//			APIs supported by "HAL ULTRASONIC SENSOR Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: HAL_ULTRASONIC_SENSOR_Init
*
* Description  : This function initializes the ultrasonic sensor
*
* PARAMETERS   : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void HAL_ULTRASONIC_SENSOR_Init(void);


/****************************************************************************
* Function Name: HAL_ULTRASONIC_Measure_Distance
*
* Description  : This function measures the distance of the objects in front of the sensor
*
* PARAMETERS   : None
* 
* Return Value : Returns the distance in (cm)
*
* Note!!!     : None
******************************************************************************/
uint32 HAL_ULTRASONIC_Measure_Distance(void);





#endif /* _ULTRASONIC_SENSOR_H_ */