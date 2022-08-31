/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
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
#include "Wdt_Cfg.h"
#include "Wdt.h"

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
* \Syntax          : void Wdg_Init(const Wdg_ConfigType* ConfigPtr)
* \Description     : initiate WDT1
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant    S                                         
* \Parameters (in) : ConfigPtr: this is a pointer to struct that contains:
												ISR_Fun_Ptr: which is a pointer to callBackFunction that is called by the ISR of WDT1 and the type of it is determined in Wdt_Cfg.h
												InterruptType: WDG_STANDARD or WDG_NON_MASKABLE
												EN_Reset:	enable or disable reset of WDT1 has the value of True or False
												Wdg_InitialTimeout: which is the initial countdown value
												u32	Wdg_MaxTimeout: which is the final countdown value


* \Parameters (out): void                  
* \Return value:   void
*******************************************************************************/

void Wdg_Init(const Wdg_ConfigType* ConfigPtr)
{
	WDTCTL_Tag* WDTCTL = (WDTCTL_Tag *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTCTL_OFFSET);
	/*TODO set Rn bit in RCGCWD	to enable its peripheral clock*/
	
		RCGCWD.B.R1 = 1;
	
	/*TODO Load the WDTLOAD with the desired timer*/
	
		(*((u32 *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTLOAD_OFFSET))) = ConfigPtr->Wdg_InitialTimeout;
	
	/*TODO wait for WRC bit in WDTCTL to be set*/
	
		while(!WDTCTL->B.WRC);
	
	/*TODO set RESEN in WDTCTL
	if th WDT is configured to trigger resets
	then wait for WRC bit in WDTCTL to be set
	*/
		if(ConfigPtr->EN_Reset)
			WDTCTL->B.RESEN=1;
		else
			WDTCTL->B.RESEN=0;
	
	/*TODO determine type of interrupt using INTTYPE bit in WDTCTL*/
		if(ConfigPtr->InterruptType==WDG_STANDARD)
			WDTCTL->B.INTTYPE = 0;
		else
			WDTCTL->B.INTTYPE = 1;
	
	/*TODO Set INTEN bit in WDTCTL which:
						enables WDT
						enables interrupts
						lock the control register
	*/
		
		WDTCTL->B.INTEN = 1;


		/*TODO LOCK the register*/
		
		(*((u32 *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTLOCK_OFFSET)))=1;
/*		to stall the WDT with if the microcontroller is stopped with debugger
					set STALL bit in the WDTTEST register 
		
		*/
	/*	
		SET_BIT((*((u32 *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTTEST_OFFSET))), 8);
	*/
		
		
}



/******************************************************************************
* \Syntax          : Wdg_SetTriggerCondition(u16 timeout)
* \Description     : refresh with timeout of ms but inside WDTLOAD insert with ticks
*
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant
* \Parameters (in) : timeout: the new time out value in milliseconds

* \Parameters (out): void                  
* \Return value:   void
*******************************************************************************/


void Wdg_SetTriggerCondition(u16 timeout)
{
		u32* WDTLOCK = (u32 *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTLOCK_OFFSET);
	
	/*TODO unlock via WDTLOCK by assigning WDTLOCK_KEY to it */

	*WDTLOCK = WDTLOCK_KEY;
	
	/*TODO write value of timeout to the WDTLOAD*/	
	
	(*((u32 *)(CORTEXM4_WDT1_BASE_ADDRESS+WDTLOAD_OFFSET))) = timeout * SystemClock;/*multiply by system clock to calculate the number of ticks*/
			
	
	/*TODO relock by writing any number into WDTLOCK*/	
	
	*WDTLOCK = 1;
	
	
}



/*******************************************************
 *  END OF FILE: Wdt.c
 ******************************************************/



