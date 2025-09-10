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
#ifndef APB1_PERIPHERALS_H_
#define APB1_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef TIM2_BASE_ADDRESS
 #define TIM2_OFFSET              (0x0ul)
 #define TIM2_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM2_OFFSET)
#endif

#ifndef TIM3_BASE_ADDRESS
 #define TIM3_OFFSET              (0x400ul)
 #define TIM3_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM3_OFFSET)
#endif

#ifndef TIM4_BASE_ADDRESS
 #define TIM4_OFFSET              (0x800ul)
 #define TIM4_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM4_OFFSET)
#endif

#ifndef TIM5_BASE_ADDRESS
 #define TIM5_OFFSET              (0xC00ul)
 #define TIM5_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM5_OFFSET)
#endif

#ifndef TIM6_BASE_ADDRESS
 #define TIM6_OFFSET              (0x1000ul)
 #define TIM6_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM6_OFFSET)
#endif

#ifndef TIM7_BASE_ADDRESS
 #define TIM7_OFFSET              (0x1400ul)
 #define TIM7_BASE_ADDRESS        (APB1_BASE_ADDRESS + TIM7_OFFSET)
#endif

#ifndef TIM12_BASE_ADDRESS
 #define TIM12_OFFSET             (0x1800ul)
 #define TIM12_BASE_ADDRESS       (APB1_BASE_ADDRESS + TIM12_OFFSET)
#endif

#ifndef TIM13_BASE_ADDRESS
 #define TIM13_OFFSET             (0x1C00ul)
 #define TIM13_BASE_ADDRESS       (APB1_BASE_ADDRESS + TIM13_OFFSET)
#endif

#ifndef TIM14_BASE_ADDRESS
 #define TIM14_OFFSET             (0x2000ul)
 #define TIM14_BASE_ADDRESS       (APB1_BASE_ADDRESS + TIM14_OFFSET)
#endif

#ifndef RTC_BKP_R_BASE_ADDRESS
 #define RTC_BKP_R_OFFSET         (0x2800ul)
 #define RTC_BKP_R_BASE_ADDRESS   (APB1_BASE_ADDRESS + RTC_BKP_R_OFFSET)
#endif

#ifndef WWDG_BASE_ADDRESS
 #define WWDG_OFFSET              (0x2C00ul)
 #define WWDG_BASE_ADDRESS        (APB1_BASE_ADDRESS + WWDG_OFFSET)
#endif

#ifndef IWDG_BASE_ADDRESS
 #define IWDG_OFFSET              (0x3000ul)
 #define IWDG_BASE_ADDRESS        (APB1_BASE_ADDRESS + IWDG_OFFSET)
#endif

#ifndef I2S2EXT_BASE_ADDRESS
 #define I2S2EXT_OFFSET           (0x3400ul)
 #define I2S2EXT_BASE_ADDRESS     (APB1_BASE_ADDRESS + I2S2EXT_OFFSET)
#endif

#ifndef SPI2_I2S2_BASE_ADDRESS
 #define SPI2_I2S2_OFFSET         (0x3800ul)
 #define SPI2_I2S2_BASE_ADDRESS   (APB1_BASE_ADDRESS + SPI2_I2S2_OFFSET)
#endif

#ifndef SPI3_I2S3_BASE_ADDRESS
 #define SPI3_I2S3_OFFSET         (0x3c00ul)
 #define SPI3_I2S3_BASE_ADDRESS   (APB1_BASE_ADDRESS + SPI3_I2S3_OFFSET)
#endif

#ifndef I2S3EXT_BASE_ADDRESS
 #define I2S3EXT_OFFSET           (0x4000ul)
 #define I2S3EXT_BASE_ADDRESS     (APB1_BASE_ADDRESS + I2S3EXT_OFFSET)
#endif

#ifndef USART2_BASE_ADDRESS
 #define USART2_OFFSET            (0x4400ul)
 #define USART2_BASE_ADDRESS      (APB1_BASE_ADDRESS + USART2_OFFSET)
#endif

#ifndef USART3_BASE_ADDRESS
 #define USART3_OFFSET            (0x4800ul)
 #define USART3_BASE_ADDRESS      (APB1_BASE_ADDRESS + USART3_OFFSET)
#endif

#ifndef UART4_BASE_ADDRESS
 #define UART4_OFFSET             (0x4C00ul)
 #define UART4_BASE_ADDRESS       (APB1_BASE_ADDRESS + UART4_OFFSET)
#endif

#ifndef UART5_BASE_ADDRESS
 #define UART5_OFFSET             (0x5000ul)
 #define UART5_BASE_ADDRESS       (APB1_BASE_ADDRESS + UART5_OFFSET)
#endif

#ifndef I2C1_BASE_ADDRESS
 #define I2C1_OFFSET              (0x5400ul)
 #define I2C1_BASE_ADDRESS        (APB1_BASE_ADDRESS + I2C1_OFFSET)
#endif

#ifndef I2C2_BASE_ADDRESS
 #define I2C2_OFFSET              (0x5800ul)
 #define I2C2_BASE_ADDRESS        (APB1_BASE_ADDRESS + I2C2_OFFSET)
#endif

#ifndef I2C3_BASE_ADDRESS
 #define I2C3_OFFSET              (0x5C00ul)
 #define I2C3_BASE_ADDRESS        (APB1_BASE_ADDRESS + I2C3_OFFSET)
#endif

#ifndef CAN1_BASE_ADDRESS
 #define CAN1_OFFSET              (0x6400ul)
 #define CAN1_BASE_ADDRESS        (APB1_BASE_ADDRESS + CAN1_OFFSET)
#endif

#ifndef CAN2_BASE_ADDRESS
 #define CAN2_OFFSET              (0x6800ul)
 #define CAN2_BASE_ADDRESS        (APB1_BASE_ADDRESS + CAN2_OFFSET)
#endif

#ifndef PWR_BASE_ADDRESS
 #define PWR_OFFSET               (0x7000ul)
 #define PWR_BASE_ADDRESS         (APB1_BASE_ADDRESS + PWR_OFFSET)
#endif

#ifndef DAC_BASE_ADDRESS
 #define DAC_OFFSET               (0x7400ul)
 #define DAC_BASE_ADDRESS         (APB1_BASE_ADDRESS + DAC_OFFSET)
#endif

#ifndef UART7_BASE_ADDRESS
 #define UART7_OFFSET             (0x7800ul)
 #define UART7_BASE_ADDRESS       (APB1_BASE_ADDRESS + UART7_OFFSET)
#endif

#ifndef UART8_BASE_ADDRESS
 #define UART8_OFFSET             (0x7C00ul)
 #define UART8_BASE_ADDRESS       (APB1_BASE_ADDRESS + UART8_OFFSET)
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