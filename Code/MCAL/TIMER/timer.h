#ifndef _TIMER_H_
#define _TIMER_H_

//--------------------------------
//	        Includes
//--------------------------------
#include "../../INC/cortexM4.h"
#include "../../INC/bitwiseOperations.h"

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
  uint8 enableInterrupt;
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
#define TIMER_MODE_CAPTURE                              0x3 

//@ ref count Direction
#define TINER_COUNT_DIRECTION_DOWN                      0X0
#define TINER_COUNT_DIRECTION_UP                        0X10



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


void MCAL_TIMER_Init(timer_typedef * TIMERx, timer_config* config);


void MCAL_TIMER_DelayMs_P(timer_typedef * TIMERx, uint32 delay, uint8 timerAlpha);




#endif /* _TIMER_H_ */