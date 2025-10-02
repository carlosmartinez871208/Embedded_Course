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
#include "Register.h"
#include "rcc.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t moder;
    __IO uint32_t otyper;
    __IO uint32_t ospeedr;
    __IO uint32_t pupdr;
    __IO uint32_t idr;
    __IO uint32_t odr;
    __IO uint32_t bsrr;
    __IO uint32_t lckr;
    __IO uint32_t afrl;
    __IO uint32_t afrh;
}GPIO_TypeDef;

typedef struct
{
    uint8_t Port;           /* Port identifier */
    uint8_t Pin;            /* Pin number */
    uint8_t Mode;           /* Pin mode */
    uint8_t OutputType;     /* Pin output type */
    uint8_t OutputSpeed;    /* Pin output speed */
    uint8_t PullUpDown;     /* Pin pull-up/pull-down resistor configuration */
    uint8_t Alternate;  /* Pin alternate function mode */
}Pin_ConfigType;

typedef struct
{
    const    Pin_ConfigType* PinConfigList;
    uint8_t  NumberOfPins;
}Port_ConfigType;


/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define PORTA                           ((uint8_t)0u)
#define PORTB                           ((uint8_t)1u)
#define PORTC                           ((uint8_t)2u)
#define PORTD                           ((uint8_t)3u)
#define PORTE                           ((uint8_t)4u)
#define PORTF                           ((uint8_t)5u)
#define PORTG                           ((uint8_t)6u)
#define PORTH                           ((uint8_t)7u)
#define PORTI                           ((uint8_t)8u)

#define PIN0                           ((uint8_t)0u)
#define PIN1                           ((uint8_t)1u)  /* Pin 1 selected    */
#define PIN2                           ((uint8_t)2u)  /* Pin 2 selected    */
#define PIN3                           ((uint8_t)3u)  /* Pin 3 selected    */
#define PIN4                           ((uint8_t)4u)  /* Pin 4 selected    */
#define PIN5                           ((uint8_t)5u)  /* Pin 5 selected    */
#define PIN6                           ((uint8_t)6u)  /* Pin 6 selected    */
#define PIN7                           ((uint8_t)7u)  /* Pin 7 selected    */
#define PIN8                           ((uint8_t)8u)  /* Pin 8 selected    */
#define PIN9                           ((uint8_t)9u)  /* Pin 9 selected   */
#define PIN10                          ((uint8_t)10u)  /* Pin 10 selected   */
#define PIN11                          ((uint8_t)11u)  /* Pin 11 selected   */
#define PIN12                          ((uint8_t)12u)  /* Pin 12 selected   */
#define PIN13                          ((uint8_t)13u)  /* Pin 13 selected   */
#define PIN14                          ((uint8_t)14u)  /* Pin 14 selected   */
#define PIN15                          ((uint8_t)15u)  /* Pin 15 selected   */

/* Reset pin: */
#define RESET                          ((uint8_t)0x0u)  /* Pin set as reset     */

/* Pin modes: */
#define INPUT                          ((uint8_t)0x0u)  /* Pin set as input     */
#define OUTPUT                         ((uint8_t)0x1u)  /* Pin set as output    */
#define ALTERNATE                      ((uint8_t)0x2u)  /* Pin set as alternate  */
#define ANALOG                         ((uint8_t)0x3u)  /* Pin set as analog     */

/* Pin output type: */
#define PUSH_PULL                      ((uint8_t)0x0u)  /* Pin set as push-pull output */
#define OPEN_DRAIN                     ((uint8_t)0x1u)  /* Pin set as open-drain output */

/* Pin output speed: */
#define LOW_SPEED                      ((uint8_t)0x0u)  /* Pin set as low speed     */
#define MEDIUM_SPEED                   ((uint8_t)0x1u)  /* Pin set as medium speed    */
#define HIGH_SPEED                     ((uint8_t)0x2u)  /* Pin set as high speed  */
#define VERY_HIGH_SPEED                ((uint8_t)0x3u)  /* Pin set as very high speed */

