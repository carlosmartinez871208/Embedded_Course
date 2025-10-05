/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.c:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/

/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "systick.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                   Local Variables                                                 */
/*********************************************************************************************************************/
volatile static uint32_t current_tick   = 0ul;
volatile static uint32_t current_tick_p = 0ul;

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/

void SysTick_Init(SysTick_ConfigType config)
{
    if (SYSTICK_ENABLE==config.Enable)
    {
        __disable_irq();
        /* Disable SysTick during setup */
        SYSTICK->csr &= ~SYSTICK_RESET_VALUE;
        /* Clear current value register */
        SYSTICK->cvr = SYSTICK_RESET_VALUE;
        /* Set reload register */
        SYSTICK->rvr = (config.ReloadValue & SYSTICK_MAX_RELOAD);
        /* Set clock source */
        if (SYSTICK_PROCESSOR_CLOCK==config.ClkSource)
        {
            SYSTICK->csr |= SYSTICK_CSR_CLKSOURCE;
        }
        else
        {
            SYSTICK->csr &= ~SYSTICK_CSR_CLKSOURCE;
        }
        /* Enable or disable interrupt */
        if (SYSTICK_TICKINT_ENABLE==config.TickInt)
        {
            SYSTICK->csr |= SYSTICK_CSR_TICKINT;
        }
        else
        {
            SYSTICK->csr &= ~SYSTICK_CSR_TICKINT;
        }
        /* Enable SysTick */
        SYSTICK->csr |= SYSTICK_CSR_ENABLE;
        __enable_irq();
    }
    else
    {/* Do nothing */}
}

void SysTick_Handler(void)
{
    /* Increment tick count */
    current_tick+=1ul;
}

uint32_t SysTick_GetTick(void)
{
    __disable_irq();
    current_tick_p = current_tick;
    __enable_irq();
    return current_tick_p;
}

void SysTick_Delay(uint32_t delay)
{
    unsigned int tickstart = SysTick_GetTick();
    unsigned int wait = delay;
    if(wait < SYSTICK_MAX_RELOAD)
    {
        wait += 1ul;
    }
    else
    {/* Do nothing */}
    while ((SysTick_GetTick() - tickstart) < wait){}
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 