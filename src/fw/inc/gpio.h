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
#ifndef GPIO_H_
#define GPIO_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "Data_Types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */    
    __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];  /*!< GPIO alternate function registers,      Address offset: 0x20-0x24 */
    __IO uint32_t BRR;      /*!< GPIO port bit reset register,          Address offset: 0x28      */
}GPIO_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#ifndef GPIOA_TYPE
#define GPIOA_TYPE ((GPIO_TypeDef*)GPIOA_BASE_ADDRESS)
#endif

#ifndef GPIOB_TYPE
#define GPIOB_TYPE ((GPIO_TypeDef*)GPIOB_BASE_ADDRESS)
#endif

#ifndef GPIOC_TYPE
#define GPIOC_TYPE ((GPIO_TypeDef*)GPIOC_BASE_ADDRESS)
#endif

#ifndef GPIOD_TYPE
#define GPIOD_TYPE ((GPIO_TypeDef*)GPIOD_BASE_ADDRESS)
#endif

#ifndef GPIOF_TYPE
#define GPIOF_TYPE ((GPIO_TypeDef*)GPIOF_BASE_ADDRESS)
#endif

#define GPIO_PORTA_MODER_5_1 (1U << 11)
#define GPIO_PORTA_MODER_5_0 (1U << 10)

#define GPIO_PORTA_ODR_5     (1U << 5)

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void GPIO_config_pin(void);
extern void GPIO_toggle(void);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 