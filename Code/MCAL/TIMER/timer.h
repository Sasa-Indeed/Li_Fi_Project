#ifndef _TIMER_H_
#define _TIMER_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"
#include "../GPIO/gpio.h"

//--------------------------------
//Macros Configuration References
//--------------------------------
#define CPU_CLOCK_MS                    16000U               



typedef struct{
  uint8 timerAlpha;            //@ref Timer Alpha
  uint8 mode;                   //@ref Mode
  uint8 timerUse;
  uint8 countDirection;         //@ ref count Direction
  uint8 counterSize;            // @ref Counter Size
  uint8 timeNumber;              // @ref Timer Number
  uint8 timerWidth;              //@ref  Timer width
  uint8 prescalerSize;
  uint8 enableInterrupt;         //@ref Timer enale
  uint8 captureEdge;             //@ref Capture Edge
  void (* callBackFunc)(void); 
}timer_config;

// @ref Timer Alpha
#define TIMER_ALPHA_A                                   0X0
#define TIMER_ALPHA_B                                   0X1

//Counter Size
#define TIMER_SIZE_16_32_32CONFIGURATION                0x0
#define TIMER_SIZE_32_64_64CONFIGURATION                0x0
#define TIMER_SIZE_16_32_32RTC_CONFIGURATION            0x1
#define TIMER_SIZE_32_64_64RTC_CONFIGURATION            0x1
#define TIMER_SIZE_16_32_16CONFIGURATION                0x4
#define TIMER_SIZE_32_64_32CONFIGURATION                0x4



//Timer width
#define TIMER_WIDTH_16_32                               0x0
#define TIMER_WIDTH_32_64                               0x1


// @ref Timer Number
#define TIMER_NUMBER_0                                  0x0
#define TIMER_NUMBER_1                                  0x1
#define TIMER_NUMBER_2                                  0x2
#define TIMER_NUMBER_3                                  0x3
#define TIMER_NUMBER_4                                  0x4
#define TIMER_NUMBER_5                                  0x5

//@ref mode 
#define TIMER_MODE_RESERVED                             0X0
#define TIMER_MODE_ONE_SHOT                             0x1
#define TIMER_MODE_PERIODIC                             0x2
#define TIMER_MODE_CAPTURE_EDGE_COUNT                   0x3
#define TIMER_MODE_CAPTURE_EDGE_TIME                    0x7 


//@ ref count Direction
#define TIMER_COUNT_DIRECTION_DOWN                      0x0
#define TIMER_COUNT_DIRECTION_UP                        0x10

//@ref Timer enale
#define TIMER_INTERRUPT_ENABLE_NONE                     0x0
#define TIMER_INTERRUPT_ENABLE_A                        0x1
#define TIMER_INTERRUPT_ENABLE_B                        0x100

//@ref Capture Edge
#define TIMER_CAPTURE_EDGE_POSTIVE                      0x0
#define TIMER_CAPTURE_EDGE_NEGATIVE                     0x4
#define TIMER_CAPTURE_EDGE_BOTH                         0xC


/* @ref Timer Peripheral Instants 
 * TIMER0 
 * TIMER1                      
 * TIMER2         
 * TIMER3  
 * TIMER4 
 * TIMER5   
 * WTIMER0          
 * WTIMER1 
 * WTIMER2 
 * WTIMER3
 * WTIMER4
 * WTIMER5
 */


//------------------------------------------------------------------------------------------
//			APIs supported by "MCAL sysTick Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_TIMER_Disable
*
* Description  : This function disables the timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_TIMER_Disable(timer_typedef * TIMERx, uint8 timerAlpha);


/****************************************************************************
* Function Name: MCAL_TIMER_Enable
*
* Description  : This function enables the timer
*
* PARAMETERS : None
* 
* Return Value : None
*
* Note!!!     : None
******************************************************************************/
void MCAL_TIMER_Enable(timer_typedef * TIMERx, uint8 timerAlpha);


