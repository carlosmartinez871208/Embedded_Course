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
#include "Std_Types.h"
#include "peripherals.h"
#include "Register.h"

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t CR;        /* Clock control register */
    __IO uint32_t CFGR;      /* Clock configuration register */
    __IO uint32_t CIR;       /* Clock interrupt register */
    __IO uint32_t APB2RSTR;  /* APB2 peripheral reset register */
    __IO uint32_t APB1RSTR;  /* APB1 peripheral reset register */
    __IO uint32_t AHBENR;    /* AHB peripheral clock enable register */
    __IO uint32_t APB2ENR;   /* APB2 peripheral clock enable register */
    __IO uint32_t APB1ENR;   /* APB1 peripheral clock enable register */
    __IO uint32_t BDCR;      /* Backup domain control register */
    __IO uint32_t CSR;       /* Control/status register */
    __IO uint32_t AHBRSTR;   /* AHB peripheral reset register */
    __IO uint32_t CFGR2;     /* Clock configuration register 2 */
    __IO uint32_t CFGR3;     /* Clock configuration register 3 */
}RCC_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#ifndef RCC
#define RCC ((RCC_TypeDef*)RCC_BASE_ADDRESS)
#endif

static const uint32_t RCC_GPIO_Clk_Enable[5] = {
    0x00020000ul, /* 0000 0000 0000 0010 0000 0000 0000 0000 */
    0x00040000ul, /* 0000 0000 0000 0100 0000 0000 0000 0000 */
    0x00080000ul, /* 0000 0000 0000 1000 0000 0000 0000 0000 */
    0x00100000ul, /* 0000 0000 0001 0000 0000 0000 0000 0000 */
    0x00400000ul, /* 0000 0000 0100 0000 0000 0000 0000 0000 */
};

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void    RCC_SetPortClockState    (const uint8_t Port, const uint8_t State);
extern boolean RCC_GetPortClockState    (const uint8_t Port);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 