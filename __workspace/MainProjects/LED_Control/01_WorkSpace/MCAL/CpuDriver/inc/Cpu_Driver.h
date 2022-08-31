#ifndef CPU_DRIVER_H_
#define CPU_DRIVER_H_


void CpuDriver_EnableGlobalInterrupt(void);
void CpuDriver_DisableGlobalInterrupt(void);
void CpuDriver_StartCriticalSection(void);
void CpuDriver_StopCriticalSection(void);


#endif
