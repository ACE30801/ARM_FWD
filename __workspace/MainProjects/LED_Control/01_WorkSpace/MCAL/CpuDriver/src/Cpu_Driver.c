#include"../../Libs/Bit_Math.h"
#include"../../Libs/Platform_Types.h"
#include "Cpu_Driver.h"


void CpuDriver_EnableGlobalInterrupt(void)
{
  __asm("CPSIE i;");
	__asm("CPSIE f");
}
void CpuDriver_DisableGlobalInterrupt(void)
{
  __asm("CPSID i;");
	__asm("CPSID f");
}





















/*
void CpuDriver_StartCriticalSection(void)
{
      __asm__ ("MRS R0, PRIMASK\n\t");
      __asm__("CPSID i\n\t");
      __asm__("STRB R0, %[output]" : [output] "=m" (SR_reg):: "r0");


__asm__("LDREX");
********code**********
__asm__("STREX");

*/
/*
}
void CpuDriver_StopCriticalSection(void)
{
      __asm__ ("ldrb r0, %[input]\n\t");
      __asm__("MSR PRIMASK,r0;\n\t"::[input] "m" (SR_reg): "r0");
*/
/*
}
*/

