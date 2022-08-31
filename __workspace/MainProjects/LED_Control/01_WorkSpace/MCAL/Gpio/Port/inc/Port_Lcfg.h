/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Port_Lcfg.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef PORT_LCFG_H_
#define PORT_LCFG_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"
/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 Port_ConfigType Port_ConfigPin[PORT_ATTACHED_PINS_NUMBER] =
/*	PortId 	ChannelId	 PortPinMode				PortPinLevelValue		PortPinDirection	PortPinInternalAttach	PortPinOutputCurrent*/
{
	{	Port_A, Channel_2, PORT_PINMODE_DIO, 	Port_Low,						Output,						NoPinAttachType,				R8R		},
};



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


 





#endif /*PORT_LCFG_H_*/

/**************************************************

  * END FILE Port_Lcfg.h
  
****************************************************/






