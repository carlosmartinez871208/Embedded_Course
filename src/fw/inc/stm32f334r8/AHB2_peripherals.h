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
#ifndef AHB2_PERIPHERALS_H_
#define AHB2_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef GPIOA_BASE_ADDRESS
 #define GPIOA_OFFSET             (0x00000ul)
 #define GPIOA_BASE_ADDRESS       (AHB2_BASE_ADDRESS + GPIOA_OFFSET)
#endif

#ifndef GPIOB_BASE_ADDRESS
 #define GPIOB_OFFSET             (0x00400ul)
 #define GPIOB_BASE_ADDRESS       (AHB2_BASE_ADDRESS + GPIOB_OFFSET)
#endif

#ifndef GPIOC_BASE_ADDRESS
 #define GPIOC_OFFSET             (0x00800ul)
 #define GPIOC_BASE_ADDRESS       (AHB2_BASE_ADDRESS + GPIOC_OFFSET)
#endif

#ifndef GPIOD_BASE_ADDRESS
 #define GPIOD_OFFSET             (0x00C00ul)
 #define GPIOD_BASE_ADDRESS       (AHB2_BASE_ADDRESS + GPIOD_OFFSET)
#endif

#ifndef GPIOF_BASE_ADDRESS
 #define GPIOF_OFFSET             (0x01400ul)
 #define GPIOF_BASE_ADDRESS       (AHB2_BASE_ADDRESS + GPIOF_OFFSET)
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