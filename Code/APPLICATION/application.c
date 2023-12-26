#include "application.h"

#define DISTANCE_THRESHOLD      10

void Smoke_Alarm(void);
void Door_Alarm(void);
void Proximity_Alarm(void);
void Start_Button(void);

vuint8 stop = HIGH , start = LOW;

void Application_Init(void){
  HAL_SMOKE_SENSOR_Init(Smoke_Alarm);
  HAL_BLUETOOTH_Init();
  HAL_ULTRASONIC_SENSOR_Init();
  HAL_MAGNETIC_SENSOR_Init(Door_Alarm);
  HAL_LI_FI_Init();
  HAL_Button_Init(Start_Button);  
}

/*
 * SWT2 is the stop button
 * SWT1 is the start button
 */
void Application_Main_Logic(void){
  uint8 initalFlag = HIGH, read;
  uint32 distance;
  
  while(1){
    HAL_Button_Read(STOP_BUTTON, &read);
    stop = read;
    
    if(stop == HIGH || initalFlag == HIGH){ //Shutting of the system
      initalFlag = LOW;
      start = LOW;
      HAL_SMOKE_SENSOR_Off();
      HAL_MAGNETIC_SENSOR_Off();
      HAL_LI_FI_System_Off_Message();
      HAL_BLUETOOTH_Send_Message("\n   System is\n    Offline");
    }else if (start == HIGH){
      distance = HAL_ULTRASONIC_Measure_Distance();
      if(distance <= DISTANCE_THRESHOLD){
        Proximity_Alarm();
      }
      MCAL_SYSTICK_delayMs_P(1000);
    }
  }
}

void Start_Button(void){
  GPIOIntClear(BUTTON_START_GPIO_INT, BUTTON_START_PIN_INT);
  stop = LOW;
  start = HIGH;
  HAL_LI_FI_System_On_Message();
  HAL_SMOKE_SENSOR_On();
  HAL_MAGNETIC_SENSOR_On();
  HAL_BLUETOOTH_Send_Message("\n   System is\n     Online");
}

void Smoke_Alarm(void){
  uint8 i = 3;

  GPIOIntClear(SMOKE_SENSOR_GPIO_INT, SMOKE_SENSOR_PIN_INT);
  HAL_LI_FI_Smoke_Message();
  HAL_BLUETOOTH_Send_Message("\n  System Alarm \nSMOKE DETECTED! ");
  
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
}
void Door_Alarm(void){
   uint8 i = 3;

  GPIOIntClear(MAGNETIC_SENSOR_GPIO_INT, MAGNETIC_SENSOR_PIN_INT);
  HAL_LI_FI_Door_Message();
  HAL_BLUETOOTH_Send_Message("\n  System Alarm\nDOOR WAS OPENED! ");
  
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
}

void Proximity_Alarm(void){
   uint8 i = 3;

  HAL_LI_FI_Ultrasonic_Message();
  HAL_BLUETOOTH_Send_Message("\n  System Alarm\nPROXIMITY ALERT! ");
  
  while(i){
    MCAL_SYSTICK_delayMs_P(1000);
    i--;
  }
}
