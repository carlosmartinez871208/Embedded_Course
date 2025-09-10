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
#ifndef APB2_PERIPHERALS_H_
#define APB2_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef TIM1_BASE_ADDRESS
 #define TIM1_OFFSET              (0x0ul)
 #define TIM1_BASE_ADDRESS        (APB2_BASE_ADDRESS + TIM1_OFFSET)
#endif

#ifndef TIM8_BASE_ADDRESS
 #define TIM8_OFFSET              (0x400ul)
 #define TIM8_BASE_ADDRESS        (APB2_BASE_ADDRESS + TIM8_OFFSET)
#endif

#ifndef USART1_BASE_ADDRESS
 #define USART1_OFFSET            (0x1000ul)
 #define USART1_BASE_ADDRESS      (APB2_BASE_ADDRESS + USART1_OFFSET)
#endif

#ifndef USART6_BASE_ADDRESS
 #define USART6_OFFSET            (0x1400ul)
 #define USART6_BASE_ADDRESS      (APB2_BASE_ADDRESS + USART6_OFFSET)
#endif

#ifndef ADC_BASE_ADDRESS
 #define ADC_OFFSET               (0x2000ul)
 #define ADC_BASE_ADDRESS         (APB2_BASE_ADDRESS + ADC_OFFSET)
#endif

#ifndef SDO_BASE_ADDRESS
 #define SDO_OFFSET               (0x2C00ul)
 #define SDO_BASE_ADDRESS         (APB2_BASE_ADDRESS + SDO_OFFSET)
#endif

#ifndef SPI1_BASE_ADDRESS
 #define SPI1_OFFSET              (0x3000ul)
 #define SPI1_BASE_ADDRESS        (APB2_BASE_ADDRESS + SPI1_OFFSET)
#endif

#ifndef SPI4_BASE_ADDRESS
 #define SPI4_OFFSET              (0x3400ul)
 #define SPI4_BASE_ADDRESS        (APB2_BASE_ADDRESS + SPI4_OFFSET)
#endif

#ifndef SYSCFG_BASE_ADDRESS
 #define SYSCFG_OFFSET            (0x3800ul)
 #define SYSCFG_BASE_ADDRESS      (APB2_BASE_ADDRESS + SYSCFG_OFFSET)
#endif

#ifndef EXTI_BASE_ADDRESS
 #define EXTI_OFFSET              (0x3C00ul)
 #define EXTI_BASE_ADDRESS        (APB2_BASE_ADDRESS + EXTI_OFFSET)
#endif

#ifndef TIM9_BASE_ADDRESS
 #define TIM9_OFFSET              (0x4000ul)
 #define TIM9_BASE_ADDRESS        (APB2_BASE_ADDRESS + TIM9_OFFSET)
#endif

#ifndef TIM10_BASE_ADDRESS
 #define TIM10_OFFSET             (0x4400ul)
 #define TIM10_BASE_ADDRESS       (APB2_BASE_ADDRESS + TIM10_OFFSET)
#endif

#ifndef TIM11_BASE_ADDRESS
 #define TIM11_OFFSET              (0x4800ul)
 #define TIM11_BASE_ADDRESS        (APB2_BASE_ADDRESS + TIM11_OFFSET)
#endif

#ifndef SPI5_BASE_ADDRESS
 #define SPI5_OFFSET              (0x5000ul)
 #define SPI5_BASE_ADDRESS        (APB2_BASE_ADDRESS + SPI5_OFFSET)
#endif

#ifndef SPI6_BASE_ADDRESS
 #define SPI6_OFFSET              (0x5400ul)
 #define SPI6_BASE_ADDRESS        (APB2_BASE_ADDRESS + SPI6_OFFSET)
#endif

#ifndef SAI1_BASE_ADDRESS
 #define SAI1_OFFSET              (0x5800ul)
 #define SAI1_BASE_ADDRESS        (APB2_BASE_ADDRESS + SAI1_OFFSET)
#endif

#ifndef LCD_TFT_BASE_ADDRESS
 #define LCD_TFT_OFFSET           (0x6800ul)
 #define LCD_TFT_BASE_ADDRESS     (APB2_BASE_ADDRESS + LCD_TFT_OFFSET)
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