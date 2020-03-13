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

#include "snd.h"
#include "mcc_generated_files/mcc.h"


#define SND_ALARM_DELAY         (100)
#define SND_ALARM_CO_CNT        (300)
#define SND_ALARM_CO_HALF_PER   (4)
#define SND_ALARM_CH4_CNT       (400)
#define SND_ALARM_CH4_HALF_PER  (3)
#define SND_ALARM_LPG_CNT       (600)
#define SND_ALARM_LPG_HALF_PER  (2)
#define SND_PER_DELAY_UNIT      (50)

static void SND_alarm(uint16_t n, uint8_t halfPer)
{
    SNDP_PIN_Toggle();
    for(uint16_t i=0; i<n; i++)
    {
        SNDP_PIN_Toggle();
        SNDN_PIN_Toggle();
        for(uint8_t j=0; j<halfPer; j++)
        {
            __delay_us(SND_PER_DELAY_UNIT);
        }
    }
    SNDP_PIN_SetLow();
    SNDN_PIN_SetLow();
    __delay_ms(SND_ALARM_DELAY);
}

void SND_alarmCO(void)
{
    SND_alarm(SND_ALARM_CO_CNT, SND_ALARM_CO_HALF_PER);
}

void SND_alarmCH4(void)
{
    SND_alarm(SND_ALARM_CH4_CNT, SND_ALARM_CH4_HALF_PER);
}

void SND_alarmLPG(void)
{
    SND_alarm(SND_ALARM_LPG_CNT, SND_ALARM_LPG_HALF_PER);
}

