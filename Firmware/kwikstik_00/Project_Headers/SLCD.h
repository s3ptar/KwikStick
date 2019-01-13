/*
 * SLCD.h
 *
 *  Created on: Jan 13, 2019
 *      Author: Besitzer
 */

#ifndef SLCD_H_
#define SLCD_H_

/*****************************************************************************
 * Includes
 ****************************************************************************/
#include "PE_Types.h"
#include "SegLCD1.h"
#include "board.h"
/*****************************************************************************
 * Definitions
 ****************************************************************************/
#define On 	1
#define Off 0

#define WirelessSign 		1
#define USBSign 			2
#define ClockSign 			8
#define FreeScaleSign 		16
#define JLinkSign			32
#define PounceSign			32
#define BatteryBlockSign	64
#define BatteryLowSign		128
#define BatteryMiddleSign	64
#define BatteryFullSign		128
#define BatteryLevelFull	3
#define BatteryLevelMiddle	2
#define BatteryLevelLow		1
#define BatteryLevelEmpty	0
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/*****************************************************************************
 * Functions
 ****************************************************************************/

void SLCDModule_USBSign(bool OnOff);
void SLCDModule_FreescaleSign(bool OnOff);
void SLCDModule_ClockSign(bool OnOff);
void SLCDModule_WirelessSign(bool OnOff);
void SLCDModule_PounceSign(bool OnOff);
void SLCDModule_JLinkSign(bool OnOff);
void SLCDModule_BatterySign(bool OnOff, uint8_t Level);

#endif /* SLCD_H_ */
