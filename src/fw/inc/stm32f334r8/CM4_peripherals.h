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
#ifndef CM4_PERIPHERALS_H_
#define CM4_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* System Control Block (SCB): */
#ifndef SCB_BASE_ADDRESS
 #define SCB_OFFSET           (0xE008ul)
 #define SCB_BASE_ADDRESS     (CORTEX_M4_BASE_ADDRESS + SCB_OFFSET)
#endif

/* System Timer (SysTick): */
#ifndef SYSTICK_BASE_ADDRESS
 #define SYSTICK_OFFSET       (0xE010ul)
 #define SYSTICK_BASE_ADDRESS (CORTEX_M4_BASE_ADDRESS + SYSTICK_OFFSET)
#endif

/* Nested Vector Interrupt Controller (NVIC): */
#ifndef NVIC_BASE_ADDRESS
 #define NVIC_OFFSET          (0xE100ul)
 #define NVIC_BASE_ADDRESS    (CORTEX_M4_BASE_ADDRESS + NVIC_OFFSET)
#endif

/* Memory Protection Unit (MPU): */
#ifndef MPU_BASE_ADDRESS
 #define MPU_OFFSET           (0xED90ul)
 #define MPU_BASE_ADDRESS     (CORTEX_M4_BASE_ADDRESS + MPU_OFFSET)
#endif

 /* Floating Point Unit (FPU): */
 /* 0xE000ED88 CPACR Coprocessor access register. */
 #ifndef FPU_BASE_ADDRESS
 #define FPU_OFFSET           (0xED88ul)
 #define FPU_BASE_ADDRESS     (CORTEX_M4_BASE_ADDRESS + FPU_OFFSET)
#endif

/* Debug Microcontroller (DBG_MCU): */
#ifndef DBG_MCU_BASE_ADDRESS
 #define DBG_MCU_OFFSET       (0x42000ul)
 #define DBG_MCU_BASE_ADDRESS (CORTEX_M4_BASE_ADDRESS + DBG_MCU_OFFSET) /* See reference manual */
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