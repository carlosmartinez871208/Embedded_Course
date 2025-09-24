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
 #define TIM2_OFFSET               (0x0ul)
 #define TIM2_BASE_ADDRESS         (APB1_BASE_ADDRESS + TIM2_OFFSET)
#endif

#ifndef TIM3_BASE_ADDRESS
 #define TIM3_OFFSET               (0x400ul)
 #define TIM3_BASE_ADDRESS         (APB1_BASE_ADDRESS + TIM3_OFFSET)
#endif

#ifndef TIM6_BASE_ADDRESS
 #define TIM6_OFFSET               (0x1000ul)
 #define TIM6_BASE_ADDRESS         (APB1_BASE_ADDRESS + TIM6_OFFSET)
#endif

#ifndef TIM7_BASE_ADDRESS
 #define TIM7_OFFSET               (0x1400ul)
 #define TIM7_BASE_ADDRESS         (APB1_BASE_ADDRESS + TIM7_OFFSET)
#endif

#ifndef RTC_BASE_ADDRESS
 #define RTC_OFFSET                (0x2800ul)
 #define RTC_BASE_ADDRESS          (APB1_BASE_ADDRESS + RTC_OFFSET)
#endif

#ifndef WWDG_BASE_ADDRESS
 #define WWDG_OFFSET               (0x2C00ul)
 #define WWDG_BASE_ADDRESS         (APB1_BASE_ADDRESS + WWDG_OFFSET)
#endif

#ifndef IWDG_BASE_ADDRESS
 #define IWDG_OFFSET               (0x3000ul)
 #define IWDG_BASE_ADDRESS         (APB1_BASE_ADDRESS + IWDG_OFFSET)
#endif

#ifndef USART2_BASE_ADDRESS
 #define USART2_OFFSET             (0x4400ul)
 #define USART2_BASE_ADDRESS       (APB1_BASE_ADDRESS + USART2_OFFSET)
#endif

#ifndef USART3_BASE_ADDRESS
 #define USART3_OFFSET             (0x4800ul)
 #define USART3_BASE_ADDRESS       (APB1_BASE_ADDRESS + USART3_OFFSET)
#endif

#ifndef I2C1_BASE_ADDRESS
 #define I2C1_OFFSET               (0x5400ul)
 #define I2C1_BASE_ADDRESS         (APB1_BASE_ADDRESS + I2C1_OFFSET)
#endif

#ifndef CAN_BASE_ADDRESS
 #define CAN_OFFSET                (0x6400ul)
 #define CAN_BASE_ADDRESS          (APB1_BASE_ADDRESS + CAN_OFFSET)
#endif

#ifndef PWR_BASE_ADDRESS
 #define PWR_OFFSET                (0x7000ul)
 #define PWR_BASE_ADDRESS          (APB1_BASE_ADDRESS + PWR_OFFSET)
#endif

#ifndef DAC1_BASE_ADDRESS
 #define DAC1_OFFSET               (0x7400ul)
 #define DAC1_BASE_ADDRESS         (APB1_BASE_ADDRESS + DAC1_OFFSET)
#endif

#ifndef DAC2_BASE_ADDRESS
 #define DAC2_OFFSET               (0x9800ul)
 #define DAC2_BASE_ADDRESS         (APB1_BASE_ADDRESS + DAC2_OFFSET)
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