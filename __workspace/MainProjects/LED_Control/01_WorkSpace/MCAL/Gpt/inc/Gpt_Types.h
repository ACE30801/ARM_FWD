/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Gpt_Types.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef GPT_TYPES_H_
#define GPT_TYPES_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum
{
	T0CCP0,
	T0CCP1,
	T1CCP0,
	T1CCP1,
	T2CCP0,
	T2CCP1,
	T3CCP0,
	T3CCP1,
	T4CCP0,
	T4CCP1,
	T5CCP0,
	T5CCP1,
	WT0CCP0,
	WT0CCP1,
	WT1CCP0,
	WT1CCP1,
	WT2CCP0,
	WT2CCP1,
	WT3CCP0,
	WT3CCP1,
	WT4CCP0,
	WT4CCP1,
	WT5CCP0,
	WT5CCP1

}Gpt_ChannelType; 


typedef enum
{
	GPT_MODE_ONESHOT,
	GPT_MODE_PERIODIC
}Gpt_ChannelModeType;

typedef enum
{
	GPT_COUNT_UP,
	GPT_COUNT_DOWN
}Gpt_TimerDirection;


typedef struct
{
	Gpt_ChannelType  		Gpt_ChannelId;
	Gpt_TimerDirection	Gpt_ChannelDirection;
	u32									Gpt_GptChannelTickFrequency;
	u32									channelTickMaxValue;
	Gpt_ChannelModeType ChannelMode;
}Gpt_ConfigType;

typedef u32 Gpt_ValueType;
          

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /*GPT_TYPES_H_*/

/**************************************************

  * END FILE Gpt_Types.h
  
****************************************************/






