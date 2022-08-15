

/**************************************************

  * GLOBAL FUNCTION
  
****************************************************/



/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "IntCtrl.h"
/*#include "Mcu_Hw.h"*/



/**************************************************

  * FUNCTIONS' IMPLIMINTATION
  
****************************************************/

void IntCtrl_init(void)
{
  //initiate driver
  //take configuration and put them into registers
  //configurations(inside config):
    //peripheral gates(which interrupt or exception)
    //group priority
    //sub-group priority
  /*APINT control the implementation of the group/sub-group implementation*/
  
   APINT = 0xFA05|0x00000000;
	
	/*assign group/sub-group priority in NVIC_PRIx and SCB_SYSPRIx registers*/
	
	
	/*enable or disable based on  configuration in NVIC_ENx and SCB_Sys registers*/
	
	
  
}






/**************************************************

  * END FILE IntCtrl.c
  
****************************************************/
