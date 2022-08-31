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
#include "Port_Cfg.h"
#include "Port.h"

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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
* \Description     : initiate pins
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ConfigPtr: this is a pointer to struct that contains:
																	
																	*	PortId:	the number of the port (Port_A -> Port_F)
																	* ChannelId: corresponding to number of pin (Channel_0->Channel_7)
																	* PortPinMode:	mode of operation:
																						*PORT_PINMODE_DIO	or -1:	make the pin digital input/output
																						*0:	analog function
																						*any other number(1 -> 14): alternative function
																	* PortPinLevelValue: High or Low
																	* PortPinDirection:	Input or Output
																	* PortPinInternalAttach: Additional choice for Dio pins that has one of four values:
																					*NoPinAttachType:	to not specify any attachment
																					*PullUp: to attach a low power a pull up resistance
																					*PullDown: to attach an open drain for I2C
																					*OpenDrain: to attach 
																	* PortPinOutputCurrent: 
																					*NoOutputCurrent: to not specify a current
																					*R2R: for 2mA current
																					*R4R: for 4mA current
																					*R8R: for 8mA current
																					

* \Parameters (out): void                                                      
* \Return value:   void                                  
*******************************************************************************/
 
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	
	/**************FIND PORT***************/
	u32 PortAdd;
	switch(ConfigPtr->PortId)
	{
		case PORTA:
				GPIOHBCTL.B.PortA=0;
				PortAdd = CORTEXM4_GPIO_A_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortA=1;
		break;
		case PORTB:
				GPIOHBCTL.B.PortB=0;
				PortAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortB=1;
		break;
		case PORTC:
				GPIOHBCTL.B.PortC=0;
				PortAdd = CORTEXM4_GPIO_C_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortC=1;
		break;
		case PORTD:
				GPIOHBCTL.B.PortD=0;
				PortAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortD=1;
		break;
		case PORTE:
				GPIOHBCTL.B.PortE=0;
				PortAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortE=1;
		break;
		case PORTF:
				GPIOHBCTL.B.PortF=0;
				PortAdd = CORTEXM4_GPIO_F_APB_BASE_ADDRESS;
				RCGCGPIO.B.PortF=1;
		break;
	}
	/*determine the bus of GPIO with GPIOHBCTL from AHB that 0is APB and 1 is AHP and bits 0 to 5 corresponds to A to F*/
	
	/*enable clock to the port with RCGCGPIO  that set enables with bits 0 to 5 for A to F*/
	
	/*unlock the bit from GPIOLOCK and set GPIOCR to apply the changes to
			GPIOAFSEL, GPIOPUR, GPIOPDR, GPIODEN
	*/
	
	
	/**************UNLOCK REGISTERS***************/
	(*((u32 *)(GPIOLOCK_OFFSET+PortAdd))) = GPIOLOCK_KEY;
	SET_BIT( (*((u32 *)(GPIOCR_OFFSET+PortAdd))) ,ConfigPtr->ChannelId);
	(*((u32 *)(GPIOLOCK_OFFSET+PortAdd))) = 0x1;
	
	
	/****************PIN DIRECTION******************/
	/*set direction of pins using GPIODIR (1 for output and 0 for input)*/
	if(ConfigPtr->PortPinDirection == Input)
	{
		CLEAR_BIT((*((u32*)(GPIODIR_OFFSET+ PortAdd ))), ConfigPtr->ChannelId);
	}
	else
	{
		SET_BIT((*((u32*)(GPIODIR_OFFSET+ PortAdd ))), ConfigPtr->ChannelId);
	}
	
	
	/*****************PIN MODE DIO******************/
		CLEAR_BIT(*((u32 *)(PortAdd+GPIOAFSEL_OFFSET)), ConfigPtr->ChannelId);
	
	
	/*set the drive strength through GPIODR2R, GPIODR4R,and GPIODR8R*/
	switch(ConfigPtr->PortPinOutputCurrent)
	{
		case	R2R:
				SET_BIT((*((u32 *)(GPIODR2R_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
		case	R4R:
				SET_BIT((*((u32 *)(GPIODR4R_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
		case	R8R:
				SET_BIT((*((u32 *)(GPIODR8R_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
		case NoOutputCurrent:
				
		break;
		
	}
	
	/*program each pad to have pull-up, pull-down, or open erain functionality with
		GPIOPUR, GPIOPDR, GPIOODR.
		first set the bit corresponding to the bit in the GPIOCR register
	if needed slow rate it can be programmed using GPIOSLR
	*/
	/*NOTE: setting GPIOPUR bitx clears GPIOPDR bitx*/
	switch(ConfigPtr->PortPinInternalAttach)
	{
		case NoPinAttachType:
			
		break;
		case PullUp:
			SET_BIT((*((u32 *)(GPIOPUR_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
		case PullDown:
			SET_BIT((*((u32 *)(GPIOPDR_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
		case OpenDrain:
			SET_BIT((*((u32 *)(GPIOODR_OFFSET+PortAdd))), ConfigPtr->ChannelId);
		break;
	}
		
	/* enable GPIO pins as:
			*digital I/Os, set the appropriate DEN bit in the GPIODEN register
			*To enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the GPIOAMSEL register.
	*/
	if(ConfigPtr->PortPinMode)/*false if analog that analog = 0*/
	{
		SET_BIT((*((u32 *)(GPIODEN_OFFSET+PortAdd))), ConfigPtr->ChannelId);
	}
	else
	{
		SET_BIT((*((u32 *)(GPIOAMSEL_OFFSET+PortAdd))), ConfigPtr->ChannelId);
	}
	
	/*relock the pin*/
	(*((u32 *)(GPIOLOCK_OFFSET+PortAdd))) = GPIOLOCK_KEY;
	CLEAR_BIT( (*((u32 *)(GPIOCR_OFFSET+PortAdd))) ,ConfigPtr->ChannelId);
	(*((u32 *)(GPIOLOCK_OFFSET+PortAdd))) = 0x1;
		
	/*TODO Add option of EXTI and ADC*/
	
	return;
}



/*******************************************************
 *  END OF FILE: Port.c
 ******************************************************/



