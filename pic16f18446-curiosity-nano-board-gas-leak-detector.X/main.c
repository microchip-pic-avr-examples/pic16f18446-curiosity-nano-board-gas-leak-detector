/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "snd.h"

#define ADMD_BASIC              0
#define ADACC_SHIFT_DIV32       5
#define DELAY_BEFORE_SETPOINT   1000
#define DELAY_AFTER_SETPOINT    1000

static uint16_t thresholdCO;
static uint16_t thresholdCH4;
static uint16_t thresholdLPG;

static void thresholdInit(void);
static void onDetectCO(void);
static void onDetectCH4(void);
static void onDetectLPG(void);
static void ADCC_selectSensor(adcc_channel_t ch, uint16_t threshold);
static void ADCC_selectNextSensor(void);
static void ADCC_setMode(uint8_t mode);

static void onDetectCO(void)
{
    SND_alarmCO();
}

static void onDetectCH4(void)
{
    SND_alarmCH4();
}

static void onDetectLPG(void)
{
    SND_alarmLPG();
}

static void ADCC_selectSensor(adcc_channel_t ch, uint16_t threshold)
{
    /* Set channel */
    ADPCH = ch;
    /* Set setpoint */
    ADCC_DefineSetPoint(threshold);
}

static void ADCC_selectNextSensor(void)
{
    switch(ADPCH)
    {
        case channel_CO:
            ADCC_SetADTIInterruptHandler(onDetectCO);
            ADCC_selectSensor(channel_CH4, thresholdCH4);
        break;
        case channel_CH4:
            ADCC_SetADTIInterruptHandler(onDetectCH4);
            ADCC_selectSensor(channel_LPG, thresholdLPG);
        break;
        case channel_LPG:
            ADCC_SetADTIInterruptHandler(onDetectLPG);
            ADCC_selectSensor(channel_CO, thresholdCO);
        break;
        default:
        break;
    }
}

static void ADCC_setMode(uint8_t mode)
{
    ADCON2bits.ADMD = mode;
}

static void thresholdInit(void)
{
    ADCC_GetSingleConversion(channel_CO);
    thresholdCO = ADCC_GetAccumulatorValue() >> ADACC_SHIFT_DIV32;

    ADCC_GetSingleConversion(channel_CH4);
    thresholdCH4 = ADCC_GetAccumulatorValue() >> ADACC_SHIFT_DIV32;

    ADCC_GetSingleConversion(channel_LPG);
    thresholdLPG = ADCC_GetAccumulatorValue() >> ADACC_SHIFT_DIV32;
}

void main(void)
{    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    __delay_ms(DELAY_BEFORE_SETPOINT); 
    thresholdInit(); 
    __delay_ms(DELAY_AFTER_SETPOINT);
    
    ADCC_setMode(ADMD_BASIC);
    
    /* Set initial sensor */
    ADCC_selectSensor(channel_CO, thresholdCO);
    
    /* Switch to next sensor when conversion is complete */
    ADCC_SetADIInterruptHandler(ADCC_selectNextSensor);
    
    /* Start timer */
    TMR2_StartTimer();
    
    while (1)
    {
        ;   
    }
}
/**
 End of File
*/