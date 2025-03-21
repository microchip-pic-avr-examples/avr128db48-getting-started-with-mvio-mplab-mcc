/**
  * MVIO Generated Driver File
  *
  * @file mvio.c
  *
  * @ingroup mvio
  *
  * @brief This file contains the driver code for MVIO module.
  *
  * @version MVIO Driver Version 1.1.1
*/

/*
� [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../mvio.h"
#include "../../system/pins.h"


void (*MVIO_VDDIO2_isr_cb)(void) = NULL;

void MVIO_Vddio2CallbackRegister(MVIO_cb_t cb)
{
	MVIO_VDDIO2_isr_cb = cb;
}

int8_t MVIO_Initialize(void) 
{
    //VDDIO2IE enabled; 
    MVIO.INTCTRL = 0x1;

    return 0;
}

bool MVIO_isOK(void) 
{
    if (MVIO.STATUS  & MVIO_VDDIO2S_bm) {
        return true;
    } else {
        return false;
    }
}

ISR(MVIO_MVIO_vect)
{
	/* Insert your MVIO interrupt handling code */

    /* The VDDIO2 interrupt flag is cleared by writing 1 to it. */

	 if(MVIO.INTFLAGS & MVIO_VDDIO2IE_bm)
        {
            if (MVIO_VDDIO2_isr_cb != NULL)
            {
                (*MVIO_VDDIO2_isr_cb)();
            }

            MVIO.INTFLAGS = MVIO_VDDIO2IE_bm;
        }	
}
