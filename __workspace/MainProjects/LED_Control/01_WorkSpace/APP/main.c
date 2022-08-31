/*****includes*****/


#include "Bit_Math.h"
#include "Platform_Types.h"
#include "STD_Types.h"
#include "Mcu_Hw.h"
#include "Cpu_Driver.h"

#include "Dio.h"
#include "Port.h"
#include "Systick.h"
#include "IntCtrl.h"
#include "LED.h"

#include "Port_Lcfg.h"

void Systick_CountEnd(void)  ;

int T_ON = 1000;
int T_OFF = 1000;


/*******main function*******/

int main(void)
{
	
	CpuDriver_EnableGlobalInterrupt();
	
	Led_Init(LED_PORT, LED_PIN);
	
	Led_Activate(T_ON);
	
	
	 
	while(1)
	{
		/*dummy code*/
		u32 x = 15;
		if(x<15)
		{
			x++;
		}
		else
		{
			x--;
		}
	
	}
	
	
	
	
}



void Systick_CountEnd(void)  
{
	static u8 State = 1;
	if(State)
	{
		Led_OFF();
		Systick_ChangeTimerValue(T_OFF);
		State = 0;
	}
	else
	{
		Led_ON();
		Systick_ChangeTimerValue(T_ON);
		State = 1;
	}
}