/* Pin pull-up/pull-down resistors: */
#define NO_PULL                        ((uint8_t)0x0u)  /* No pull-up/pull-down resistor */
#define PULL_UP                        ((uint8_t)0x1u)  /* Pull-up resistor enabled */
#define PULL_DOWN                      ((uint8_t)0x2u)  /* Pull-down resistor enabled */
#define RESERVED                       ((uint8_t)0x3u)  /* Reserved */

/* Lock register: */
#define LOCK                            ((uint8_t)0x1u)  /* Lock register enabled */
#define UNLOCK                          ((uint8_t)0x0u)  /* Lock register disabled */
#define LCKK                            ((uint32_t)1<<16)  /* Lock key bit */

/* Alternate function modes:  */
#define AF0                             ((uint8_t)0x0u)  /* Alternate function 0  */
#define AF1                             ((uint8_t)0x1u)  /* Alternate function 1  */
#define AF2                             ((uint8_t)0x2u)  /* Alternate function 2  */
#define AF3                             ((uint8_t)0x3u)  /* Alternate function 3  */
#define AF4                             ((uint8_t)0x4u)  /* Alternate function 4  */
#define AF5                             ((uint8_t)0x5u)  /* Alternate function 5  */
#define AF6                             ((uint8_t)0x6u)  /* Alternate function 6  */
#define AF7                             ((uint8_t)0x7u)  /* Alternate function 7  */
#define AF8                             ((uint8_t)0x8u)  /* Alternate function 8  */
#define AF9                             ((uint8_t)0x9u)  /* Alternate function 9  */
#define AF10                            ((uint8_t)0xAu)  /* Alternate function 10 */
#define AF11                            ((uint8_t)0xBu)  /* Alternate function 11 */
#define AF12                            ((uint8_t)0xCu)  /* Alternate function 12 */
#define AF13                            ((uint8_t)0xDu)  /* Alternate function 13 */
#define AF14                            ((uint8_t)0xEu)  /* Alternate function 14 */
#define AF15                            ((uint8_t)0xFu)  /* Alternate function 15 */

#define ALTERNATE_SYSTEM                AF0
#define ALTERNATE_TIM1                  AF1
#define ALTERNATE_TIM2                  AF1
#define ALTERNATE_TIM3                  AF2
#define ALTERNATE_TIM4                  AF2
#define ALTERNATE_TIM5                  AF2
#define ALTERNATE_TIM8                  AF3
#define ALTERNATE_TIM9                  AF3
#define ALTERNATE_TIM10                 AF3
#define ALTERNATE_TIM11                 AF3
#define ALTERNATE_I2C1                  AF4
#define ALTERNATE_I2C2                  AF4
#define ALTERNATE_I2C3                  AF4
#define ALTERNATE_SPI1                  AF5
#define ALTERNATE_SPI2                  AF5
#define ALTERNATE_SPI3                  AF6
#define ALTERNATE_SPI4                  AF5
#define ALTERNATE_SPI5                  AF6
#define ALTERNATE_SPI6                  AF6
#define ALTERNATE_USART1                AF7
#define ALTERNATE_USART2                AF7
#define ALTERNATE_USART3                AF7
#define ALTERNATE_UART4                 AF8
#define ALTERNATE_UART5                 AF8
#define ALTERNATE_USART6                AF8
#define ALTERNATE_UART7                 AF8
#define ALTERNATE_UART8                 AF8
#define ALTERNATE_CAN1                  AF9
#define ALTERNATE_CAN2                  AF9
#define ALTERNATE_TIM12                 AF9
#define ALTERNATE_TIM13                 AF9
#define ALTERNATE_TIM14                 AF9
#define ALTERNATE_OTG_FS                AF10
#define ALTERNATE_OTG_HS                AF10
#define ALTERNATE_ETH                   AF11
#define ALTERNATE_FSMC                  AF12
#define ALTERNATE_SDIO                  AF12
#define ALTERNATE_DCMI                  AF13
#define ALTERNATE_LTDC                  AF14
#define ALTERNATE_EVENTOUT              AF15

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/
static GPIO_TypeDef* const GPIO_Base[9] = {
    (GPIO_TypeDef *) GPIOA_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOB_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOC_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOD_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOE_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOF_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOG_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOH_BASE_ADDRESS,
    (GPIO_TypeDef *) GPIOI_BASE_ADDRESS
};

