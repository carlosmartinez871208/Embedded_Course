/*********************************************************************************************************************/
/*                                                  HEADER GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.h:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef TEMPLATE_H_
#define TEMPLATE_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "interrupts.h"
#include "peripherals.h"
#include "Register.h"
#include "Std_Types.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t csr;       /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
    __IO uint32_t rvr;       /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
    __IO uint32_t cvr;        /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
    __IO uint32_t calib;      /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

typedef struct
{
    uint8_t  Enable;       /* Enable or disable the SysTick Timer */
    uint8_t  TickInt;      /* Enable or disable the SysTick Interrupt */
    uint8_t  ClkSource;    /* Select the clock source */
    uint32_t ReloadValue;  /* Set the reload value (24-bit value) */
} SysTick_ConfigType;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#ifndef SYSTICK
#define SYSTICK ((SysTick_Type *)SYSTICK_BASE_ADDRESS)
#endif

#define SYSTICK_1_SEC_TICKS     15999999ul /* Assuming a system clock of 16 MHz, 1 sec = 16000000 ticks */
#define SYSTICK_500_MS_TICKS    7999999ul  /* Assuming a system clock of 16 MHz, 500 ms = 8000000 ticks */
#define SYSTICK_100_MS_TICKS    1599999ul  /* Assuming a system clock of 16 MHz, 100 ms = 160000 ticks */
#define SYSTICK_50_MS_TICKS     799999ul   /* Assuming a system clock of 16 MHz, 50 ms = 80000 ticks */
#define SYSTICK_10_MS_TICKS     159999ul   /* Assuming a system clock of 16 MHz, 10 ms = 16000 ticks */
#define SYSTICK_1_MS_TICKS      15999ul    /* Assuming a system clock of 16 MHz, 1 ms = 1600 ticks */
#define SYSTICK_650_US_TICKS    10399ul    /* Assuming a system clock of 16 MHz, 650 us = 10400 ticks */
#define SYSTICK_500_US_TICKS    7999ul     /* Assuming a system clock of 16 MHz, 500 us = 8000 ticks */
#define SYSTICK_100_US_TICKS    1599ul  /* Assuming a system clock of 16 MHz, 100 us = 1600 ticks */

#define SYSTICK_EXTERNAL_CLOCK  (uint8_t)0
#define SYSTICK_PROCESSOR_CLOCK (uint8_t)1

#define SYSTICK_ENABLE          (uint8_t)0
#define SYSTICK_DISABLE         (uint8_t)1

#define SYSTICK_TICKINT_ENABLE  (uint8_t)0
#define SYSTICK_TICKINT_DISABLE (uint8_t)1

/* Registers values: */
#define SYSTICK_CSR_ENABLE      (1 << 0)
#define SYSTICK_CSR_TICKINT     (1 << 1)
#define SYSTICK_CSR_CLKSOURCE   (1 << 2)
#define SYSTICK_RVR_MASK        (0xFFFFFF)
#define SYSTICK_CVR_MASK        (0xFFFFFF)

#define SYSTICK_RESET_VALUE     (uint32_t)0ul
#define SYSTICK_MAX_RELOAD      (uint32_t)0xFFFFFFul

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void      SysTick_Init    (SysTick_ConfigType ticks);
extern uint32_t  SysTick_GetTick (void);
extern void      SysTick_Delay   (uint32_t delay);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 