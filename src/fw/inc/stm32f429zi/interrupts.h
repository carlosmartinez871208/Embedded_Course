/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: interrupts.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-03-23 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* interrupts.h:
               contains system definitions like, enable/disable interrupts.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef INTERRUPTS_H_
 #define INTERRUPTS_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/
#include "Std_types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t iser0;
    __IO uint32_t iser1;
    __IO uint32_t iser2;
    __IO uint32_t iser3;
    __IO uint32_t iser4;
    __IO uint32_t iser5;
    __IO uint32_t iser6;
    __IO uint32_t iser7;
}nvic_iser; /* Interrupt Set-enable Registers */

typedef struct
{
    __IO uint32_t icer0;
    __IO uint32_t icer1;
    __IO uint32_t icer2;
    __IO uint32_t icer3;
    __IO uint32_t icer4;
    __IO uint32_t icer5;
    __IO uint32_t icer6;
    __IO uint32_t icer7;
}nvic_icer; /* Interrupt Clear-enable Registers */

typedef struct
{
    __IO uint32_t ispr0;
    __IO uint32_t ispr1;
    __IO uint32_t ispr2;
    __IO uint32_t ispr3;
    __IO uint32_t ispr4;
    __IO uint32_t ispr5;
    __IO uint32_t ispr6;
    __IO uint32_t ispr7;
}nvic_ispr; /* Interrupt Set-pending Registers */

typedef struct
{
    __IO uint32_t icpr0;
    __IO uint32_t icpr1;
    __IO uint32_t icpr2;
    __IO uint32_t icpr3;
    __IO uint32_t icpr4;
    __IO uint32_t icpr5;
    __IO uint32_t icpr6;
    __IO uint32_t icpr7;
}nvic_icpr; /* Interrupt Clear-pending Registers */

typedef struct
{
    __IO uint32_t iabr0;
    __IO uint32_t iabr1;
    __IO uint32_t iabr2;
    __IO uint32_t iabr3;
    __IO uint32_t iabr4;
    __IO uint32_t iabr5;
    __IO uint32_t iabr6;
    __IO uint32_t iabr7;
}nvic_iabr; /* Interrupt Active Bit Registers */

typedef struct
{
    __IO uint32_t ipr0;
    __IO uint32_t ipr1;
    __IO uint32_t ipr2;
    __IO uint32_t ipr3;
    __IO uint32_t ipr4;
    __IO uint32_t ipr5;
    __IO uint32_t ipr6;
    __IO uint32_t ipr7;
    __IO uint32_t ipr8;
    __IO uint32_t ipr9;
    __IO uint32_t ipr10;
    __IO uint32_t ipr11;
    __IO uint32_t ipr12;
    __IO uint32_t ipr13;
    __IO uint32_t ipr14;
    __IO uint32_t ipr15;
    __IO uint32_t ipr16;
    __IO uint32_t ipr17;
    __IO uint32_t ipr18;
    __IO uint32_t ipr19;
    __IO uint32_t ipr20;
    __IO uint32_t ipr21;
    __IO uint32_t ipr22;
    __IO uint32_t ipr23;
    __IO uint32_t ipr24;
    __IO uint32_t ipr25;
    __IO uint32_t ipr26;
    __IO uint32_t ipr27;
    __IO uint32_t ipr28;
    __IO uint32_t ipr29;
    __IO uint32_t ipr30;
    __IO uint32_t ipr31;
    __IO uint32_t ipr32;
    __IO uint32_t ipr33;
    __IO uint32_t ipr34;
    __IO uint32_t ipr35;
    __IO uint32_t ipr36;
    __IO uint32_t ipr37;
    __IO uint32_t ipr38;
    __IO uint32_t ipr39;
    __IO uint32_t ipr40;
    __IO uint32_t ipr41;
    __IO uint32_t ipr42;
    __IO uint32_t ipr43;
    __IO uint32_t ipr44;
    __IO uint32_t ipr45;
    __IO uint32_t ipr46;
    __IO uint32_t ipr47;
    __IO uint32_t ipr48;
    __IO uint32_t ipr49;
    __IO uint32_t ipr50;
    __IO uint32_t ipr51;
    __IO uint32_t ipr52;
    __IO uint32_t ipr53;
    __IO uint32_t ipr54;
    __IO uint32_t ipr55;
    __IO uint32_t ipr56;
    __IO uint32_t ipr57;
    __IO uint32_t ipr58;
    __IO uint32_t ipr59;
}nvic_ipr;

