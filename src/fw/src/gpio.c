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
static void Port_SetPinMode     (const Pin_ConfigType* PinConfig);
static void Port_SetPinOutputType(const Pin_ConfigType* PinConfig);
static void Port_SetPinSpeed    (const Pin_ConfigType* PinConfig);
static void Port_SetPinPullUpDown(const Pin_ConfigType* PinConfig);
static void Port_SetPinAlternate (const Pin_ConfigType* PinConfig);

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void Port_SetPinMode (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Pin Mode: */
    GPIOx->moder  = REG_MASKING(GPIOx->moder,   GPIO_2Bit_control[pin][0]); /* Clear mode bits */
    if(INPUT!=PinConfig->Mode) /* If not input mode */
    {
        GPIOx->moder  = REG_ENABLE_BITS(GPIOx->moder, GPIO_2Bit_control[pin][PinConfig->Mode]); /* Set mode bits */
    }
    else
    {/* Input mode, do nothing */}
}

void Port_SetPinOutputType(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Output Type: */
    GPIOx->otyper = REG_MASKING(GPIOx->otyper, GPIO_1Bit_control[pin][0]); /* Clear output type bit */
    if(PUSH_PULL!=PinConfig->OutputType) /* If not push-pull */
    {
        GPIOx->otyper = REG_ENABLE_BITS(GPIOx->otyper, GPIO_1Bit_control[pin][1]); /* Set output type bit */
    }
    else
    {/* Push-pull, do nothing */}
}

void Port_SetPinSpeed(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Speed: */
    GPIOx->ospeedr = REG_MASKING(GPIOx->ospeedr, GPIO_2Bit_control[pin][0]); /* Clear speed bits */
    if(LOW_SPEED!=PinConfig->OutputSpeed) /* If not low speed */
    {
        GPIOx->ospeedr = REG_ENABLE_BITS(GPIOx->ospeedr, GPIO_2Bit_control[pin][PinConfig->OutputSpeed]); /* Set speed bits */
    }
    else
    {/* Low speed, do nothing */}
}

void Port_SetPinPullUpDown(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Pull-up/Pull-down: */
    GPIOx->pupdr = REG_MASKING(GPIOx->pupdr, GPIO_2Bit_control[pin][0]); /* Clear pull-up/pull-down bits */
    if(NO_PULL!=PinConfig->PullUpDown) /* If not pull-up */
    {
        GPIOx->pupdr = REG_ENABLE_BITS(GPIOx->pupdr, GPIO_2Bit_control[pin][PinConfig->PullUpDown]); /* Set pull-up/pull-down bits */
    }
    else
    {/* No pull-up/pull-down, do nothing */}
}

void Port_SetPinAlternate (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Alternate Function: */
    if(ALTERNATE==PinConfig->Mode)
    {
        if(pin < 8)
        {
            /* GPIOx->afr[0] */
            GPIOx->afrl = REG_MASKING(GPIOx->afrl, GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
            if(AF0!=PinConfig->Alternate)
            {
                GPIOx->afrl = REG_ENABLE_BITS(GPIOx->afrl, GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
            }
            else
            {/* AF0, do nothing */}
        }
        else
        {
            /* GPIOx->afr[1] */
            GPIOx->afrh = REG_MASKING(GPIOx->afrh, GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
            if(AF0!=PinConfig->Alternate)
            {
                GPIOx->afrh = REG_ENABLE_BITS(GPIOx->afrh, GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
            }
            else
            {/* AF0, do nothing */}
        }
    }
}

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/
void    Port_Init             (const Port_ConfigType* ConfigPtr)
{
    uint16_t i;
    for(i=0; i<ConfigPtr->NumberOfPins; i++)
    {
        Port_ConfigurePin(&ConfigPtr->PinConfigList[i]);
    }
}

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
    Port_SetPinMode(PinConfig);
    /* Configure Output Type: */
    if(OUTPUT==PinConfig->Mode || ALTERNATE==PinConfig->Mode)
    {
        Port_SetPinOutputType(PinConfig);
        /* Configure Speed: */
        Port_SetPinSpeed(PinConfig);
        /* Configure Pull-up/Pull-down: */
        Port_SetPinPullUpDown(PinConfig);
        /* Configure Alternate Function: */
        if(ALTERNATE==PinConfig->Mode)
        {
            Port_SetPinAlternate(PinConfig);
        }
        else
        {/* Not alternate mode, do nothing */}
    }
    else
    {/* Input or Analog mode, do nothing */}
}

void    Port_TooglePin        (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Toggle the output data register */
    GPIOx->odr ^= GPIO_1Bit_control[pin][1];
}

void    Port_SetPinState      (const Pin_ConfigType* PinConfig,uint8_t State)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    if (State)
    {
        GPIOx->odr |= GPIO_1Bit_control[pin][1]; // Set bit
    }
    else
    {
        GPIOx->odr &= ~GPIO_1Bit_control[pin][1]; // Reset bit
    }
}

boolean Port_GetPinState      (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    return REG_COMPARER(GPIOx->idr & GPIO_1Bit_control[pin][1]);
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 