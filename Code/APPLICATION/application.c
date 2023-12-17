#include "application.h"

void Smoke_Alarm(void);
void Door_Alarm(void);
void Proximity_Alarm(void);

void Application_Init(void){
  HAL_SMOKE_SENSOR_Init(Smoke_Alarm);
  HAL_BLUETOOTH_Init();
  HAL_ULTRASONIC_SENSOR_Init();
  HAL_MAGNETIC_SENSOR_Init(Door_Alarm);
  HAL_LI_FI_Init();
  HAL_Button_Init();
  
}


void Application_Main_Logic(void){

}


void Smoke_Alarm(void){
  HAL_LI_FI_Smoke_Message();
  HAL_BLUETOOTH_Send_Message("System Alarm:\nSMOKE DETECTED!");
}
void Door_Alarm(void){
  HAL_LI_FI_Door_Message();
  HAL_BLUETOOTH_Send_Message("System Alarm:\nDOOR WAS OPENED!");
}

void Proximity_Alarm(void){
  HAL_LI_FI_Ultrasonic_Message();
  HAL_BLUETOOTH_Send_Message("System Alarm:\nPROXIMITY ALERT!");
}
