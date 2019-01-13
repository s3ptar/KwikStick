/** ###################################################################
**     Filename  : Events.c
**     Project   : ProcessorExpert
**     Processor : MK40DX256ZVLQ10
**     Component : Events
**     Version   : Driver 01.00
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-04-12, 17:12, # CodeGen: 0
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "my.h"
#include "board.h"
/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK40N512LQ100]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Interrupt handler : DMA_ADC_DoneInterrupt
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
PE_ISR(DMA_ADC_DoneInterrupt)
{
  /* Write your interrupt code here ... */
  // Clear all DMA interrupt flags
  DMA_CINT = 0x40;
  // switch bufstart to other part of buffer
  BufStart = ADC_BUFFER_SIZE - BufStart;
  // reset destination address	
  DMA_TCD0_DADDR = (uint32_t)&(MeasuredValues[BufStart]);		
  // toggle pin
  GPIO1_ToggleFieldBits(GPIOPtr, TST,1);
  // toggle flag
  Measured = TRUE;
}

/*
** ===================================================================
**     Interrupt handler : DMA_error
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
PE_ISR(DMA_error)
{
  // Clear all DMA interrupt flags
  DMA_CINT = 0x40;
}


/*
** ===================================================================
**     Interrupt handler : PDBinterrupt
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
PE_ISR(PDBinterrupt)
{
  /* Write your interrupt code here ... */

}


/*
** ===================================================================
**     Interrupt handler : ADCinterrupt
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
PE_ISR(ADCinterrupt)
{
  /* Write your interrupt code here ... */

}


/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
