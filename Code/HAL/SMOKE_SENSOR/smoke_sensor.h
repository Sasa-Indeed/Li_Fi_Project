#ifndef _SMOKE_SENSOR_H_
#define _SMOKE_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define SMOKE_SENSOR_PORT                               GPIOF
#define SMOKE_SENSOR_PORT_NUMBER                        PORTF
#define SMOKE_SENSOR_PIN                                PIN_2


//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL SMOKE SENSOR Driver"
//------------------------------------------------------------------------------------------
void HAL_SMOKE_SENSOR_Init(void);
uint8 HAL_SMOKE_SENSOR_Read(void);




#endif /* _SMOKE_SENSOR_H_ */