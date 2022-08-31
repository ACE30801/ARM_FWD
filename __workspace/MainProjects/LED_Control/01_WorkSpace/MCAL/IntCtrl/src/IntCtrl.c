#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
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
	
	APINT &= ~((u32)(0x7<<8));
	/*enable or disable based on  configuration in NVIC_ENx and SCB_Sys registers*/
	
	
  *((u32 *)(0xE000E000 + 0x100)) |= ((1 <<19)| (1<<21));
	
}




