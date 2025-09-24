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
#ifndef AHB1_PERIPHERALS_H_
#define AHB1_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef DMA1_BASE_ADDRESS
 #define DMA1_OFFSET                (0x0ul)
 #define DMA1_BASE_ADDRESS          (AHB1_BASE_ADDRESS + DMA1_OFFSET)
#endif

#ifndef RCC_BASE_ADDRESS
 #define RCC_OFFSET                (0x1000ul)
 #define RCC_BASE_ADDRESS          (AHB1_BASE_ADDRESS + RCC_OFFSET)
#endif

#ifndef FLASH_IR_BASE_ADDRESS
 #define FLASH_IR_OFFSET           (0x2000ul)
 #define FLASH_IR_BASE_ADDRESS     (AHB1_BASE_ADDRESS + FLASH_IR_OFFSET)
#endif

#ifndef CRC_BASE_ADDRESS
 #define CRC_OFFSET                (0x3000ul)
 #define CRC_BASE_ADDRESS          (AHB1_BASE_ADDRESS + CRC_OFFSET)
#endif

#ifndef TSC_BASE_ADDRESS
 #define TSC_OFFSET               (0x4000ul)
 #define TSC_BASE_ADDRESS         (AHB1_BASE_ADDRESS + TSC_OFFSET)
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