/**
  MVIO Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    mvio.c

  @Summary
    This is the generated driver implementation file for the MVIO

  @Description
    This source file provides APIs for MVIO.
    Generation Information :
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLABX v5.40
*/

/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#include "../mvio.h"

/**
 * \brief Initialize mvio interface
 */
int8_t MVIO_Initialize(void) 
{
    //VDDIO2IE disabled; 
    MVIO.INTCTRL = 0x0;

    return 0;
}

/**
 * \brief Check MVIO VDDIO2 Status
 *
 * \return The status to check if VDDIO2 voltage is within the acceptable range of operation
 * \retval false The VDDIO2 supply voltage is below the acceptable range of operation
 * \retval true The VDDIO2 supply voltage is within the acceptable range of operation
 */
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
    /* Insert your MVIO interrupt handling code here */
}
