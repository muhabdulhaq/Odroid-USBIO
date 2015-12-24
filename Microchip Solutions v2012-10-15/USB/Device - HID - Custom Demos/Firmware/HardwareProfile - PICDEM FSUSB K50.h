/********************************************************************
 FileName:     	HardwareProfile - PICDEM FSUSB K50.h
 Dependencies:  See INCLUDES section
 Processor:     PIC18 USB Microcontrollers
 Hardware:      PICDEM FSUSB populated with PIC18F45K50
 Compiler:      Microchip C18
 Company:       Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC�?Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  2.9f  06/25/2012   Initial release
********************************************************************/

#ifndef HARDWARE_PROFILE_PICDEM_FSUSB_K50_H
#define HARDWARE_PROFILE_PICDEM_FSUSB_K50_H

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    //The PICDEM FS USB Demo Board platform supports the USE_SELF_POWER_SENSE_IO
    //and USE_USB_BUS_SENSE_IO features.  Uncomment the below line(s) if
    //it is desireable to use one or both of the features.
    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #if defined(USE_SELF_POWER_SENSE_IO)
    #define self_power          PORTAbits.RA2
    #else
    #define self_power          1
    #endif

    //#define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISAbits.TRISA1    // Input
    #if defined(USE_USB_BUS_SENSE_IO)
    #define USB_BUS_SENSE       PORTAbits.RA1
    #else
    #define USB_BUS_SENSE       1
    #endif


    //Uncomment the following line to make the output HEX of this  
    //  project work with the MCHPUSB Bootloader    
    //#define PROGRAMMABLE_WITH_USB_MCHPUSB_BOOTLOADER
	
    //Uncomment the following line to make the output HEX of this 
    //  project work with the HID Bootloader
    #define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER		

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    #define DEMO_BOARD PICDEM_FS_USB_K50
    #define PICDEM_FS_USB_K50
    #define PIC18F45K50_FAMILY
//    #define CLOCK_FREQ 48000000

    /** LED ************************************************************/
    #define mInitAllLEDs()      LATCbits.LATC2=1; TRISCbits.TRISC2=0; TRISDbits.TRISD6 = 0;
    
    #define mLED_1              LATCbits.LATC2

    #define mLED_2              LATDbits.LATD6
    
    /** SWITCH *********************************************************/
    #define mInitAllSwitches()  TRISA |= 0x7c; TRISB |= 0x38; TRISC |= 0x03; TRISD |= 0x3; TRISE |= 0x7;

    #define mKEY_0              PORTAbits.RA5
    #define mKEY_1              PORTAbits.RA2
    #define mKEY_2              PORTAbits.RA3

    #define mKEY_3              PORTAbits.RA4
    #define mKEY_4              PORTDbits.RD0
    #define mKEY_5              PORTAbits.RA6
    #define mKEY_6              PORTCbits.RC0
    #define mKEY_7              PORTCbits.RC1
    #define mKEY_8              PORTDbits.RD5
    #define mKEY_9              PORTDbits.RD4
    #define mKEY_10             PORTEbits.RE0
    #define mKEY_11             PORTEbits.RE1
    #define mKEY_12             PORTEbits.RE2
    #define mKEY_13             PORTBbits.RB5
    #define mKEY_14             PORTBbits.RB4
    #define mKEY_15             PORTBbits.RB3

#endif  //HARDWARE_PROFILE_PICDEM_FSUSB_K50_H