/****************************************************************************
* Function Name: MCAL_TIMER_Init
*
* Description  : This function initializes the timer
*
* PARAMETER1 : The timer you want to initialize
*
* PARAMETER2 : The configuration for the timer you want to initialize
* 
* Return Value : None
*
* Note!!!     : Parameter 1 must be from Timer Peripheral Instants 
******************************************************************************/
void MCAL_TIMER_Init(timer_typedef * TIMERx, timer_config* config);



/****************************************************************************
* Function Name: MCAL_TIMERA_DelayMs_P
*
* Description  : This function makes a polling delay for subtimer A
*
* PARAMETER1 : The timer you want to use for delay
*
* PARAMETER2 : The delay you want in  ms (miliseconds)
* 
* Return Value : None
*
* Note!!!     : Parameter 1 must be from Timer Peripheral Instants, for
this function to work proprely you must configure the timer to be periodic or one shot 
******************************************************************************/
void MCAL_TIMERA_DelayMs_P(timer_typedef * TIMERx, uint32 delay);



/****************************************************************************
* Function Name: MCAL_TIMERB_DelayMs_P
*
* Description  : This function makes a polling delay for subtimer B
*
* PARAMETER1 : The timer you want to use for delay
*
* PARAMETER2 : The delay you want in  ms (miliseconds)
* 
* Return Value : None
*
* Note!!!     : Parameter 1 must be from Timer Peripheral Instants, for
this function to work proprely you must configure the timer to be periodic or one shot 
******************************************************************************/
void MCAL_TIMERB_DelayMs_P(timer_typedef * TIMERx, uint32 delay);



/****************************************************************************
* Function Name: MCAL_TIMER_DelayMs
*
* Description  : This function sets up a delay for the timer for using interrupt
*
* PARAMETER1 : The timer you want to use for delay
*
* PARAMETER2 : The delay you want in  ms (miliseconds)
* 
* Return Value : None
*
* Note!!!     : Parameter 1 must be from Timer Peripheral Instants, for
this function to work proprely you must configure the timer to be periodic or one shot,
it it important to add the callback function in initialization otherwise it will lead to busfault 
******************************************************************************/
void MCAL_TIMER_DelayMs(timer_typedef * TIMERx, uint32 delay);



/****************************************************************************
* Function Name: MCAL_TIMERA_Delay_MicroSecond_P
*
* Description  : This function makes a polling delay for subtimer A
*
* PARAMETER1 : The timer you want to use for delay
*
* PARAMETER2 : The delay you want in  us (microseconds)
* 
* Return Value : None
*
* Note!!!     : Parameter 1 must be from Timer Peripheral Instants, for
this function to work proprely you must configure the timer to be periodic or one shot 
******************************************************************************/
void MCAL_TIMERA_Delay_MicroSecond_P(timer_typedef * TIMERx,uint32 delay);



/****************************************************************************
* Function Name: MCAL_TIMER_Measure_Capture_Time
*
* Description  : This function mostly used with a ultrasonic sensors for measuring
* the time taken of the echo pulse 
*
* PARAMETER1 : The Port to use for the tirgger pin
*
* PARAMETER2 : The Pin of the trigger pin
*
* PARAMETER3 : The Port to use for the echo pin
*
* PARAMETER4 : The Pin of the echo pin
*
* PARAMETER5 : The timer used for the delay
*
* PARAMETER6 : The timer used for capture mode
* 
* Return Value : None
*
* Note!!!     : Parameter 1 & 3 must be from @ref GPIO, parameter 2 & 4 must be 
from @ref pinNumber, and parameter 5 & 6 must be from @ref Timer Peripheral Instants
******************************************************************************/
uint32 MCAL_TIMER_Measure_Capture_Time(vuint32_ptr writePort, uint8 writePIN, vuint32_ptr readPort, uint8 readPIN,
                                       timer_typedef * delay, timer_typedef * capture);


#endif /* _TIMER_H_ */