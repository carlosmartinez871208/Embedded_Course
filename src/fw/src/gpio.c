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
    GPIOx->MODER  = REG_MASKING(GPIOx->MODER,   GPIO_2Bit_control[pin][0]); /* Clear mode bits */
    if(INPUT!=PinConfig->Mode) /* If not input mode */
    {
        GPIOx->MODER  = REG_ENABLE_BITS(GPIOx->MODER, GPIO_2Bit_control[pin][PinConfig->Mode]); /* Set mode bits */
    }
    else
    {/* Input mode, do nothing */}
}

void Port_SetPinOutputType(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Output Type: */
    GPIOx->OTYPER = REG_MASKING(GPIOx->OTYPER, GPIO_1Bit_control[pin][0]); /* Clear output type bit */
    if(PUSH_PULL!=PinConfig->OutputType) /* If not push-pull */
    {
        GPIOx->OTYPER = REG_ENABLE_BITS(GPIOx->OTYPER, GPIO_1Bit_control[pin][1]); /* Set output type bit */
    }
    else
    {/* Push-pull, do nothing */}
}

void Port_SetPinSpeed(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Speed: */
    GPIOx->OSPEEDR = REG_MASKING(GPIOx->OSPEEDR, GPIO_2Bit_control[pin][0]); /* Clear speed bits */
    if(LOW_SPEED!=PinConfig->OutputSpeed) /* If not low speed */
    {
        GPIOx->OSPEEDR = REG_ENABLE_BITS(GPIOx->OSPEEDR, GPIO_2Bit_control[pin][PinConfig->OutputSpeed]); /* Set speed bits */
    }
    else
    {/* Low speed, do nothing */}
}

void Port_SetPinPullUpDown(const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Configure Pull-up/Pull-down: */
    GPIOx->PUPDR = REG_MASKING(GPIOx->PUPDR, GPIO_2Bit_control[pin][0]); /* Clear pull-up/pull-down bits */
    if(NO_PULL!=PinConfig->PullUpDown) /* If not pull-up */
    {
        GPIOx->PUPDR = REG_ENABLE_BITS(GPIOx->PUPDR, GPIO_2Bit_control[pin][PinConfig->PullUpDown]); /* Set pull-up/pull-down bits */
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
            GPIOx->AFR[0] = REG_MASKING(GPIOx->AFR[0], GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
            if(AF0!=PinConfig->Alternate)
            {
                GPIOx->AFR[0] = REG_ENABLE_BITS(GPIOx->AFR[0], GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
            }
            else
            {/* AF0, do nothing */}
        }
        else
        {
            /* GPIOx->AFR[1] */
            GPIOx->AFR[1] = REG_MASKING(GPIOx->AFR[1], GPIO_4Bit_control[pin][0]); /* Clear alternate function bits */
            if(AF0!=PinConfig->Alternate)
            {
                GPIOx->AFR[1] = REG_ENABLE_BITS(GPIOx->AFR[1], GPIO_4Bit_control[pin][PinConfig->Alternate]); /* Set alternate function bits */
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
    for(uint16_t i=0; i<ConfigPtr->NumberOfPins; i++)
    {
        Port_ConfigurePin(&ConfigPtr->PinConfigList[i]);
    }
}

void Port_ConfigurePin     (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    /* Enable clock for the corresponding GPIO port */
    RCC_SetPortClockState(PinConfig->Port, STD_ON);
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
    GPIOx->ODR ^= GPIO_1Bit_control[pin][1];
}

void    Port_SetPinState      (const Pin_ConfigType* PinConfig,uint8_t State)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    if (State)
    {
        GPIOx->ODR |= GPIO_1Bit_control[pin][1]; // Set bit
    }
    else
    {
        GPIOx->ODR &= ~GPIO_1Bit_control[pin][1]; // Reset bit
    }
}

boolean Port_GetPinState      (const Pin_ConfigType* PinConfig)
{
    GPIO_TypeDef* GPIOx = GPIO_Base[PinConfig->Port];
    uint8_t pin = PinConfig->Pin;
    return REG_COMPARER(GPIOx->IDR & GPIO_1Bit_control[pin][1]);
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 