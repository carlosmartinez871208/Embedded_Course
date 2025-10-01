/*********************************************************************************************************************/
/*                                                  HEADER GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: Std_Types.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* Std_Types.h:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "Data_Types.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
/* Standard return type: */
typedef uint8 Std_ReturnType;
/* Structure for version information: */
typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION      4u
#define STD_TYPES_AR_RELEASE_MINOR_VERSION      4u
#define STD_TYPES_AR_RELEASE_REVISION_VERSION   0u

#define STD_SW_MAJOR_VERSION                    1u
#define STD_SW_MINOR_VERSION                    0u
#define STD_SW_PATCH_VERSION                    0u

#define STD_VENDOR_ID                           0u
#define STD_MODULE_ID                           0u

#define STD_HIGH    ((uint8)0x01u)
#define STD_LOW     ((uint8)0x00u)

#define STD_ACTIVE  ((uint8)0x01u)
#define STD_IDLE    ((uint8)0x00u)

#define STD_ON      ((uint8)0x01u)
#define STD_OFF     ((uint8)0x00u)

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/
#define E_OK        ((Std_ReturnType)0x00u)
#define E_NOT_OK    ((Std_ReturnType)0x01u)

/* Fill structure with version information: */
#define STD_GET_VERSION_INFO(destPtr)                           \
    do {                                                        \
        if ((destPtr) != NULL_PTR) {                            \
            (destPtr)->vendorID        = STD_VENDOR_ID;         \
            (destPtr)->moduleID        = STD_MODULE_ID;         \
            (destPtr)->sw_major_version = STD_SW_MAJOR_VERSION; \
            (destPtr)->sw_minor_version = STD_SW_MINOR_VERSION; \
            (destPtr)->sw_patch_version = STD_SW_PATCH_VERSION; \
        }                                                       \
    } while (0)
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