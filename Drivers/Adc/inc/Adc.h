/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Adc.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef ADC_H_
#define ADC_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "Adc_Types.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr);

Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);
/*in initialization store the group specific result buffer start address (where the conversion result will be stored)*/

void Adc_StartGroupConversion(Adc_GroupType Group);


void Adc_StopGroupConversion(Adc_GroupType Group);

Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);

Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)

Adc_StreamNumSampleType Adc_getStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr);


void Adc_EnableHardwareTrigger(Adc_GroupType Group);


void Adc_DisableHardwareTrigger(Adc_GroupType Group);


void Adc_EnableGroupNotification(Adc_GroupType Group);

void Adc_DisableGroupNotification(Adc_GroupType Group);
        


#endif /*ADC_H_*/

/**************************************************

  * END FILE Adc.h
  
****************************************************/






