/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: bus.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* bus.h:
               describes buses.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef BUS_H_
#define BUS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "memory_map.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef CORTEX_M4_BASE_ADDRESS
 #define CORTEX_M4_OFFSET       (0x0ul)
 #define CORTEX_M4_BASE_ADDRESS (CM4_INT_PERIPH_BASE_ADDRESS + CORTEX_M4_OFFSET)
#endif

#ifndef AHB3_BASE_ADDRESS
 #define AHB3_OFFSET            (0x0ul)
 #define AHB3_BASE_ADDRESS      (FMC_BASE_ADDRESS + AHB3_OFFSET)
#endif

#ifndef AHB2_BASE_ADDRESS
 #define AHB2_OFFSET            (0x10000000ul)
 #define AHB2_BASE_ADDRESS      (PERIPHERAL_BASE_ADDRESS + AHB2_OFFSET)
#endif

#ifndef AHB1_BASE_ADDRESS
 #define AHB1_OFFSET            (0x20000ul)
 #define AHB1_BASE_ADDRESS      (PERIPHERAL_BASE_ADDRESS + AHB1_OFFSET)
#endif

#ifndef APB2_BASE_ADDRESS
 #define APB2_OFFSET            (0x10000ul)
 #define APB2_BASE_ADDRESS      (PERIPHERAL_BASE_ADDRESS + APB2_OFFSET)
#endif

#ifndef APB1_BASE_ADDRESS
 #define APB1_OFFSET            (0x0ul)
 #define APB1_BASE_ADDRESS      (PERIPHERAL_BASE_ADDRESS + APB1_OFFSET)
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