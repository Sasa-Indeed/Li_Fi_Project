#ifndef _ULTRASONIC_SENSOR_H_
#define _ULTRASONIC_SENSOR_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../../MCAL/GPIO/gpio.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define ECHO_PORT                       GPIOB
#define ECHO_PORT_NUMBER                PORTB
#define ECHO_PIN                        PIN_6

#define TRIGGER_PORT                    GPIOB
#define TRIGGER_PORT_NUMBER             PORTB
#define TRIGGER_PIN                     PIN_2





//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL ULTRASONIC SENSOR Driver"
//------------------------------------------------------------------------------------------
uint32_t Measure_distance(void);





#endif /* _ULTRASONIC_SENSOR_H_ */