#ifndef NVIC_ISER
 #define NVIC_ISER_OFFSET (0x0ul)
 #define NVIC_ISER        ((__IO nvic_iser*)NVIC_BASE_ADDRESS+NVIC_ISER_OFFSET)
#endif

#ifndef NVIC_ICER
 #define NVIC_ICER_OFFSET (0x80ul)
 #define NVIC_ICER        ((__IO nvic_icer*)NVIC_BASE_ADDRESS+NVIC_ICER_OFFSET)
#endif

#ifndef NVIC_ISPR
 #define NVIC_ISPR_OFFSET (0x100ul)
 #define NVIC_ISPR        ((__IO nvic_ispr*)NVIC_BASE_ADDRESS+NVIC_ISPR_OFFSET)
#endif

#ifndef NVIC_ICPR
 #define NVIC_ICPR_OFFSET (0x180ul)
 #define NVIC_ICPR        ((__IO nvic_icpr*)NVIC_BASE_ADDRESS+NVIC_ICPR_OFFSET)
#endif

#ifndef NVIC_IABR
 #define NVIC_IABR_OFFSET (0x200ul)
 #define NVIC_IABR        ((__IO nvic_icpr*)NVIC_BASE_ADDRESS+NVIC_IABR_OFFSET)
#endif

#ifndef NVIC_IPR
 #define NVIC_IPR_OFFSET (0x300ul)
 #define NVIC_IPR        ((__IO nvic_ipr*)NVIC_BASE_ADDRESS+NVIC_IPR_OFFSET)
#endif

#ifndef NVIC_STIR
 #define NVIC_STIR_OFFSET (0xE00ul)
 #define NVIC_STIR        (*(__IO uint32_t*)NVIC_BASE_ADDRESS+NVIC_STIR_OFFSET)