static const uint32_t RCC_GPIO_Clk_Enable[9] = {
    0x00000001ul, /* ... 00000001*/
    0x00000002ul, /* ... 00000010*/
    0x00000004ul,
    0x00000008ul,
    0x00000010ul,
    0x00000020ul,
    0x00000040ul,
    0x00000080ul,
    0x00000100ul,
};

static const uint32_t GPIO_1Bit_control[16][2] = {
    {0xFFFFFFFEul,0x00000001ul}, /* .... 1111 1110*/
    {0xFFFFFFFDul,0x00000002ul}, /* .... 1111 1101*/
    {0xFFFFFFFBul,0x00000004ul},
    {0xFFFFFFF7ul,0x00000008ul},
    {0xFFFFFFEFul,0x00000010ul},
    {0xFFFFFFDFul,0x00000020ul},
    {0xFFFFFFBFul,0x00000040ul},
    {0xFFFFFF7Ful,0x00000080ul},
    {0xFFFFFEFFul,0x00000100ul},
    {0xFFFFFDFFul,0x00000200ul},
    {0xFFFFFBFFul,0x00000400ul},
    {0xFFFFF7FFul,0x00000800ul},
    {0xFFFFEFFFul,0x00001000ul},
    {0xFFFFDFFFul,0x00002000ul},
    {0xFFFFBFFFul,0x00004000ul},
    {0xFFFF7FFFul,0x00008000ul} /* ....1111 0111 1111 1111 1111, .... 0000 1000 0000 0000 0000*/
};

static const uint32_t GPIO_2Bit_control[16][4] = 
{
  /* reset,         output,      alternate,    analog*/
    {0xFFFFFFFCul, 0x00000001ul, 0x00000002ul, 0x00000003ul}, /* .... 1111 1100, .... 0000 0001, .... 0000 0010, .... 0000 0011*/
    {0xFFFFFFF3ul, 0x00000004ul, 0x00000008ul, 0x0000000Cul},
    {0xFFFFFFCFul, 0x00000010ul, 0x00000020ul, 0x00000030ul},
    {0xFFFFFF3Ful, 0x00000040ul, 0x00000080ul, 0x000000C0ul},
    {0xFFFFFCFFul, 0x00000100ul, 0x00000200ul, 0x00000300ul},
    {0xFFFFF3FFul, 0x00000400ul, 0x00000800ul, 0x00000C00ul},
    {0xFFFFCFFFul, 0x00001000ul, 0x00002000ul, 0x00003000ul},
    {0xFFFF3FFFul, 0x00004000ul, 0x00008000ul, 0x0000C000ul},
    {0xFFFCFFFFul, 0x00010000ul, 0x00020000ul, 0x00030000ul},
    {0xFFF3FFFFul, 0x00040000ul, 0x00080000ul, 0x000C0000ul},
    {0xFFCFFFFFul, 0x00100000ul, 0x00200000ul, 0x00300000ul},
    {0xFF3FFFFFul, 0x00400000ul, 0x00800000ul, 0x00C00000ul},
    {0xFCFFFFFFul, 0x01000000ul, 0x02000000ul, 0x03000000ul},
    {0xF3FFFFFFul, 0x04000000ul, 0x08000000ul, 0x0C000000ul},
    {0xCFFFFFFFul, 0x10000000ul, 0x20000000ul, 0x30000000ul},
    {0x3FFFFFFFul, 0x40000000ul, 0x80000000ul, 0xC0000000ul} /* 0011 1111 ... 1111, 0100 0000 ... 0000, 1000 ... 0000, 1100 ... 0000 */
};

