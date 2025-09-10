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
#ifndef AHB1_PERIPHERALS_H_
#define AHB1_PERIPHERALS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "bus.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
#ifndef GPIOA_BASE_ADDRESS
 #define GPIOA_OFFSET              (0x0ul)
 #define GPIOA_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOA_OFFSET)
#endif

#ifndef GPIOB_BASE_ADDRESS
 #define GPIOB_OFFSET              (0x400ul)
 #define GPIOB_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOB_OFFSET)
#endif

#ifndef GPIOC_BASE_ADDRESS
 #define GPIOC_OFFSET              (0x800ul)
 #define GPIOC_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOC_OFFSET)
#endif

#ifndef GPIOD_BASE_ADDRESS
 #define GPIOD_OFFSET              (0xC00ul)
 #define GPIOD_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOD_OFFSET)
#endif

#ifndef GPIOE_BASE_ADDRESS
 #define GPIOE_OFFSET              (0x1000ul)
 #define GPIOE_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOE_OFFSET)
#endif

#ifndef GPIOF_BASE_ADDRESS
 #define GPIOF_OFFSET              (0x1400ul)
 #define GPIOF_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOF_OFFSET)
#endif

#ifndef GPIOG_BASE_ADDRESS
 #define GPIOG_OFFSET              (0x1800ul)
 #define GPIOG_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOG_OFFSET)
#endif

#ifndef GPIOH_BASE_ADDRESS
 #define GPIOH_OFFSET              (0x1C00ul)
 #define GPIOH_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOH_OFFSET)
#endif

#ifndef GPIOI_BASE_ADDRESS
 #define GPIOI_OFFSET              (0x2000ul)
 #define GPIOI_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOI_OFFSET)
#endif

#ifndef GPIOJ_BASE_ADDRESS
 #define GPIOJ_OFFSET              (0x2400ul)
 #define GPIOJ_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOJ_OFFSET)
#endif

#ifndef GPIOK_BASE_ADDRESS
 #define GPIOK_OFFSET              (0x2800ul)
 #define GPIOK_BASE_ADDRESS        (AHB1_BASE_ADDRESS + GPIOK_OFFSET)
#endif

#ifndef CRC_BASE_ADDRESS
 #define CRC_OFFSET                (0x3000ul)
 #define CRC_BASE_ADDRESS          (AHB1_BASE_ADDRESS + CRC_OFFSET)
#endif

#ifndef RCC_BASE_ADDRESS
 #define RCC_OFFSET                (0x3800ul)
 #define RCC_BASE_ADDRESS          (AHB1_BASE_ADDRESS + RCC_OFFSET)
#endif

#ifndef FLASH_IR_BASE_ADDRESS
 #define FLASH_IR_OFFSET           (0x3C00ul)
 #define FLASH_IR_BASE_ADDRESS     (AHB1_BASE_ADDRESS + FLASH_IR_OFFSET)
#endif

#ifndef BKPSRAM_BASE_ADDRESS
 #define BKPSRAM_OFFSET            (0x4000ul)
 #define BKPSRAM_BASE_ADDRESS      (AHB1_BASE_ADDRESS + BKPSRAM_OFFSET)
#endif

#ifndef DMA1_BASE_ADDRESS
 #define DMA1_OFFSET               (0x6000ul)
 #define DMA1_BASE_ADDRESS         (AHB1_BASE_ADDRESS + DMA1_OFFSET)
#endif

#ifndef DMA2_BASE_ADDRESS
 #define DMA2_OFFSET               (0x6400ul)
 #define DMA2_BASE_ADDRESS         (AHB1_BASE_ADDRESS + DMA2_OFFSET)
#endif

#ifndef ETHERNET_MAC_BASE_ADDRESS
 #define ETHERNET_MAC_OFFSET       (0x8000ul)
 #define ETHERNET_MAC_BASE_ADDRESS (AHB1_BASE_ADDRESS + ETHERNET_MAC_OFFSET)
#endif

#ifndef DMA2D_BASE_ADDRESS
 #define DMA2D_OFFSET              (0xB000ul)
 #define DMA2D_BASE_ADDRESS        (AHB1_BASE_ADDRESS + DMA2D_OFFSET)
#endif

#ifndef USB_OTG_HS_BASE_ADDRESS
 #define USB_OTG_HS_OFFSET         (0x20000ul)
 #define USB_OTG_HS_BASE_ADDRESS   (AHB1_BASE_ADDRESS + USB_OTG_HS_OFFSET)
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