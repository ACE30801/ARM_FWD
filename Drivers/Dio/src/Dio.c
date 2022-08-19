/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"
#include "Bit_Math.h"
#include "Mcu_Hw.h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS                                                                          
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)        
* \Description     : Read channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ChannelId:  DIO channel number (0-7), PortId:  ID of the DIO port(0-5 corresponding to portA to portF)                       
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType  LOW,
																		 HIGH                                  
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
    u32 PortAdd;
    switch(PortId)
    {
      case  PORTA:
      PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
      break;
      case  PORTB:
      PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
      break;
      case  PORTC:
      PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
      break;
      case  PORTD:
      PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
      break;
      case  PORTE:
      PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
      break;
      case  PORTF:
      PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
      break;  
    }
    /*do
  {
    u32 tempVal = (u32) __LDREX((unsigned long *)var); 
    tempVal += off;
    lockedOut = __STREX(tempVal,(unsigned long *)var); 
  }
  while ( lockedOut );*/
		
    return(GET_BIT((*(((u32 *)(PortAdd + GPIODATA_OFFSET))+(1<<(2+ChannelId)))), ChannelId));
}


/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level)        
* \Description     : Write channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ChannelId:  DIO channel number (0-7),
                     PortId:  ID of the DIO port(0-5 corresponding to portA to portF),
                     Level: HIGH or LOW
* \Parameters (out): void                                                      
* \Return value:   : void                                  
*******************************************************************************/

void Dio_WriteChannel( Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    u32 PortAdd;
    switch(PortId)
    {
      case  PORTA:
      PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
      break;
      case  PORTB:
      PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
      break;
      case  PORTC:
      PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
      break;
      case  PORTD:
      PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
      break;
      case  PORTE:
      PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
      break;
      case  PORTF:
      PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
      break;  
    }
    if(Level)
    {
      SET_BIT((*(((u32 *)(PortAdd + GPIODATA_OFFSET))+(1<<(2+ChannelId)))), ChannelId);
    }
    else{
      CLEAR_BIT((*(((u32 *)(PortAdd + GPIODATA_OFFSET))+(1<<(2+ChannelId)))), ChannelId);
    }
  
}


/******************************************************************************
* \Syntax          : Dio_PortLevelType  Dio_ReadPort(Dio_PortType PortId)        
* \Description     : Read port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : PortId:  ID of the DIO port(0-5 corresponding to portA to portF),
                     
* \Parameters (out): Dio_PortLevelType                                                     
* \Return value:   : Dio_PortLevelType (0 -> 255)                                  
*******************************************************************************/


Dio_PortLevelType  Dio_ReadPort(Dio_PortType PortId)
{
  
    u32 PortAdd;
    switch(PortId)
    {
      case  PORTA:
      PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
      break;
      case  PORTB:
      PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
      break;
      case  PORTC:
      PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
      break;
      case  PORTD:
      PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
      break;
      case  PORTE:
      PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
      break;
      case  PORTF:
      PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
      break;  
    }  
    
    return ((*(((u8 *)(PortAdd + GPIODATA_OFFSET))+(255<<(2)))));
  
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)        
* \Description     : Write port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : PortId:  ID of the DIO port(0-5 corresponding to portA to portF),
                     Level: (0->255)
* \Parameters (out): void                                                      
* \Return value:   : void                                  
*******************************************************************************/


void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    u32 PortAdd;
    switch(PortId)
    {
      case  PORTA:
      PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
      break;
      case  PORTB:
      PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
      break;
      case  PORTC:
      PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
      break;
      case  PORTD:
      PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
      break;
      case  PORTE:
      PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
      break;
      case  PORTF:
      PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
      break;  
    }
    
    (*(((u8 *)(PortAdd + GPIODATA_OFFSET))+(255<<(2)))) = Level;
  
  
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_PortType PortId, Dio_ChannelType ChannelId)        
* \Description     : Toggle channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ChannelId: number of pin (0-7)
                     PortId:  ID of the DIO port(0-5 corresponding to portA to portF),
                     Level: high or low
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType: 
                                    HIGH
                                    LOW
*******************************************************************************/


Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
    u32 PortAdd;
    switch(PortId)
    {
      case  PORTA:
      PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
      break;
      case  PORTB:
      PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
      break;
      case  PORTC:
      PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
      break;
      case  PORTD:
      PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
      break;
      case  PORTE:
      PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
      break;
      case  PORTF:
      PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
      break;  
    }
    
    
    TOGGLE_BIT((*(((u32 *)(PortAdd + GPIODATA_OFFSET))+(1<<(2+ChannelId)))), ChannelId);
    
    return (GET_BIT((*(((u32 *)(PortAdd + GPIODATA_OFFSET))+(1<<(2+ChannelId)))), ChannelId));
}





/*******************************************************
 *  END OF FILE: Dio.c
 ******************************************************/



