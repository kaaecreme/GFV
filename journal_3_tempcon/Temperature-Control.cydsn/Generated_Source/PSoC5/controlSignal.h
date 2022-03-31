/*******************************************************************************
* File Name: controlSignal.h  
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

#if !defined(CY_PINS_controlSignal_H) /* Pins controlSignal_H */
#define CY_PINS_controlSignal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "controlSignal_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 controlSignal__PORT == 15 && ((controlSignal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    controlSignal_Write(uint8 value);
void    controlSignal_SetDriveMode(uint8 mode);
uint8   controlSignal_ReadDataReg(void);
uint8   controlSignal_Read(void);
void    controlSignal_SetInterruptMode(uint16 position, uint16 mode);
uint8   controlSignal_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the controlSignal_SetDriveMode() function.
     *  @{
     */
        #define controlSignal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define controlSignal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define controlSignal_DM_RES_UP          PIN_DM_RES_UP
        #define controlSignal_DM_RES_DWN         PIN_DM_RES_DWN
        #define controlSignal_DM_OD_LO           PIN_DM_OD_LO
        #define controlSignal_DM_OD_HI           PIN_DM_OD_HI
        #define controlSignal_DM_STRONG          PIN_DM_STRONG
        #define controlSignal_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define controlSignal_MASK               controlSignal__MASK
#define controlSignal_SHIFT              controlSignal__SHIFT
#define controlSignal_WIDTH              1u

/* Interrupt constants */
#if defined(controlSignal__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in controlSignal_SetInterruptMode() function.
     *  @{
     */
        #define controlSignal_INTR_NONE      (uint16)(0x0000u)
        #define controlSignal_INTR_RISING    (uint16)(0x0001u)
        #define controlSignal_INTR_FALLING   (uint16)(0x0002u)
        #define controlSignal_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define controlSignal_INTR_MASK      (0x01u) 
#endif /* (controlSignal__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define controlSignal_PS                     (* (reg8 *) controlSignal__PS)
/* Data Register */
#define controlSignal_DR                     (* (reg8 *) controlSignal__DR)
/* Port Number */
#define controlSignal_PRT_NUM                (* (reg8 *) controlSignal__PRT) 
/* Connect to Analog Globals */                                                  
#define controlSignal_AG                     (* (reg8 *) controlSignal__AG)                       
/* Analog MUX bux enable */
#define controlSignal_AMUX                   (* (reg8 *) controlSignal__AMUX) 
/* Bidirectional Enable */                                                        
#define controlSignal_BIE                    (* (reg8 *) controlSignal__BIE)
/* Bit-mask for Aliased Register Access */
#define controlSignal_BIT_MASK               (* (reg8 *) controlSignal__BIT_MASK)
/* Bypass Enable */
#define controlSignal_BYP                    (* (reg8 *) controlSignal__BYP)
/* Port wide control signals */                                                   
#define controlSignal_CTL                    (* (reg8 *) controlSignal__CTL)
/* Drive Modes */
#define controlSignal_DM0                    (* (reg8 *) controlSignal__DM0) 
#define controlSignal_DM1                    (* (reg8 *) controlSignal__DM1)
#define controlSignal_DM2                    (* (reg8 *) controlSignal__DM2) 
/* Input Buffer Disable Override */
#define controlSignal_INP_DIS                (* (reg8 *) controlSignal__INP_DIS)
/* LCD Common or Segment Drive */
#define controlSignal_LCD_COM_SEG            (* (reg8 *) controlSignal__LCD_COM_SEG)
/* Enable Segment LCD */
#define controlSignal_LCD_EN                 (* (reg8 *) controlSignal__LCD_EN)
/* Slew Rate Control */
#define controlSignal_SLW                    (* (reg8 *) controlSignal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define controlSignal_PRTDSI__CAPS_SEL       (* (reg8 *) controlSignal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define controlSignal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) controlSignal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define controlSignal_PRTDSI__OE_SEL0        (* (reg8 *) controlSignal__PRTDSI__OE_SEL0) 
#define controlSignal_PRTDSI__OE_SEL1        (* (reg8 *) controlSignal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define controlSignal_PRTDSI__OUT_SEL0       (* (reg8 *) controlSignal__PRTDSI__OUT_SEL0) 
#define controlSignal_PRTDSI__OUT_SEL1       (* (reg8 *) controlSignal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define controlSignal_PRTDSI__SYNC_OUT       (* (reg8 *) controlSignal__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(controlSignal__SIO_CFG)
    #define controlSignal_SIO_HYST_EN        (* (reg8 *) controlSignal__SIO_HYST_EN)
    #define controlSignal_SIO_REG_HIFREQ     (* (reg8 *) controlSignal__SIO_REG_HIFREQ)
    #define controlSignal_SIO_CFG            (* (reg8 *) controlSignal__SIO_CFG)
    #define controlSignal_SIO_DIFF           (* (reg8 *) controlSignal__SIO_DIFF)
#endif /* (controlSignal__SIO_CFG) */

/* Interrupt Registers */
#if defined(controlSignal__INTSTAT)
    #define controlSignal_INTSTAT            (* (reg8 *) controlSignal__INTSTAT)
    #define controlSignal_SNAP               (* (reg8 *) controlSignal__SNAP)
    
	#define controlSignal_0_INTTYPE_REG 		(* (reg8 *) controlSignal__0__INTTYPE)
#endif /* (controlSignal__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_controlSignal_H */


/* [] END OF FILE */
