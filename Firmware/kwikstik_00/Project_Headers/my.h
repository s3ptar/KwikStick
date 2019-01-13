/*
 * External definitions for KwikStik audio scope demo code 
 * 
 */

// current buffer with valid values
extern volatile uint16_t BufStart;
// double buffer for values
extern uint16_t MeasuredValues[];
// flag for end of measurement
extern bool Measured;



// size of the buffer 
// must correspond to Init_EDMA property channels / channel 0 / Settings / Major iteration count
#define ADC_BUFFER_SIZE 40
