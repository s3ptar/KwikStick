/** ###################################################################
**     Filename  : ProcessorExpert.c
**     Project   : ProcessorExpert
**     Processor : MK40DX256ZVLQ10
**     Version   : Driver 01.00
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-04-12, 17:12, # CodeGen: 0
**     Abstract  :
**         This demo project shows simple application for Kinetis KwikStik board (K40)
**         created with use of Processor Expert and it's Peripheral Initializatin Components.
**         Microphone signal is periodically sampled and displayed on the display.  
**         ADC reading the signal is triggered for 
**         periodical sampling 8 kHz (Influenced by Init_PDB period setting). 
**         The ADC (ADC0, channel 10) results are read and automatically stored 
**         using DMA into a memory buffer.            
**         
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "GPIO1.h"
#include "SegLCD1.h"
#include "ADC2.h"
#include "PDB1.h"
#include "eDMA1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "my.h"
#include "board.h"
#include "SLCD.h"
// variables for LDD components
LDD_TError Error;
LDD_TDeviceData *GPIOPtr;
LDD_TDeviceData *lcdDev;


// current buffer offset with valid values
volatile uint16_t BufStart;
// double buffer for values. One half will be filled and the other ready to be displayed  
uint16_t MeasuredValues[2*ADC_BUFFER_SIZE];
// flag for end of measurement
bool Measured;
// display hold counter
uint16_t cntr;
// last average value
uint16_t LastAvg;

// shows data on display like a simple "oscilloscope"
void ShowData() {	
  uint16_t i;
  uint8_t pos;
  int32_t val;  
  int32_t sum;
  sum = 0;
  // cycle through values
  for (i=0; i<37; i++) {	
	val = MeasuredValues[BufStart+i];
	sum += val;
	// substract last average 
	val = val - LastAvg;
	if (val < -150) {
	   pos = 0;	
	} else if (val < -90) {
	   pos = 1;	
	} else if (val < -60) {
	   pos = 2;	
	} else if (val < -30) {
	   pos = 3;	
	} else if (val < 30) {
	   pos = 4;	
	} else if (val < 60) {
	   pos = 5;	
	} else if (val < 90) {
	   pos = 6;	
	} else {
	   pos = 7;	
	}
	// set pixel on LCD 
    SegLCD1_SetFrontplaneData(lcdDev, (LDD_SegLCD_TPinIndex)i+1, 1 << pos );
  } // for  
  // compute average
  LastAvg = sum / 37; 
}


void main(void)
{
  /* Write your local variable definition here */
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  // Initilize test pin
  GPIOPtr = GPIO1_Init(NULL);
  // Initialize LCD
  lcdDev = SegLCD1_Init( NULL );
  // start with first buffer
  BufStart = 0;  
  // Display FSL logo
  SLCDModule_WirelessSign(1);
  SLCDModule_PounceSign(1);
  SLCDModule_JLinkSign(1);
  SLCDModule_BatterySign(1, 0);
  SLCDModule_BatterySign(1, 1);
  SLCDModule_BatterySign(1, 2);
  SLCDModule_BatterySign(1, 3);
  SLCDModule_BatterySign(1, 2);
  SLCDModule_BatterySign(0, 2);
  // Initialize ADC
  ADC2_Init();
  // Initialize DMA
  eDMA1_Init();
  // Initialize PDB for triggering
  PDB1_Init();
  // Start triggering from PDB peripheral  
  PDB0_SC |= PDB_SC_SWTRIG_MASK;  
  
  // reset display counter 
  cntr = 0;
  // we don't have average ready yet - estimation
  LastAvg = 33000;
  for(;;) {
	  // check if DMA cycle is finished 
	  if (Measured) {
		  cntr++;
		  // display only time after time 
		  if (cntr > 10) {
			  // display data 
			  ShowData();			  
			  cntr = 0; 
		  }
		  // reset flag 
		  Measured = FALSE;
	  }
  }
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