#endif

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* Systick NVIC*/
typedef enum
{
    NMI_IRQn                  = -14,
    MemManage_IRQN            = -12,
    BusFault_IRQn             = -11,
    UsageFault_IRQn           = -10,
    SVCall_IRQn               = -5,
    DebugMonitor_IRQn         = -4,
    PendSV_IRQn               = -2,
    SysTick_IRQn              = -1,
    WWDG_IRQn                 = 0,
    EXTI_PVD_IRQn             = 1,
    EXTI_TAMP_STAMP_IRQn      = 2,
    EXTI_RTC_WKUP_IRQn        = 3,
    FLASH_IRQn                = 4,
    RCC_IRQn                  = 5,
    EXTI0_IRQn                = 6,
    EXTI1_IRQn                = 7,
    EXTI2_IRQn                = 8,
    EXTI3_IRQn                = 9,
    EXTI4_IRQn                = 10,
    DMA1_Stream0_IRQn         = 11,
    DMA1_Stream1_IRQn         = 12,
    DMA1_Stream2_IRQn         = 13,
    DMA1_Stream3_IRQn         = 14,
    DMA1_Stream4_IRQn         = 15,
    DMA1_Stream5_IRQn         = 16,
    DMA1_Stream6_IRQn         = 17,
    ADC_IRQn                  = 18,
    CAN1_TX_IRQn              = 19,
    CAN1_RX0_IRQn             = 20,
    CAN1_RX1_IRQn             = 21,
    CAN1_SCE_IRQn             = 22,
    EXTI9_5_IRQn              = 23,
    TIM1_BRK_TIM9_IRQn        = 24,
    TIM1_UP_TIM10_IRQn        = 25,
    TIM1_TRG_COM_TIM11_IRQn   = 26,
    TIM1_CC_IRQn              = 27,
    TIM2_IRQn                 = 28,
    TIM3_IRQn                 = 29,
    TIM4_IRQn                 = 30,
    I2C1_EV_IRQn              = 31,
    I2C1_ER_IRQn              = 32,
    I2C2_EV_IRQn              = 33,
    I2C2_ER_IRQn              = 34,
    SPI1_IRQn                 = 35,
    SPI2_IRQn                 = 36,
    USART1_IRQn               = 37,
    USART2_IRQn               = 38,
    USART3_IRQn               = 39,
    EXTI15_10_IRQn            = 40,
    RTC_Alarm_IRQn            = 41,
    OTG_FS_WKUP_IRQn          = 42,
    TIM8_BRK_TIM12_IRQn       = 43,
    TIM8_UP_TIM13_IRQn        = 44,
    TIM8_TRG_COM_TIM14_IRQn   = 45,
    TIM8_CC_IRQn              = 46,
    DMA1_Stream7_IRQn         = 47,
    FSMC_IRQn                 = 48,
    SDIO_IRQn                 = 49,
    TIM5_IRQn                 = 50,
    SPI3_IRQn                 = 51,
    USART4_IRQn               = 52,
    USART5_IRQn               = 53,
    TIM6_DAC_IRQn             = 54,
    TIM7_IRQn                 = 55,
    DMA2_Stream0_IRQn         = 56,
    DMA2_Stream1_IRQn         = 57,
    DMA2_Stream2_IRQn         = 58,
    DMA2_Stream3_IRQn         = 59,
    DMA2_Stream4_IRQn         = 60,
    ETH_IRQn                  = 61,
    ETH_WKUP_IRQn             = 62,
    CAN2_TX_IRQn              = 63,
    CAN2_RX0_IRQn             = 64,
    CAN2_RX1_IRQn             = 65,
    CAN2_SCE_IRQn             = 66,
    OTG_FS_IRQn               = 67,
    DMA2_Stream5_IRQn         = 68,
    DMA2_Stream6_IRQn         = 69,
    DMA2_Stream7_IRQn         = 70,
    USART6_IRQn               = 71,
    I2C3_EV_IRQn              = 72,
    I2C3_ER_IRQn              = 73,
    OTG_HS_EP1_OUT_IRQn       = 74,
    OTG_HS_EP1_IN_IRQn        = 75,
    OTG_HS_WKUP_IRQn          = 76,
    OTG_HS_IRQn               = 77,
    DCMI_IRQn                 = 78,
    CRYP_IRQn                 = 79,
    HASH_RNG_IRQn             = 80,
    FPU_IRQn                  = 81,
    USART7_IRQn               = 82,
    USART8_IRQn               = 83,
    SPI4_IRQn                 = 84,
    SPI5_IRQn                 = 85,
    SPI6_IRQn                 = 86,
    SAI1_IRQn                 = 87,
    LCD_TFT_IRQn              = 88,
    LCD_TFT_ERR_IRQn          = 89,
    DMA2D_IRQn                = 90
}IRQn_type;

#define NVIC_IPR0_RESET       (0xFFFFFF00ul)
#define NVIC_IPR1_RESET       (0xFFFF00FFul)
#define NVIC_IPR2_RESET       (0xFF00FFFFul)
#define NVIC_IPR3_RESET       (0x00FFFFFFul)

/*                         Special functions                         */
/* The compiler attempts to inline the function, regardless of the characteristics of the function. 
** However, the compiler does not inline a function if doing so causes problems. For example, a 
** recursive function is inlined into itself only once. 
** The inline keyword suggests to the compiler that the function be inlined. Normally, when a 
** function is called, the current contents of the registers are pushed (copied) to memory. 
** Once the function returns, they are popped (copied back).
** Inline functions are not always important, but it is good to understand them. The basic idea is 
** to save time at a cost in space. Inline functions are a lot like a placeholder. Once you define 
** an inline function, using the 'inline' keyword, whenever you call that function the compiler will 
** replace the function call with the actual code from the function. 
*/
/* Enable IRQ interrupts: by clearing the I-bit in the CPSR. */
__attribute__((__always_inline__)) static inline void __enable_irq (void)
{
    asm volatile ("cpsie i" : : : "memory");
}

/* Enable IRQ interrupts: by setting the I-bit in the CPSR. */
__attribute__((__always_inline__)) static inline void __disable_irq (void)
{
    asm volatile ("cpsid i" : : : "memory");
}

/* Set Main Stack pointer */
__attribute__((__always_inline__)) static inline void __set_MSP (unsigned int MainStackTop)
{
    asm volatile ("MSR msp, %0\n" : : "r" (MainStackTop) : "sp");
}

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