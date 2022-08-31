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

u32 PredefTimerAdd;

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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
* \Description     : initiate pins
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ConfigPtr: this is a pointer to struct that contains:
																	
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



void Gpt_Init(const Gpt_ConfigType * ConfigPtr)  
{
	/*the base address that will be worked on*/
	u32 TimerAdd;
	switch(ConfigPtr->Gpt_ChannelId)
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
	/*TODO	define the timer in individual state by writing 0x4 in GPTMCFG*/

		GPTMCFG(TimerAdd) |= 0x4; 

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
		
		GPTMTAMR(TimerAdd).B.TAILD = 0;

	/*TODO	set number of bits based on the max value that is taken*/
		
		
	/*TODO	make the timer stop with the processor halt*/
	GPTMCTL(TimerAdd).B.TASTALL = 1;

	/*TODO determine prescaler*/
	
		if((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency < 257 )
			GPTMTAPR(TimerAdd).B.TAPSR=((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency)-1;
		else
		{
			u16 prescale = (((MCU_CLOCK_FREQ_KHZ/1000)/ConfigPtr->Gpt_GptChannelTickFrequency)-1);
			GPTMTAPR(TimerAdd).B.TAPSR=prescale&0xFF;
			GPTMTAPR(TimerAdd).B.TAPSRH=prescale&0xFF00;
			
		}			
			
/*
#if (GPT_PREDEF_TIMER_100US_32BIT_STATUS == ENABLE)
`PredefTimerAdd;

switch(PREDEF_TIMER)
	{
		case T0CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	}
		GPTMCFG(PredefTimerAdd) = 0x4;
		GPTMTAMR(PredefTimerAdd).B.TACDIR=1;
		GPTMTAMR(PredefTimerAdd).B.TAMR=2;
		GPTMTAILR(PredefTimerAdd)= 

#elif GPT_PREDEF_TIMER_1US_16BIT_STATUS == ENABLE

	switch (PREDEF_TIMER){
		case T0CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	}

#elif (GPT_PREDEF_TIMER_1US_24BIT_STATUS == ENABLE)
`u32 PredefTimerAdd;
	switch(PREDEF_TIMER)
	{
		case T0CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	}
	
#elif (GPT_PREDEF_TIMER_1US_32BIT_STATUS == ENABLE)
`u32 PredefTimerAdd;
	switch(PREDEF_TIMER)
	{
		case T0CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T0CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS;
		break;
		case T1CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;			
		break;
		case T1CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS;
		break;
		case T2CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T2CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS;
		break;
		case T3CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T3CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS;
		break;
		case T4CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T4CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS;
		break;
		case T5CCP0:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case T5CCP1:
			PredefTimerAdd = CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT0CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT0CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS;
		break;
		case WT1CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT1CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS;
		break;
		case WT2CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT2CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS;
		break;
		case WT3CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT3CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS;
		break;
		case WT4CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT4CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS;
		break;
		case WT5CCP0:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;
		case WT5CCP1:
			PredefTimerAdd = CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS;
		break;		
	}
	

#endif

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
	
	GPTMTAMR(TimerAdd).B.TAMIE = 0;
	
}



Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)  
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
		/*
		* get timer value
		* (*((u16 *)(GPTMTAV_OFFSET+TimerAdd)))
		*
		*/
		if(GPTMTAMR(TimerAdd).B.TACDIR)/*counts up*/
		{
				return ((u32)(*((u16 *)(GPTMTAV_OFFSET+TimerAdd))));
		}
		else
		{
			return ((u32)(GPTMTAILR(TimerAdd)-(*((u16 *)(GPTMTAV_OFFSET+TimerAdd)))));
		}
	
}


Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)  
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
		/*
		* get timer value
		* (*((u16 *)(GPTMTAV_OFFSET+TimerAdd)))
		*
		*/
		if(GPTMTAMR(TimerAdd).B.TACDIR)/*counts up*/
		{
				return ((u32)(GPTMTAILR(TimerAdd)-(*((u16 *)(GPTMTAV_OFFSET+TimerAdd)))));
		}
		else
		{
			return ((u32)(*((u16 *)(GPTMTAV_OFFSET+TimerAdd))));
		}
	
	
}


Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, u32* TimeValuePtr)  
{
	/*not known*/
	
	return 0; 
}



void Gpt_Notification_channel(void)  
{
	static int x = 0;
	x++;
	
}


/*TODO make a notification function for each timer and make a handler for each timer and put the handlers in startup code*/


/*******************************************************
 *  END OF FILE: Gpt.c
 ******************************************************/



