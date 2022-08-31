/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Adc_Types.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_


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
	SS0,
	SS1,
	SS2,
	SS3
}Adc_GroupType;

typedef u16 Adc_ValueGroupType;

typedef enum
{
	IDLE,
	BUSY
}Adc_StatusType;

typedef enum
{
  AIN0,			/*PE3*/
	AIN1,			/*PE2*/
	AIN2,			/*PE1*/
	AIN3,			/*PE0*/
	AIN4,			/*PD3*/
	AIN5,			/*PD2*/
	AIN6,			/*PD1*/
	AIN7,			/*PD0*/
	AIN8,			/*PE5*/
	AIN9,			/*PE4*/
	AIN10,		/*PB4*/
	AIN11			/*PB5*/
}Adc_ChannelType;


typedef enum
{
  ADC_TRIGG_SRC_HW,
  ADC_TRIGG_SRC_SW
}Adc_TriggSourceType;


typedef enum
{
  ADC_CONV_MODE_CONTINUOUS,
  ADC_CONV_MODE_ONESHOT
}Adc_GroupConvModeType;


typedef enum
{
	ADC_GROUP_PRIORITY_FIRST,
	ADC_GROUP_PRIORITY_SECOND,
	ADC_GROUP_PRIORITY_THIRD,
	ADC_GROUP_PRIORITY_FOURTH
}Adc_GroupPriorityType;


typedef enum
{
  ADC_STREAM_BUFFER_CIRCULAR,
  ADC_STREAM_BUFFER_LINEAR
}Adc_StreamBufferModeType;


typedef enum
{
	GROUP0,
	GROUP1,
	GROUP2,
	GROUP3,
	GROUP4,
	GROUP5,
	GROUP6,
	GROUP7
}Adc_GroupDefType;


typedef enum
{
	ADC_STREAM_SAMPLES_1,
	ADC_STREAM_SAMPLES_2,
	ADC_STREAM_SAMPLES_3,
	ADC_STREAM_SAMPLES_4,
	ADC_STREAM_SAMPLES_5,
	ADC_STREAM_SAMPLES_6,
	ADC_STREAM_SAMPLES_7,
	ADC_STREAM_SAMPLES_8,
	ADC_STREAM_SAMPLES_9,
	ADC_STREAM_SAMPLES_10,
	ADC_STREAM_SAMPLES_11,
	ADC_STREAM_SAMPLES_12
}Adc_StreamNumSampleType;

typedef struct
{
	Adc_ChannelType AdcChannelId;
	Adc_GroupType	AdcGroupId;
	Adc_GroupPriorityType	AdcGroupPriority;
	Adc_TriggSourceType	AdcGroupTriggSrc;
	Adc_GroupConvModeType	AdcGroupConversionMode;
	void (*AdcNotification)(void);
	Adc_StreamBufferModeType	AdcStreamingBufferMode;
	Adc_StreamNumSampleType		AdcStreamingNumSamples;
}Adc_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

        


#endif /*ADC_TYPES_H_*/

/**************************************************

  * END FILE Adc_Types.h
  
****************************************************/