static const uint32_t GPIO_4Bit_control[8][16] = {
    {0xFFFFFFF0ul, 0x00000001ul, 0x00000002ul, 0x00000003ul, 0x00000004ul, 0x00000005ul, 0x00000006ul, 0x00000007ul, 0x00000008ul, 0x00000009ul, 0x0000000Aul, 0x0000000Bul, 0x0000000Cul, 0x0000000Dul, 0x0000000Eul, 0x0000000Ful},
    {0xFFFFFF0Ful, 0x00000010ul, 0x00000020ul, 0x00000030ul, 0x00000040ul, 0x00000050ul, 0x00000060ul, 0x00000070ul, 0x00000080ul, 0x00000090ul, 0x000000A0ul, 0x000000B0ul, 0x000000C0ul, 0x000000D0ul, 0x000000E0ul, 0x000000F0ul},
    {0xFFFFF0FFul, 0x00000100ul, 0x00000200ul, 0x00000300ul, 0x00000400ul, 0x00000500ul, 0x00000600ul, 0x00000700ul, 0x00000800ul, 0x00000900ul, 0x00000A00ul, 0x00000B00ul, 0x00000C00ul, 0x00000D00ul, 0x00000E00ul, 0x00000F00ul},
    {0xFFFF0FFFul, 0x00001000ul, 0x00002000ul, 0x00003000ul, 0x00004000ul, 0x00005000ul, 0x00006000ul, 0x00007000ul, 0x00008000ul, 0x00009000ul, 0x0000A000ul, 0x0000B000ul, 0x0000C000ul, 0x0000D000ul, 0x0000E000ul, 0x0000F000ul},
    {0xFFF0FFFFul, 0x00010000ul, 0x00020000ul, 0x00030000ul, 0x00040000ul, 0x00050000ul, 0x00060000ul, 0x00070000ul, 0x00080000ul, 0x00090000ul, 0x000A0000ul, 0x000B0000ul, 0x000C0000ul, 0x000D0000ul, 0x000E0000ul, 0x000F0000ul},
    {0xFFF0FFFFul, 0x00100000ul, 0x00200000ul, 0x00300000ul, 0x00400000ul, 0x00500000ul, 0x00600000ul, 0x00700000ul, 0x00800000ul, 0x00900000ul, 0x00A00000ul, 0x00B00000ul, 0x00C00000ul, 0x00D00000ul, 0x00E00000ul, 0x00F00000ul},
    {0xF0FFFFFFul, 0x01000000ul, 0x02000000ul, 0x03000000ul, 0x04000000ul, 0x05000000ul, 0x06000000ul, 0x07000000ul, 0x08000000ul, 0x09000000ul, 0x0A000000ul, 0x0B000000ul, 0x0C000000ul, 0x0D000000ul, 0x0E000000ul, 0x0F000000ul},
    {0x0FFFFFFFul, 0x10000000ul, 0x20000000ul, 0x30000000ul, 0x40000000ul, 0x50000000ul, 0x60000000ul, 0x70000000ul, 0x80000000ul, 0x90000000ul, 0xA0000000ul, 0xB0000000ul, 0xC0000000ul, 0xD0000000ul, 0xE0000000ul, 0xF0000000ul}
};

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
extern void    Port_Init             (const Port_ConfigType* ConfigPtr);
extern void    Port_ConfigurePin     (const Pin_ConfigType*  PinConfig);
extern void    Port_TooglePin        (const Pin_ConfigType*  PinConfig);
extern void    Port_SetPinState      (const Pin_ConfigType*  PinConfig,uint8_t State);
extern boolean Port_GetPinState      (const Pin_ConfigType*  PinConfig);

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 