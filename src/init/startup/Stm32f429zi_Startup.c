/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: Stm32f429zi_Startup.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* Stm32f429zi_Startup.c:
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
#include "Data_Types.h"
#include "main.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
/* Into linker script can be found _estack
** it is used as the first vector table element.
*/
extern uint32_t _estack;

/* Global symbols */
extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/
uint32_t sys_clk_freq;

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
/* Default Handler prototype */
void Default_Handler(void);

/* System init function */
void SystemInit (void);

/* Reset Handler prototype */
void Reset_Handler (void);

/* Interrupt and exceptions handlers: from GNU collections page 601 (GCC-14.2)
** Provide 'weak' aliases for each exception handler to the deault handler.
** As they are 'weak' aliasses, any function with the same name will override
** this definition.
** The alias attribute causes the declaration to be emitted as an alias for another
** symbol, which must have been previously declared with the same type, and for
** variables, also the same size and aligment.
** Declaring an alias with different type than the target is undefined and my be
** diagnosed.
** e.g.
** void __f () {}
** void f () __attribute__ ((weak,alias ("__f")))
*/
/* Exceptions */
void NMI_Handler                      (void)__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler                (void)__attribute__((weak,alias("Default_Handler")));
void MemManage_Handler                (void)__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler                 (void)__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler               (void)__attribute__((weak,alias("Default_Handler")));
void SVCall_Handler                   (void)__attribute__((weak,alias("Default_Handler")));
void DebugMonitor_Handler             (void)__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler                   (void)__attribute__((weak,alias("Default_Handler")));
void Systick_Handler                  (void)__attribute__((weak,alias("Default_Handler")));

