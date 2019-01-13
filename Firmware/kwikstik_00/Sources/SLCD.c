/*
 * SLCD.c
 *
 *  Created on: Jan 13, 2019
 *      Author: Besitzer
 */

/*****************************************************************************
 * Includes
 ****************************************************************************/
#include "SLCD.h"
/*****************************************************************************
* Informations
*****************************************************************************/
// Signs from Driver_SLCD.h file in Project AN4523SW - ksplayer 
/*****************************************************************************
* Local Funtions
*****************************************************************************/

/*****************************************************************************
* Global Variable
*****************************************************************************/

/*****************************************************************************
* Constant
*****************************************************************************/

/************************************************************************
*! \fn			void SLCDModule_TurnUSBSign(bool OnOff)
*  \brief		Turn the USB Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_USBSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= USBSign;
	else
		TempData &= ~USBSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}
/************************************************************************
*! \fn			SLCDModule_FreescaleSign(bool OnOff)
*  \brief		Turn the Freescale Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_FreescaleSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= FreeScaleSign;
	else
		TempData &= ~FreeScaleSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}
/************************************************************************
*! \fn			void SLCDModule_ClockSign(bool OnOff)
*  \brief		Turn the Clock Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_ClockSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= ClockSign;
	else
		TempData &= ~ClockSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}

/************************************************************************
*! \fn			void SLCDModule_WirelessSign(bool OnOff)
*  \brief		Turn the Wireless Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_WirelessSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= WirelessSign;
	else
		TempData &= ~WirelessSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}

/************************************************************************
*! \fn			void SLCDModule_PounceSign(bool OnOff)
*  \brief		Turn the Pounce Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_PounceSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= PounceSign;
	else
		TempData &= ~PounceSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 38, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}

/************************************************************************
*! \fn			void SLCDModule_JLinkSign(bool OnOff)
*  \brief		Turn the JLink Sign On or Off
*  \param		bool OnOff	
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_JLinkSign(bool OnOff){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= JLinkSign;
	else
		TempData &= ~JLinkSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData); 
	
}

/************************************************************************
*! \fn			void SLCDModule_BatterySign(bool OnOff, uint8_t Level)
*  \brief		Turn the Battery Sign On or Off and Level
*  \param		bool OnOff	
*  \param		uint8_t Level, 0 = Empty, all over 2 is Full  
*  \exception	none
*  \return		none
************************************************************************/
void SLCDModule_BatterySign(bool OnOff, uint8_t Level){
    
	LDD_SegLCD_TFrontplaneData TempData;
	//get actual Display Data
	SegLCD1_GetFrontplaneData(lcdDev, 0, &TempData);
	//Clear Or Set Data
	if(OnOff)
		TempData |= BatteryBlockSign;
	else
		// Battery Outline and Block Off
		TempData &= ~(BatteryBlockSign|BatteryFullSign);
	
	if(Level >= BatteryLevelFull)
		TempData |= BatteryFullSign;
	else
		TempData &= ~BatteryFullSign;
	//Write Data To Display
    SegLCD1_SetFrontplaneData(lcdDev, 0, (LDD_SegLCD_TFrontplaneData)TempData);
    
    //Data for Middle an Low Sign
    SegLCD1_GetFrontplaneData(lcdDev, 38, &TempData);
    if(!OnOff){
    	//turn Off all Data
    	TempData &= ~(BatteryLowSign|BatteryMiddleSign);
    }else {
    	//Set Middle Sign
    	if(Level >= BatteryLevelMiddle)
    		TempData |= (BatteryMiddleSign);
    	else
    		TempData &= ~(BatteryMiddleSign);
    	
    	//Set Low Sign
    	if(Level >= BatteryLevelLow)
    	    TempData |= (BatteryLowSign);
    	 else
    	    TempData &= ~(BatteryLowSign);
    }
    SegLCD1_SetFrontplaneData(lcdDev, 38, (LDD_SegLCD_TFrontplaneData)TempData);
	
}

