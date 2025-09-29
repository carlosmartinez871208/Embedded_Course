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
#ifndef RCC_H_
#define RCC_H_
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
    __IO uint32_t cr;
    __IO uint32_t pllcfgr;
    __IO uint32_t cfgr;
    __IO uint32_t cir;
    __IO uint32_t ahb1rstr;
    __IO uint32_t ahb2rstr;
    __IO uint32_t ahb3rstr;
    __IO uint32_t dummy0;
    __IO uint32_t apb1rstr;
    __IO uint32_t apb2rstr;
    __IO uint32_t dummy1;
    __IO uint32_t dummy2;
    __IO uint32_t ahb1enr;
    __IO uint32_t ahb2enr;
    __IO uint32_t ahb3enr;
    __IO uint32_t dummy3;
    __IO uint32_t apb1enr;
    __IO uint32_t apb2enr;
    __IO uint32_t dummy4;
    __IO uint32_t dummy5;
    __IO uint32_t ahb1lpenr;
    __IO uint32_t ahb2lpenr;
    __IO uint32_t ahb3lpenr;
    __IO uint32_t dummy6;
    __IO uint32_t apb1lpenr;
    __IO uint32_t apb2lpenr;
    __IO uint32_t dummy7;
    __IO uint32_t dummy8;
    __IO uint32_t bdcr;
    __IO uint32_t csr;
    __IO uint32_t dummy9;
    __IO uint32_t dumm10;
    __IO uint32_t sscgr;
    __IO uint32_t plli2scfgr;
    __IO uint32_t pllsaicfgr;
    __IO uint32_t dckcfgr;
}RCC_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define RCC                             ((RCC_TypeDef *) RCC_BASE_ADDRESS)
/* Green LED is connected to GPIOG pin 13 */
#define RCC_AHB1ENR_GPIOG_EN            ((uint32_t) (1 << 6))

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void RCC_EnableGPIO(const uint32_t GPIO_EN);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 