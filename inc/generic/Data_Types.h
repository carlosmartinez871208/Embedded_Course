/*********************************************************************************************************************/
/*                                                  HEADER GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: Data_Types.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* Data_Types.h:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Unsigned types: */
/* 32 bits data type. */
#ifndef uint32_t
 typedef unsigned long  uint32_t;
#endif
/* 16 bits data type. */
#ifndef uint16_t
 typedef unsigned short uint16_t;
#endif
/* 8 bits data type. */
#ifndef uint8_t
 typedef unsigned char  uint8_t;
#endif

/* Signed types: */
/* 32 bits data type. */
#ifndef sint32_t
 typedef signed long  sint32_t;
#endif
/* 16 bits data type. */
#ifndef sint16_t
 typedef signed short sint16_t;
#endif
/* 8 bits data type. */
#ifndef sint8_t
 typedef signed char  sint8_t;
#endif

/* Bool (boolean) type: */
#ifndef bool
 typedef uint8_t bool;
#endif

/* Function pointer type definition, points a void function type. */
#ifndef func_ptr
 typedef void(*func_ptr)(void);
#endif

/* IO definitions */
/* Defines read only permissions. */
#define __I volatile const
/* Defines write only permissions. */
#define __O volatile
/* Defines read / write permissions. */
#define __IO volatile

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#ifndef TRUE
 #define TRUE            (bool)1ul;
#endif

#ifndef FALSE
 #define FALSE           (bool)0ul;
#endif

/* NULL pointer type definition. */
#ifndef NULL
 #define NULL (void*)(0u)
#endif 

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS FALSE;
#endif

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

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