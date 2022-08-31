/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
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
#include "Mcu_TypeCfg.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"

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

/************PREDEFINED TIMERS*************/



/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType * ConfigPtr)  

* \Description     : initiate timer
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ConfigPtr: this is a pointer to struct that contains:
																	
																	* 	Gpt_ChannelId:
																							timer id which is (TnCCPx or WTnCCPx that x = 1 or 0 and n = 0->5)	
																	*		Gpt_ChannelDirection
																							GPT_COUNT_UP for counting up or GPT_COUNT_DOWN for counting down
																	*		Gpt_GptChannelTickFrequency
																							frequency of the timer
																	*		channelTickMaxValue
																							maximum ticks that the timer will hold
																	*		ChannelMode
																							mode of operation oneshoot or periodic(GPT_MODE_ONESHOT or GPT_MODE_PERIODIC)
																					

* \Parameters (out): void                                                      
* \Return value:   void                                  
*******************************************************************************/



void Gpt_Init(const Gpt_ConfigType * ConfigPtr)  
{
	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(ConfigPtr->Gpt_ChannelId)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 1;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 1;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
				/*enable clock*/
				RCGCTIMER |= 2;
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 2;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 4;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 4;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 8;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 8;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 16;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 16;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 32;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
				/*enable clock*/
				RCGCTIMER |= 32;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 1;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 1;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 2;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 2;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 4;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 4;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 8;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 8;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 16;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 16;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 32;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
				/*enable clock*/
				RCGCWTIMER |= 32;
		break;		
	
	}
/*ensure timer is disabled for configuration*/
	GPTMCTL(TimerAdd).B.TAEN = 0;
	/*TODO	define the timer in individual state by writing 0x4 in GPTMCFG*/

		GPTMCFG(TimerAdd) = 0x00000000; 

	/*TODO	determine mode of operation of the timer*/
	switch(ConfigPtr->ChannelMode)
	{
		case GPT_MODE_ONESHOT:	
			GPTMTAMR(TimerAdd).B.TAMR = 0x1;
		break;
		case GPT_MODE_PERIODIC:	
			GPTMTAMR(TimerAdd).B.TAMR = 0x2;
		break;
	}
	/*TODO	determine direction of the timer*/
		switch(ConfigPtr->Gpt_ChannelDirection)
		{
			case GPT_COUNT_UP:
				GPTMTAMR(TimerAdd).B.TACDIR = 1;
			break;
			case GPT_COUNT_DOWN:
				GPTMTAMR(TimerAdd).B.TACDIR = 0;
			break;
		}
	
	/*TODO	make the timer wait for the enable bit to be set with writing 0 to TnWOT in register GPTMTnMR */
		
		GPTMTAMR(TimerAdd).B.TAWOT = 0;

		/*
		*take a snap shot from timer to GPTMTAR and the prescaler to GPTMTAPV
		*GPTMTAMR(TimerAdd).B.TASNAPS=1;
		*/

		
	/*TODO	update the value of timer instantly by 0 and after time out with 1*/
		
		//GPTMTAMR(TimerAdd).B.TAILD = 0;
				
	/*TODO	make the timer stop with the processor halt*/
	
		//GPTMCTL(TimerAdd).B.TASTALL = 1;

	/*TODO determine prescaler*/
	/*
		if((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency < 257 )
			GPTMTAPR(TimerAdd).B.TAPSR=((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency)-1;
		else
		{
			u16 prescale = (((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency)-1);
			GPTMTAPR(TimerAdd).B.TAPSR=prescale&0xFF;
			GPTMTAPR(TimerAdd).B.TAPSRH=prescale&0xFF00;
			
		}			
		*/	

}

void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)  
{
	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	
	
	/*TODO	load the value of Value in the GPTMTAILR*/
	
		GPTMTAILR(TimerAdd) = Value;
		
	/*TODO	GPTMTnMATCHR*/
	/*TODO	*/
	/*TODO	enable timer to start counting by writing to TnEN bit in GPTMCTL register*/
	GPTMCTL(TimerAdd).B.TAEN=1;
	
}
void Gpt_StopTimer(Gpt_ChannelType Channel)
{

	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	

	/*stop timer(disable)*/
	GPTMCTL(TimerAdd).B.TAEN = 0;

}

void Gpt_ContinueTimer(Gpt_ChannelType Channel)
{

	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	

	/*stop timer(disable)*/
	GPTMCTL(TimerAdd).B.TAEN = 1;

}

void Gpt_DisableNotification(Gpt_ChannelType Channel)  
{

	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	
	GPTMIMR(TimerAdd).B.TAMIM = 0;
	GPTMIMR(TimerAdd).B.TBMIM = 0;
	
	
	GPTMTAMR(TimerAdd).B.TAMIE = 0;
	
}

void Gpt_EnableNotification(Gpt_ChannelType Channel)  
{

	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	
	GPTMIMR(TimerAdd).B.TAMIM = 1;
	GPTMIMR(TimerAdd).B.TBMIM = 1;
	
	GPTMTAMR(TimerAdd).B.TAMIE = 1;
	
}


void Gpt_ChangeTimerValue(Gpt_ChannelType Channel, Gpt_ValueType Value)  
{
	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(Channel)
	{
		case T0CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			TimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			TimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	
	}	
	
	/*TODO	load the value of Value in the GPTMTAILR*/
	
		GPTMTAILR(TimerAdd) = Value;
}


/*TODO make a notification function for each timer and make a handler for each timer and put the handlers in startup code*/


/*******************************************************
 *  END OF FILE: Gpt.c
 ******************************************************/



