#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../INC/types.h"
#include "../HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "../HAL/MAGNETIC_SENSOR/magnetic_sensor.h"
#include "../HAL/SMOKE_SENSOR/smoke_sensor.h"
#include "../HAL/LI-FI/li-fi.h"
#include "../HAL/BLUETOOTH/bluetooth.h"
#include "../HAL/BUTTON/button.h"




//------------------------------------------------------------------------------------------
//			APIs supported by "APPLICATION Driver"
//------------------------------------------------------------------------------------------
void Application_Init(void);
void Application_Main_Logic(void);




#endif /* _APPLICATION_H_ */