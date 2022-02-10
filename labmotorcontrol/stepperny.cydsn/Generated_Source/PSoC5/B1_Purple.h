/*******************************************************************************
* File Name: B1_Purple.h  
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

#if !defined(CY_PINS_B1_Purple_H) /* Pins B1_Purple_H */
#define CY_PINS_B1_Purple_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B1_Purple_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B1_Purple__PORT == 15 && ((B1_Purple__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B1_Purple_Write(uint8 value);
void    B1_Purple_SetDriveMode(uint8 mode);
uint8   B1_Purple_ReadDataReg(void);
uint8   B1_Purple_Read(void);
void    B1_Purple_SetInterruptMode(uint16 position, uint16 mode);
uint8   B1_Purple_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B1_Purple_SetDriveMode() function.
     *  @{
     */
        #define B1_Purple_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B1_Purple_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B1_Purple_DM_RES_UP          PIN_DM_RES_UP
        #define B1_Purple_DM_RES_DWN         PIN_DM_RES_DWN
        #define B1_Purple_DM_OD_LO           PIN_DM_OD_LO
        #define B1_Purple_DM_OD_HI           PIN_DM_OD_HI
        #define B1_Purple_DM_STRONG          PIN_DM_STRONG
        #define B1_Purple_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B1_Purple_MASK               B1_Purple__MASK
#define B1_Purple_SHIFT              B1_Purple__SHIFT
#define B1_Purple_WIDTH              1u

/* Interrupt constants */
#if defined(B1_Purple__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B1_Purple_SetInterruptMode() function.
     *  @{
     */
        #define B1_Purple_INTR_NONE      (uint16)(0x0000u)
        #define B1_Purple_INTR_RISING    (uint16)(0x0001u)
        #define B1_Purple_INTR_FALLING   (uint16)(0x0002u)
        #define B1_Purple_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B1_Purple_INTR_MASK      (0x01u) 
#endif /* (B1_Purple__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B1_Purple_PS                     (* (reg8 *) B1_Purple__PS)
/* Data Register */
#define B1_Purple_DR                     (* (reg8 *) B1_Purple__DR)
/* Port Number */
#define B1_Purple_PRT_NUM                (* (reg8 *) B1_Purple__PRT) 
/* Connect to Analog Globals */                                                  
#define B1_Purple_AG                     (* (reg8 *) B1_Purple__AG)                       
/* Analog MUX bux enable */
#define B1_Purple_AMUX                   (* (reg8 *) B1_Purple__AMUX) 
/* Bidirectional Enable */                                                        
#define B1_Purple_BIE                    (* (reg8 *) B1_Purple__BIE)
/* Bit-mask for Aliased Register Access */
#define B1_Purple_BIT_MASK               (* (reg8 *) B1_Purple__BIT_MASK)
/* Bypass Enable */
#define B1_Purple_BYP                    (* (reg8 *) B1_Purple__BYP)
/* Port wide control signals */                                                   
#define B1_Purple_CTL                    (* (reg8 *) B1_Purple__CTL)
/* Drive Modes */
#define B1_Purple_DM0                    (* (reg8 *) B1_Purple__DM0) 
#define B1_Purple_DM1                    (* (reg8 *) B1_Purple__DM1)
#define B1_Purple_DM2                    (* (reg8 *) B1_Purple__DM2) 
/* Input Buffer Disable Override */
#define B1_Purple_INP_DIS                (* (reg8 *) B1_Purple__INP_DIS)
/* LCD Common or Segment Drive */
#define B1_Purple_LCD_COM_SEG            (* (reg8 *) B1_Purple__LCD_COM_SEG)
/* Enable Segment LCD */
#define B1_Purple_LCD_EN                 (* (reg8 *) B1_Purple__LCD_EN)
/* Slew Rate Control */
#define B1_Purple_SLW                    (* (reg8 *) B1_Purple__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B1_Purple_PRTDSI__CAPS_SEL       (* (reg8 *) B1_Purple__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B1_Purple_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B1_Purple__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B1_Purple_PRTDSI__OE_SEL0        (* (reg8 *) B1_Purple__PRTDSI__OE_SEL0) 
#define B1_Purple_PRTDSI__OE_SEL1        (* (reg8 *) B1_Purple__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B1_Purple_PRTDSI__OUT_SEL0       (* (reg8 *) B1_Purple__PRTDSI__OUT_SEL0) 
#define B1_Purple_PRTDSI__OUT_SEL1       (* (reg8 *) B1_Purple__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B1_Purple_PRTDSI__SYNC_OUT       (* (reg8 *) B1_Purple__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B1_Purple__SIO_CFG)
    #define B1_Purple_SIO_HYST_EN        (* (reg8 *) B1_Purple__SIO_HYST_EN)
    #define B1_Purple_SIO_REG_HIFREQ     (* (reg8 *) B1_Purple__SIO_REG_HIFREQ)
    #define B1_Purple_SIO_CFG            (* (reg8 *) B1_Purple__SIO_CFG)
    #define B1_Purple_SIO_DIFF           (* (reg8 *) B1_Purple__SIO_DIFF)
#endif /* (B1_Purple__SIO_CFG) */

/* Interrupt Registers */
#if defined(B1_Purple__INTSTAT)
    #define B1_Purple_INTSTAT            (* (reg8 *) B1_Purple__INTSTAT)
    #define B1_Purple_SNAP               (* (reg8 *) B1_Purple__SNAP)
    
	#define B1_Purple_0_INTTYPE_REG 		(* (reg8 *) B1_Purple__0__INTTYPE)
#endif /* (B1_Purple__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B1_Purple_H */


/* [] END OF FILE */