/* Interrupst */
void WWDOG_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void EXTI_PVD_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void EXTI_TAMP_STAMP_IRQHandler       (void)__attribute__((weak,alias("Default_Handler")));
void EXTI_RTC_WKUP_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler                   (void)__attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream0_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream1_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream2_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream3_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream4_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream5_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream6_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void ADC_IRQHandler                   (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_TX_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_RX0_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler             (void)__attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler             (void)__attribute__((weak,alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler           (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler    (void)__attribute__((weak,alias("Default_Handler")));
void TIM8_CC_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Stream7_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void FSMC_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void USART4_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void USART5_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream0_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void ETH_IRQHandler                   (void)__attribute__((weak,alias("Default_Handler")));
void ETH_WKUP_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_TX_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_RX0_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_RX1_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void CAN2_SCE_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void OTG_FS_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream5_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream6_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA2_Stream7_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void USART6_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void I2C3_EV_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C3_ER_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler        (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler         (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler           (void)__attribute__((weak,alias("Default_Handler")));
void OTG_HS_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void DCMI_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void CRYP_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void HASH_RNG_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void FPU_IRQHandler                   (void)__attribute__((weak,alias("Default_Handler")));
void USART7_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void USART8_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void SPI4_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SPI5_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SPI6_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void SAI1_IRQHandler                  (void)__attribute__((weak,alias("Default_Handler")));
void LCD_TFT_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void LCD_TFT_ERR_IRQHandler           (void)__attribute__((weak,alias("Default_Handler")));
void DMA2D_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* From GNU Compiler Collection: pages 674 and 675 (GCC-14.2)
** Normally, the compiler places the objects it generates in sections like data and bss.
** Sometimes, however, you need additional sections, or you need certain
** particular variables to appear in special sections, for example to map to special
** hardware.
** The section attribute specifies that a variable (or function) lives
** in a particular section. For example, this small program uses several specific
** section names:
** e.g.
** int init_data __attribute__ ((section ("INITDATA")));
*/
/* Vector table, see reference manual page: 378 */
uint32_t vector_table[] __attribute__((section (".isr_vector_table"))) = {\
    (uint32_t) &_estack,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &HardFault_Handler,
    (uint32_t) &MemManage_Handler,
    (uint32_t) &BusFault_Handler,
    (uint32_t) &UsageFault_Handler,
    0u,
    0u,
    0u,
    0u,
    (uint32_t) &SVCall_Handler,
    (uint32_t) &DebugMonitor_Handler,
    0u,
    (uint32_t) &PendSV_Handler,
    (uint32_t) &Systick_Handler,
    (uint32_t) &WWDOG_IRQHandler,/* Microcontroller interrupts. WWDOG address: 0x0000 0040*/
    (uint32_t) &EXTI_PVD_IRQHandler,
    (uint32_t) &EXTI_TAMP_STAMP_IRQHandler,
    (uint32_t) &EXTI_RTC_WKUP_IRQHandler,
    (uint32_t) &FLASH_IRQHandler,
    (uint32_t) &RCC_IRQHandler,
    (uint32_t) &EXTI0_IRQHandler,
    (uint32_t) &EXTI1_IRQHandler,
    (uint32_t) &EXTI2_IRQHandler,
    (uint32_t) &EXTI3_IRQHandler,
    (uint32_t) &EXTI4_IRQHandler,
    (uint32_t) &DMA1_Stream0_IRQHandler,
    (uint32_t) &DMA1_Stream1_IRQHandler,
    (uint32_t) &DMA1_Stream2_IRQHandler,
    (uint32_t) &DMA1_Stream3_IRQHandler,
    (uint32_t) &DMA1_Stream4_IRQHandler,
    (uint32_t) &DMA1_Stream5_IRQHandler,
    (uint32_t) &DMA1_Stream6_IRQHandler,
    (uint32_t) &ADC_IRQHandler,
    (uint32_t) &CAN1_TX_IRQHandler,
    (uint32_t) &CAN1_RX0_IRQHandler,
    (uint32_t) &CAN1_RX1_IRQHandler,
    (uint32_t) &CAN1_SCE_IRQHandler,
    (uint32_t) &EXTI9_5_IRQHandler,
    (uint32_t) &TIM1_BRK_TIM9_IRQHandler,
    (uint32_t) &TIM1_UP_TIM10_IRQHandler,
    (uint32_t) &TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t) &TIM1_CC_IRQHandler,
    (uint32_t) &TIM2_IRQHandler,
    (uint32_t) &TIM3_IRQHandler,
    (uint32_t) &TIM4_IRQHandler,
    (uint32_t) &I2C1_EV_IRQHandler,
    (uint32_t) &I2C1_ER_IRQHandler,
    (uint32_t) &I2C2_EV_IRQHandler,
    (uint32_t) &I2C2_ER_IRQHandler,
    (uint32_t) &SPI1_IRQHandler,
    (uint32_t) &SPI2_IRQHandler,
    (uint32_t) &USART1_IRQHandler,
    (uint32_t) &USART2_IRQHandler,
    (uint32_t) &USART3_IRQHandler,
    (uint32_t) &EXTI15_10_IRQHandler,
    (uint32_t) &RTC_Alarm_IRQHandler,
    (uint32_t) &OTG_FS_WKUP_IRQHandler,
    (uint32_t) &TIM8_BRK_TIM12_IRQHandler,
    (uint32_t) &TIM8_UP_TIM13_IRQHandler,
    (uint32_t) &TIM8_TRG_COM_TIM14_IRQHandler,
    (uint32_t) &TIM8_CC_IRQHandler,
    (uint32_t) &DMA1_Stream7_IRQHandler,
    (uint32_t) &FSMC_IRQHandler,
    (uint32_t) &SDIO_IRQHandler,
    (uint32_t) &TIM5_IRQHandler,
    (uint32_t) &SPI3_IRQHandler,
    (uint32_t) &USART4_IRQHandler,
    (uint32_t) &USART5_IRQHandler,
    (uint32_t) &TIM6_DAC_IRQHandler,
    (uint32_t) &TIM7_IRQHandler,
    (uint32_t) &DMA2_Stream0_IRQHandler,
    (uint32_t) &DMA2_Stream1_IRQHandler,
    (uint32_t) &DMA2_Stream2_IRQHandler,
    (uint32_t) &DMA2_Stream3_IRQHandler,
    (uint32_t) &DMA2_Stream4_IRQHandler,
    (uint32_t) &ETH_IRQHandler,
    (uint32_t) &ETH_WKUP_IRQHandler,
    (uint32_t) &CAN2_TX_IRQHandler,
    (uint32_t) &CAN2_RX0_IRQHandler,
    (uint32_t) &CAN2_RX1_IRQHandler,
    (uint32_t) &CAN2_SCE_IRQHandler,
    (uint32_t) &OTG_FS_IRQHandler,
    (uint32_t) &DMA2_Stream5_IRQHandler,
    (uint32_t) &DMA2_Stream6_IRQHandler,
    (uint32_t) &DMA2_Stream7_IRQHandler,
    (uint32_t) &USART6_IRQHandler,
    (uint32_t) &I2C3_EV_IRQHandler,
    (uint32_t) &I2C3_ER_IRQHandler,
    (uint32_t) &OTG_HS_EP1_OUT_IRQHandler,
    (uint32_t) &OTG_HS_EP1_IN_IRQHandler,
    (uint32_t) &OTG_HS_WKUP_IRQHandler,
    (uint32_t) &OTG_HS_IRQHandler,
    (uint32_t) &DCMI_IRQHandler,
    (uint32_t) &CRYP_IRQHandler,
    (uint32_t) &HASH_RNG_IRQHandler,
    (uint32_t) &FPU_IRQHandler,
    (uint32_t) &USART7_IRQHandler,
    (uint32_t) &USART8_IRQHandler,
    (uint32_t) &SPI4_IRQHandler,
    (uint32_t) &SPI5_IRQHandler,
    (uint32_t) &SPI6_IRQHandler,
    (uint32_t) &SAI1_IRQHandler,
    (uint32_t) &LCD_TFT_IRQHandler,
    (uint32_t) &LCD_TFT_ERR_IRQHandler,
    (uint32_t) &DMA2D_IRQHandler
};

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
/* Defining default handler:*/
void Default_Handler(void)
{
    while(1)
    {
        /* Do nothing */
    }
}

/* 
** System initilization:
*/
void SystemInit (void)
{
    /* Add here the system initilizations: */
}

/* Entry point: Reset_Handler */
void Reset_Handler (void)
{
    uint32_t data_mem_size = (uint32_t)&_edata - (uint32_t)&_sdata; /* Size of data section */
    uint32_t bss_mem_size  = (uint32_t)&_ebss - (uint32_t)&_sbss;   /* Size of bss section */

    uint32_t *p_src_mem    = (uint32_t*)&_etext;
    uint32_t *p_dest_mem   = (uint32_t*)&_sdata;

    for(uint32_t i=0u;i<data_mem_size;i++)
    {
        /* Copy data section from FLASH to SRAM */
        *p_dest_mem++ = * p_src_mem++;
    }

    p_dest_mem = (uint32_t*)&_sbss;
    for(uint32_t i=0;i<bss_mem_size; i++)
    {
        /* Initialize .bss section to 0u*/
        *p_dest_mem++ = 0u;
    }
    /* Calling system initialization */
    (void)SystemInit();
    /*Calling main function.*/
    (void)main();
    while(1);
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 