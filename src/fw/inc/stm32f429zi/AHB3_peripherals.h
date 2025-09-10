/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.h:
               Use this template for your header files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef AHB3_PERIPHERALS_H_
#define AHB3_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef FMC_BANK1_BASE_ADDRESS
 #define FMC_BANK1_OFFSET       (0x0ul)
 #define FMC_BANK1_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK1_OFFSET)
#endif

#ifndef FMC_BANK2_BASE_ADDRESS
 #define FMC_BANK2_OFFSET       (0x10000000ul)
 #define FMC_BANK2_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK2_OFFSET)
#endif

#ifndef FMC_BANK3_BASE_ADDRESS
 #define FMC_BANK3_OFFSET       (0x20000000ul)
 #define FMC_BANK3_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK3_OFFSET)
#endif

#ifndef FMC_BANK4_BASE_ADDRESS
 #define FMC_BANK4_OFFSET       (0x30000000ul)
 #define FMC_BANK4_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK4_OFFSET)
#endif

#ifndef FMC_CR_BASE_ADDRESS
 #define FMC_CR_OFFSET          (0x40000000ul)
 #define FMC_CR_BASE_ADDRESS    (AHB3_BASE_ADDRESS + FMC_CR_OFFSET)
#endif

#ifndef FMC_BANK5_BASE_ADDRESS
 #define FMC_BANK5_OFFSET       (0x60000000ul)
 #define FMC_BANK5_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK5_OFFSET)
#endif

#ifndef FMC_BANK6_BASE_ADDRESS
 #define FMC_BANK6_OFFSET       (0x70000000ul)
 #define FMC_BANK6_BASE_ADDRESS (AHB3_BASE_ADDRESS + FMC_BANK6_OFFSET)
#endif

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 