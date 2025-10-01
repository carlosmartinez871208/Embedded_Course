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
#include "gpio.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                   Local Variables                                                 */
/*********************************************************************************************************************/

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/
void Port_ConfigurePin     (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;

    /* Check if GPIO clock is enabled: */
    if(!(RCC->ahb1enr & RCC_GPIO_Clk_Enable[PinConfig->Port])) {
        /* GPIO clock is disabled, enable it: */
        RCC->ahb1enr |= RCC_GPIO_Clk_Enable[PinConfig->Port];
    }
    else
    {/* GPIO clock is enabled, do nothing */}
    /* Configure Pin Mode: */
    GPIOx->moder  = REG_MASKING(GPIOx->moder,   GPIO_2Bit_control[pin][0]); /* Clear mode bits */
    if(INPUT!=PinConfig->Mode) /* If not input mode */
    {
        GPIOx->moder  = REG_ENABLE_BITS(GPIOx->moder, GPIO_2Bit_control[pin][PinConfig->Mode]); /* Set mode bits */
    }
    /* Configure Output Type: */
    if(OUTPUT==PinConfig->Mode || ALTERNATE==PinConfig->Mode)
    {
        GPIOx->otyper = REG_MASKING(GPIOx->otyper, GPIO_1Bit_control[pin][0]); /* Clear output type bit */
        if(PUSH_PULL!=PinConfig->OutputType) /* If not push-pull */
        {
            GPIOx->otyper = REG_ENABLE_BITS(GPIOx->otyper, GPIO_1Bit_control[pin][1]); /* Set output type bit */
        }
        /* Configure Speed: */
        GPIOx->ospeedr = REG_MASKING(GPIOx->ospeedr, GPIO_2Bit_control[pin][0]); /* Clear speed bits */
        if(LOW_SPEED!=PinConfig->OutputSpeed) /* If not low speed */
        {
            GPIOx->ospeedr = REG_ENABLE_BITS(GPIOx->ospeedr, GPIO_2Bit_control[pin][PinConfig->OutputSpeed]); /* Set speed bits */
        }
        /* Configure Pull-up/Pull-down: */
        GPIOx->pupdr = REG_MASKING(GPIOx->pupdr, GPIO_2Bit_control[pin][0]); /* Clear pull-up/pull-down bits */
        if(NO_PULL!=PinConfig->PullUpDown) /* If not pull-up */
        {
            GPIOx->pupdr = REG_ENABLE_BITS(GPIOx->pupdr, GPIO_2Bit_control[pin][PinConfig->PullUpDown]); /* Set pull-up/pull-down bits */
        }
        /* Configure Alternate Function: */
        if(ALTERNATE==PinConfig->Mode)
        {
            if(pin < 8)
            {
                GPIOx->afrl = REG_MASKING(GPIOx->afrl, GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
                GPIOx->afrl = REG_ENABLE_BITS(GPIOx->afrl, GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
            }
            else
            {
                GPIOx->afrh = REG_MASKING(GPIOx->afrh, GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
                GPIOx->afrh = REG_ENABLE_BITS(GPIOx->afrh, GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
            }
        }
    }
}

void    Port_TooglePin        (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Toggle the output data register */
    GPIOx->odr ^= GPIO_1Bit_control[pin][1];
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 