#include "IntCtrl.h"
#include "Mcu_Hw.h"

void IntCtrl_init(void)
{
  /*initiate driver
  *take configuration and put them into registers
  *configurations(inside config):
    *peripheral gates(which interrupt or exception)
    *group priority
    *sub-group priority
  */
   APINT = APINT_KEY|0x00000000;
	
	/*assign group/sub-group priority in NVIC_PRIx and SCB_SYSPRIx registers*/
	
	
	/*enable or disable based on  configuration in NVIC_ENx and SCB_Sys registers*/
	
	
  
}




