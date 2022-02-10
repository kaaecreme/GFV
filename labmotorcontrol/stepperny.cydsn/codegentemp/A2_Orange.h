/*******************************************************************************
* File Name: A2_Orange.h  
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

#if !defined(CY_PINS_A2_Orange_H) /* Pins A2_Orange_H */
#define CY_PINS_A2_Orange_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "A2_Orange_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 A2_Orange__PORT == 15 && ((A2_Orange__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    A2_Orange_Write(uint8 value);
void    A2_Orange_SetDriveMode(uint8 mode);
uint8   A2_Orange_ReadDataReg(void);
uint8   A2_Orange_Read(void);
void    A2_Orange_SetInterruptMode(uint16 position, uint16 mode);
uint8   A2_Orange_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the A2_Orange_SetDriveMode() function.
     *  @{
     */
        #define A2_Orange_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define A2_Orange_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define A2_Orange_DM_RES_UP          PIN_DM_RES_UP
        #define A2_Orange_DM_RES_DWN         PIN_DM_RES_DWN
        #define A2_Orange_DM_OD_LO           PIN_DM_OD_LO
        #define A2_Orange_DM_OD_HI           PIN_DM_OD_HI
        #define A2_Orange_DM_STRONG          PIN_DM_STRONG
        #define A2_Orange_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define A2_Orange_MASK               A2_Orange__MASK
#define A2_Orange_SHIFT              A2_Orange__SHIFT
#define A2_Orange_WIDTH              1u

/* Interrupt constants */
#if defined(A2_Orange__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in A2_Orange_SetInterruptMode() function.
     *  @{
     */
        #define A2_Orange_INTR_NONE      (uint16)(0x0000u)
        #define A2_Orange_INTR_RISING    (uint16)(0x0001u)
        #define A2_Orange_INTR_FALLING   (uint16)(0x0002u)
        #define A2_Orange_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define A2_Orange_INTR_MASK      (0x01u) 
#endif /* (A2_Orange__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A2_Orange_PS                     (* (reg8 *) A2_Orange__PS)
/* Data Register */
#define A2_Orange_DR                     (* (reg8 *) A2_Orange__DR)
/* Port Number */
#define A2_Orange_PRT_NUM                (* (reg8 *) A2_Orange__PRT) 
/* Connect to Analog Globals */                                                  
#define A2_Orange_AG                     (* (reg8 *) A2_Orange__AG)                       
/* Analog MUX bux enable */
#define A2_Orange_AMUX                   (* (reg8 *) A2_Orange__AMUX) 
/* Bidirectional Enable */                                                        
#define A2_Orange_BIE                    (* (reg8 *) A2_Orange__BIE)
/* Bit-mask for Aliased Register Access */
#define A2_Orange_BIT_MASK               (* (reg8 *) A2_Orange__BIT_MASK)
/* Bypass Enable */
#define A2_Orange_BYP                    (* (reg8 *) A2_Orange__BYP)
/* Port wide control signals */                                                   
#define A2_Orange_CTL                    (* (reg8 *) A2_Orange__CTL)
/* Drive Modes */
#define A2_Orange_DM0                    (* (reg8 *) A2_Orange__DM0) 
#define A2_Orange_DM1                    (* (reg8 *) A2_Orange__DM1)
#define A2_Orange_DM2                    (* (reg8 *) A2_Orange__DM2) 
/* Input Buffer Disable Override */
#define A2_Orange_INP_DIS                (* (reg8 *) A2_Orange__INP_DIS)
/* LCD Common or Segment Drive */
#define A2_Orange_LCD_COM_SEG            (* (reg8 *) A2_Orange__LCD_COM_SEG)
/* Enable Segment LCD */
#define A2_Orange_LCD_EN                 (* (reg8 *) A2_Orange__LCD_EN)
/* Slew Rate Control */
#define A2_Orange_SLW                    (* (reg8 *) A2_Orange__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define A2_Orange_PRTDSI__CAPS_SEL       (* (reg8 *) A2_Orange__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define A2_Orange_PRTDSI__DBL_SYNC_IN    (* (reg8 *) A2_Orange__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define A2_Orange_PRTDSI__OE_SEL0        (* (reg8 *) A2_Orange__PRTDSI__OE_SEL0) 
#define A2_Orange_PRTDSI__OE_SEL1        (* (reg8 *) A2_Orange__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define A2_Orange_PRTDSI__OUT_SEL0       (* (reg8 *) A2_Orange__PRTDSI__OUT_SEL0) 
#define A2_Orange_PRTDSI__OUT_SEL1       (* (reg8 *) A2_Orange__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define A2_Orange_PRTDSI__SYNC_OUT       (* (reg8 *) A2_Orange__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(A2_Orange__SIO_CFG)
    #define A2_Orange_SIO_HYST_EN        (* (reg8 *) A2_Orange__SIO_HYST_EN)
    #define A2_Orange_SIO_REG_HIFREQ     (* (reg8 *) A2_Orange__SIO_REG_HIFREQ)
    #define A2_Orange_SIO_CFG            (* (reg8 *) A2_Orange__SIO_CFG)
    #define A2_Orange_SIO_DIFF           (* (reg8 *) A2_Orange__SIO_DIFF)
#endif /* (A2_Orange__SIO_CFG) */

/* Interrupt Registers */
#if defined(A2_Orange__INTSTAT)
    #define A2_Orange_INTSTAT            (* (reg8 *) A2_Orange__INTSTAT)
    #define A2_Orange_SNAP               (* (reg8 *) A2_Orange__SNAP)
    
	#define A2_Orange_0_INTTYPE_REG 		(* (reg8 *) A2_Orange__0__INTTYPE)
#endif /* (A2_Orange__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_A2_Orange_H */


/* [] END OF FILE */
