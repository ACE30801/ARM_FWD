/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Adc.c
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
#include "Adc_Config.h"
#include "Adc.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u16 i;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS                                                                          
 *********************************************************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
	static u8 Adc_0_Pressure=0,Adc_1_Pressure=0;
	
	u32 AdcBaseAdd, GpioBaseAdd;
	
	u8 AdcMux0Flag = 0,AdcMux1Flag = 0 ;
	/**************Enable Clock To ADCn by choosing the less working ADC to split the pressure****************/
	if(Adc_1_Pressure<Adc_0_Pressure)
	{
		RCGCADC.B.R1 = 1;
		AdcBaseAdd = CORTEXM4_ADC1_BASE_ADDRESS;
		Adc_1_Pressure+=ConfigPtr->AdcStreamingNumSamples;
	}
	else
	{
		RCGCADC.B.R0 = 1;
		AdcBaseAdd = CORTEXM4_ADC0_BASE_ADDRESS;
		Adc_0_Pressure+=ConfigPtr->AdcStreamingNumSamples;
	}
	/*************Enable Clock To GPIO Port*************/
	/*if(ConfigPtr->AdcChannelId<AIN4)
	{
		*enable port E*
		RCGCGPIO.B.PortE=1;
		GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
	}
	else if(ConfigPtr->AdcChannelId<AIN10)
	{
		*enable port D*
		RCGCGPIO.B.PortD=1;
		GpioBaseAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
	}
	else
	{
		*enable port B*
		RCGCGPIO.B.PortB=1;
		GpioBaseAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
	}
	*/
	/***************Define Pins as Analog Input *****************/
	switch(ConfigPtr->AdcChannelId)
	{
		case AIN0:/*PE3*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN3 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN3=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN3=1;/*Enable analog functionality*/
			
		break;
		case AIN1:/*PE2*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN2 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN2=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN2=1;/*Enable analog functionality*/
			
		break;
		case AIN2:/*PE1*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN1 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN1=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN1=1;/*Enable analog functionality*/
			
		break;
		case AIN3:/*PE0*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN0 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN0=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN0=1;/*Enable analog functionality*/
			
		break;
		case AIN4:/*PD3*/
			RCGCGPIO.B.PortD=1;
			GpioBaseAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN3 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN3=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN3=1;/*Enable analog functionality*/
			
		break;
		case AIN5:/*PD2*/
			RCGCGPIO.B.PortD=1;
			GpioBaseAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN2 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN2=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN2=1;/*Enable analog functionality*/
			
		break;
		case AIN6:/*PD1*/
			RCGCGPIO.B.PortD=1;
			GpioBaseAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN1 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN1=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN1=1;/*Enable analog functionality*/
			
		break;
		case AIN7:/*PD0*/
			RCGCGPIO.B.PortD=1;
			GpioBaseAdd = CORTEXM4_GPIO_D_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN0 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN0=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN0=1;/*Enable analog functionality*/
			
		break;
		case AIN8:/*PE5*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN5 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN5=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN5=1;/*Enable analog functionality*/
			
		break;
		case AIN9:/*PE4*/
			RCGCGPIO.B.PortE=1;
			GpioBaseAdd = CORTEXM4_GPIO_E_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN4 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN4=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN4=1;/*Enable analog functionality*/
			
		break;
		case AIN10:/*PB4*/
			RCGCGPIO.B.PortB=1;
			GpioBaseAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN4 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN4=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN4=1;/*Enable analog functionality*/
			
		break;
		case AIN11:/*PB5*/
			RCGCGPIO.B.PortB=1;
			GpioBaseAdd = CORTEXM4_GPIO_B_APB_BASE_ADDRESS;
			GPIOAFSEL(GpioBaseAdd).B.CONTROL_PIN5 = 1;/*Alternate function*/
			GPIODEN(GpioBaseAdd).B.CONTROL_PIN5=0;/*disable digital functionality*/
			GPIOAMSEL(GpioBaseAdd).B.CONTROL_PIN5=1;/*Enable analog functionality*/
			
		break;
	}
	/********************Group(SEQUENCER) Configuration***********************/
	switch(ConfigPtr->AdcGroupId){
		case SS0:
			ADCACTSS(GpioBaseAdd).B.ASEN0=0;
			if(ConfigPtr->AdcGroupTriggSrc == ADC_TRIGG_SRC_HW)
			{
				u32 Adc_TrigPortAdd =(u32)( CORTEXM4_GPIO_A_APB_BASE_ADDRESS + (0x1000 * ADC_TRIGGER_PORT));
				ADCEMUX(AdcBaseAdd).B.EM0 = 0x4;
				SET_BIT(GPIOADCCTL(Adc_TrigPortAdd), ADC_TRIGGER_PIN);
			}
			else
			{
				ADCEMUX(AdcBaseAdd).B.EM0 = 0x0;
				
			}
			/********determine input sequence mux********/
			for(i = 0; i<7;i++)
			{
				if((ADCSSMUX0(AdcBaseAdd).R>>(i*4))&0xF)/*MUXi is busy*/
				{
					continue;
				}
				else
				{
					ADCSSMUX0(AdcBaseAdd).R|=(((u32)(ConfigPtr->AdcChannelId))<<(4*i));
					AdcMux0Flag = 1;
					ADCSSCTL0(AdcBaseAdd).R|=1<<(3+4*i);/*enable temprature sensor*/
					ADCSSCTL0(AdcBaseAdd).R|=1<<(1+4*i);/*make the sample the end sample*/
					if(i>0)	
					{
						ADCSSCTL0(AdcBaseAdd).R&=~(1<<(1+4*(i-1)));/*make previous end bit not the end bit*/
					}
					break;
				}
				
			}
			if(AdcMux0Flag == 0)
			{
				/*the group is busy*/
			
			}
			ADCACTSS(GpioBaseAdd).B.ASEN0=1;
		break;
			
		case SS1:
			ADCACTSS(GpioBaseAdd).B.ASEN1=0;
			if(ConfigPtr->AdcGroupTriggSrc == ADC_TRIGG_SRC_HW)
			{
				u32 Adc_TrigPortAdd =(u32)( CORTEXM4_GPIO_A_APB_BASE_ADDRESS + (0x1000 * ADC_TRIGGER_PORT));
				ADCEMUX(AdcBaseAdd).B.EM1 = 0x4;
				SET_BIT(GPIOADCCTL(Adc_TrigPortAdd), ADC_TRIGGER_PIN);
			}
			else
			{
				ADCEMUX(AdcBaseAdd).B.EM1 = 0x0;
				
			}
			/********determine input sequence mux********/
			for(i = 0; i<7;i++)
			{
				if((ADCSSMUX1(AdcBaseAdd).R>>(i*4))&0xF)/*MUXi is busy*/
				{
					continue;
				}
				else
				{
					ADCSSMUX1(AdcBaseAdd).R|=(((u32)(ConfigPtr->AdcChannelId))<<(4*i));
					AdcMux1Flag = 1;
					ADCSSCTL1(AdcBaseAdd).R|=1<<(3+4*i);/*enable temprature sensor*/
					ADCSSCTL1(AdcBaseAdd).R|=1<<(1+4*i);/*make the sample the end sample*/
					if(i>0)	
					{
						ADCSSCTL1(AdcBaseAdd).R&=~(1<<(1+4*(i-1)));/*make previous end bit not the end bit*/
					}
					break;
				}
				
			}
			if(AdcMux1Flag == 0)
			{
				/*the group is busy*/
			
			}
			ADCACTSS(GpioBaseAdd).B.ASEN1=1;
		break;
		case SS2:
			ADCACTSS(GpioBaseAdd).B.ASEN2=0;
			if(ConfigPtr->AdcGroupTriggSrc == ADC_TRIGG_SRC_HW)
			{
				u32 Adc_TrigPortAdd =(u32)( CORTEXM4_GPIO_A_APB_BASE_ADDRESS + (0x1000 * ADC_TRIGGER_PORT));
				ADCEMUX(AdcBaseAdd).B.EM2 = 0x4;
				SET_BIT(GPIOADCCTL(Adc_TrigPortAdd), ADC_TRIGGER_PIN);
			}
			else
			{
				ADCEMUX(AdcBaseAdd).B.EM2 = 0x0;
				
			}
			/********determine input sequence mux********/
			for(i = 0; i<7;i++)
			{
				if((ADCSSMUX2(AdcBaseAdd).R>>(i*4))&0xF)/*MUXi is busy*/
				{
					continue;
				}
				else
				{
					ADCSSMUX2(AdcBaseAdd).R|=(((u32)(ConfigPtr->AdcChannelId))<<(4*i));
					AdcMux1Flag = 1;
					ADCSSCTL2(AdcBaseAdd).R|=1<<(3+4*i);/*enable temprature sensor*/
					ADCSSCTL2(AdcBaseAdd).R|=1<<(1+4*i);/*make the sample the end sample*/
					if(i>0)	
					{
						ADCSSCTL2(AdcBaseAdd).R&=~(1<<(1+4*(i-1)));/*make previous end bit not the end bit*/
					}
					break;
				}
				
			}
			if(AdcMux1Flag == 0)
			{
				/*the group is busy*/
			
			}
			ADCACTSS(GpioBaseAdd).B.ASEN2=1;
		break;
		case SS3:
			ADCACTSS(GpioBaseAdd).B.ASEN3=0;
			if(ConfigPtr->AdcGroupTriggSrc == ADC_TRIGG_SRC_HW)
			{
				u32 Adc_TrigPortAdd =(u32)( CORTEXM4_GPIO_A_APB_BASE_ADDRESS + (0x1000 * ADC_TRIGGER_PORT));
				ADCEMUX(AdcBaseAdd).B.EM3 = 0x4;
				SET_BIT(GPIOADCCTL(Adc_TrigPortAdd), ADC_TRIGGER_PIN);
			}
			else
			{
				ADCEMUX(AdcBaseAdd).B.EM3 = 0x0;
				
			}
			/********determine input sequence mux********/
			for(i = 0; i<7;i++)
			{
				if((ADCSSMUX3(AdcBaseAdd).R>>(i*4))&0xF)/*MUXi is busy*/
				{
					continue;
				}
				else
				{
					ADCSSMUX3(AdcBaseAdd).R|=(((u32)(ConfigPtr->AdcChannelId))<<(4*i));
					AdcMux1Flag = 1;
					ADCSSCTL3(AdcBaseAdd).R|=1<<(3+4*i);/*enable temprature sensor*/
					ADCSSCTL3(AdcBaseAdd).R|=1<<(1+4*i);/*make the sample the end sample*/
					if(i>0)	
					{
						ADCSSCTL3(AdcBaseAdd).R&=~(1<<(1+4*(i-1)));/*make previous end bit not the end bit*/
					}
					break;
				}
				
			}
			if(AdcMux1Flag == 0)
			{
				/*the group is busy*/
			
			}
			ADCACTSS(GpioBaseAdd).B.ASEN3=1;
		break;
	}
}

Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);
/*in initialization store the group specific result buffer start address (where the conversion result will be stored)*/

void Adc_StartGroupConversion(Adc_GroupType Group);


void Adc_StopGroupConversion(Adc_GroupType Group);

Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);

Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{


}
Adc_StreamNumSampleType Adc_getStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr);


void Adc_EnableHardwareTrigger(Adc_GroupType Group);


void Adc_DisableHardwareTrigger(Adc_GroupType Group);


void Adc_EnableGroupNotification(Adc_GroupType Group);

void Adc_DisableGroupNotification(Adc_GroupType Group);

/*******************************************************
 *  END OF FILE: Adc.c
 ******************************************************/



