#ifndef _SMOKE_SENSOR_H_
#define _SMOKE_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/SYSTICK/sysTick.h"


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
void HAL_SMOKE_SENSOR_Init(void (* callBack)(void));

uint8 HAL_SMOKE_SENSOR_Read(void);

void HAL_SMOKE_SENSOR_Off(void);

void HAL_SMOKE_SENSOR_On(void);


#endif /* _SMOKE_SENSOR_H_ */