/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_CO aliases
#define channel_CO_TRIS                 TRISCbits.TRISC0
#define channel_CO_LAT                  LATCbits.LATC0
#define channel_CO_PORT                 PORTCbits.RC0
#define channel_CO_WPU                  WPUCbits.WPUC0
#define channel_CO_OD                   ODCONCbits.ODCC0
#define channel_CO_ANS                  ANSELCbits.ANSC0
#define channel_CO_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define channel_CO_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define channel_CO_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define channel_CO_GetValue()           PORTCbits.RC0
#define channel_CO_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define channel_CO_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define channel_CO_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define channel_CO_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define channel_CO_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define channel_CO_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define channel_CO_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define channel_CO_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set channel_CH4 aliases
#define channel_CH4_TRIS                 TRISCbits.TRISC1
#define channel_CH4_LAT                  LATCbits.LATC1
#define channel_CH4_PORT                 PORTCbits.RC1
#define channel_CH4_WPU                  WPUCbits.WPUC1
#define channel_CH4_OD                   ODCONCbits.ODCC1
#define channel_CH4_ANS                  ANSELCbits.ANSC1
#define channel_CH4_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define channel_CH4_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define channel_CH4_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define channel_CH4_GetValue()           PORTCbits.RC1
#define channel_CH4_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define channel_CH4_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define channel_CH4_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define channel_CH4_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define channel_CH4_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define channel_CH4_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define channel_CH4_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define channel_CH4_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set channel_LPG aliases
#define channel_LPG_TRIS                 TRISCbits.TRISC2
#define channel_LPG_LAT                  LATCbits.LATC2
#define channel_LPG_PORT                 PORTCbits.RC2
#define channel_LPG_WPU                  WPUCbits.WPUC2
#define channel_LPG_OD                   ODCONCbits.ODCC2
#define channel_LPG_ANS                  ANSELCbits.ANSC2
#define channel_LPG_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define channel_LPG_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define channel_LPG_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define channel_LPG_GetValue()           PORTCbits.RC2
#define channel_LPG_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define channel_LPG_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define channel_LPG_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define channel_LPG_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define channel_LPG_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define channel_LPG_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define channel_LPG_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define channel_LPG_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SNDP_PIN aliases
#define SNDP_PIN_TRIS                 TRISCbits.TRISC6
#define SNDP_PIN_LAT                  LATCbits.LATC6
#define SNDP_PIN_PORT                 PORTCbits.RC6
#define SNDP_PIN_WPU                  WPUCbits.WPUC6
#define SNDP_PIN_OD                   ODCONCbits.ODCC6
#define SNDP_PIN_ANS                  ANSELCbits.ANSC6
#define SNDP_PIN_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SNDP_PIN_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SNDP_PIN_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SNDP_PIN_GetValue()           PORTCbits.RC6
#define SNDP_PIN_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SNDP_PIN_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SNDP_PIN_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SNDP_PIN_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SNDP_PIN_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SNDP_PIN_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SNDP_PIN_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SNDP_PIN_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SNDN_PIN aliases
#define SNDN_PIN_TRIS                 TRISCbits.TRISC7
#define SNDN_PIN_LAT                  LATCbits.LATC7
#define SNDN_PIN_PORT                 PORTCbits.RC7
#define SNDN_PIN_WPU                  WPUCbits.WPUC7
#define SNDN_PIN_OD                   ODCONCbits.ODCC7
#define SNDN_PIN_ANS                  ANSELCbits.ANSC7
#define SNDN_PIN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SNDN_PIN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SNDN_PIN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SNDN_PIN_GetValue()           PORTCbits.RC7
#define SNDN_PIN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SNDN_PIN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SNDN_PIN_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SNDN_PIN_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SNDN_PIN_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SNDN_PIN_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SNDN_PIN_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SNDN_PIN_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/