/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Port_Cfg.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "Port.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/
#define PORT_ATTACHED_PINS_NUMBER		4

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

Port_ConfigType Port_ConfigPin[PORT_ATTACHED_PINS_NUMBER] =
/*	PortId 	ChannelId	 PortPinMode				PortPinLevelValue		PortPinDirection	PortPinInternalAttach	PortPinOutputCurrent*/
{
	{	Port_A, Channel_0, PORT_PINMODE_DIO, 	Port_High,					Output,						NoPinAttachType,				NoOutputCurrent		},
	{Port_A, Channel_1, PORT_PINMODE_DIO, 	Port_High,					Output,						NoPinAttachType,				NoOutputCurrent		},
	{Port_A, Channel_2, PORT_PINMODE_DIO, 	Port_High,					Output,						NoPinAttachType,				NoOutputCurrent		},
	{Port_A, Channel_3, PORT_PINMODE_DIO, 	Port_High,					Output,						NoPinAttachType,				NoOutputCurrent		}
};



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


 





#endif /*PORT_CFG_H_*/

/**************************************************

  * END FILE Port_Cfg.h
  
****************************************************/






