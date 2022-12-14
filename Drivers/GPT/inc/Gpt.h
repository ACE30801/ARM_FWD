/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Gpt.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef GPT_H_
#define GPT_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "Gpt_Types.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define PREDEF_TIMERS_INT_SIZE   4



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

        
void Gpt_Init(const Gpt_ConfigType * ConfigPtr);/*set configuration*/

void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);  /*target time in number of counts but in the pre-scaler that was determined by user*/
void Gpt_StopTimer(Gpt_ChannelType Channel);  //in continuous mode not one shot that expires automatically.

void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);

void Gpt_Notification_channel(void);


Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, u32* TimeValuePtr);


#endif /*GPT_H_*/

/**************************************************

  * END FILE Gpt.h
  
****************************************************/






