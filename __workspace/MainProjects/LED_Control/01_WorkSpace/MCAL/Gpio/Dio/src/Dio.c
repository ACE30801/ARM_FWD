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
    if(Level==Dio_High)
    {
      //*((volatile u32 *)(PortAdd+(u32)(4<<ChannelId)))= (u32)1<<ChannelId;
			*(volatile u32 *)BIT_BANDING_ADDRESS(PortAdd, GPIODATA_OFFSET+0x3FC,ChannelId) = 1;//ADDRESS(BASE+OFFSET)- 0x40000000, 0x3FC is the address taht writes to all pins
    }
    else{
      *(volatile u32 *)BIT_BANDING_ADDRESS(PortAdd, GPIODATA_OFFSET+0x3FC,ChannelId) = 0;
    }
  
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
    
    
    (*(volatile u32 *)BIT_BANDING_ADDRESS(PortAdd, GPIODATA_OFFSET+0x3FC,ChannelId)) ^= 1;
    
    return ((*(volatile u32 *)BIT_BANDING_ADDRESS(PortAdd, GPIODATA_OFFSET+0x3FC,ChannelId)));
}





/*******************************************************
 *  END OF FILE: Dio.c
 ******************************************************/



