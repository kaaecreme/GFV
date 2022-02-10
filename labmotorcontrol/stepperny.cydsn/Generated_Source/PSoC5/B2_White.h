/*******************************************************************************
* File Name: B2_White.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_B2_White_H) /* Pins B2_White_H */
#define CY_PINS_B2_White_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B2_White_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B2_White__PORT == 15 && ((B2_White__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B2_White_Write(uint8 value);
void    B2_White_SetDriveMode(uint8 mode);
uint8   B2_White_ReadDataReg(void);
uint8   B2_White_Read(void);
void    B2_White_SetInterruptMode(uint16 position, uint16 mode);
uint8   B2_White_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B2_White_SetDriveMode() function.
     *  @{
     */
        #define B2_White_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B2_White_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B2_White_DM_RES_UP          PIN_DM_RES_UP
        #define B2_White_DM_RES_DWN         PIN_DM_RES_DWN
        #define B2_White_DM_OD_LO           PIN_DM_OD_LO
        #define B2_White_DM_OD_HI           PIN_DM_OD_HI
        #define B2_White_DM_STRONG          PIN_DM_STRONG
        #define B2_White_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B2_White_MASK               B2_White__MASK
#define B2_White_SHIFT              B2_White__SHIFT
#define B2_White_WIDTH              1u

/* Interrupt constants */
#if defined(B2_White__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B2_White_SetInterruptMode() function.
     *  @{
     */
        #define B2_White_INTR_NONE      (uint16)(0x0000u)
        #define B2_White_INTR_RISING    (uint16)(0x0001u)
        #define B2_White_INTR_FALLING   (uint16)(0x0002u)
        #define B2_White_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B2_White_INTR_MASK      (0x01u) 
#endif /* (B2_White__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B2_White_PS                     (* (reg8 *) B2_White__PS)
/* Data Register */
#define B2_White_DR                     (* (reg8 *) B2_White__DR)
/* Port Number */
#define B2_White_PRT_NUM                (* (reg8 *) B2_White__PRT) 
/* Connect to Analog Globals */                                                  
#define B2_White_AG                     (* (reg8 *) B2_White__AG)                       
/* Analog MUX bux enable */
#define B2_White_AMUX                   (* (reg8 *) B2_White__AMUX) 
/* Bidirectional Enable */                                                        
#define B2_White_BIE                    (* (reg8 *) B2_White__BIE)
/* Bit-mask for Aliased Register Access */
#define B2_White_BIT_MASK               (* (reg8 *) B2_White__BIT_MASK)
/* Bypass Enable */
#define B2_White_BYP                    (* (reg8 *) B2_White__BYP)
/* Port wide control signals */                                                   
#define B2_White_CTL                    (* (reg8 *) B2_White__CTL)
/* Drive Modes */
#define B2_White_DM0                    (* (reg8 *) B2_White__DM0) 
#define B2_White_DM1                    (* (reg8 *) B2_White__DM1)
#define B2_White_DM2                    (* (reg8 *) B2_White__DM2) 
/* Input Buffer Disable Override */
#define B2_White_INP_DIS                (* (reg8 *) B2_White__INP_DIS)
/* LCD Common or Segment Drive */
#define B2_White_LCD_COM_SEG            (* (reg8 *) B2_White__LCD_COM_SEG)
/* Enable Segment LCD */
#define B2_White_LCD_EN                 (* (reg8 *) B2_White__LCD_EN)
/* Slew Rate Control */
#define B2_White_SLW                    (* (reg8 *) B2_White__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B2_White_PRTDSI__CAPS_SEL       (* (reg8 *) B2_White__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B2_White_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B2_White__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B2_White_PRTDSI__OE_SEL0        (* (reg8 *) B2_White__PRTDSI__OE_SEL0) 
#define B2_White_PRTDSI__OE_SEL1        (* (reg8 *) B2_White__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B2_White_PRTDSI__OUT_SEL0       (* (reg8 *) B2_White__PRTDSI__OUT_SEL0) 
#define B2_White_PRTDSI__OUT_SEL1       (* (reg8 *) B2_White__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B2_White_PRTDSI__SYNC_OUT       (* (reg8 *) B2_White__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B2_White__SIO_CFG)
    #define B2_White_SIO_HYST_EN        (* (reg8 *) B2_White__SIO_HYST_EN)
    #define B2_White_SIO_REG_HIFREQ     (* (reg8 *) B2_White__SIO_REG_HIFREQ)
    #define B2_White_SIO_CFG            (* (reg8 *) B2_White__SIO_CFG)
    #define B2_White_SIO_DIFF           (* (reg8 *) B2_White__SIO_DIFF)
#endif /* (B2_White__SIO_CFG) */

/* Interrupt Registers */
#if defined(B2_White__INTSTAT)
    #define B2_White_INTSTAT            (* (reg8 *) B2_White__INTSTAT)
    #define B2_White_SNAP               (* (reg8 *) B2_White__SNAP)
    
	#define B2_White_0_INTTYPE_REG 		(* (reg8 *) B2_White__0__INTTYPE)
#endif /* (B2_White__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B2_White_H */


/* [] END OF FILE */
