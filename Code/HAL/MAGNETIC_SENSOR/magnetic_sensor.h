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
#define MAGNETIC_SENSOR_PIN_INT                            GPIO_INT_PIN_5




//------------------------------------------------------------------------------------------
//			APIs supported by "HAL MAGNETIC SENSOR Driver"
//------------------------------------------------------------------------------------------
void HAL_MAGNETIC_SENSOR_Init(void (* callBack)(void));
uint8 HAL_MAGNETIC_SENSOR_Read(void);




#endif /* _MAGNETIC_SENSOR_H_ */