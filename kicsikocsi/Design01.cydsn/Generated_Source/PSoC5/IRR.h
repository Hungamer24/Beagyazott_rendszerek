/*******************************************************************************
* File Name: IRR.h  
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

#if !defined(CY_PINS_IRR_H) /* Pins IRR_H */
#define CY_PINS_IRR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IRR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IRR__PORT == 15 && ((IRR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IRR_Write(uint8 value);
void    IRR_SetDriveMode(uint8 mode);
uint8   IRR_ReadDataReg(void);
uint8   IRR_Read(void);
void    IRR_SetInterruptMode(uint16 position, uint16 mode);
uint8   IRR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IRR_SetDriveMode() function.
     *  @{
     */
        #define IRR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IRR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IRR_DM_RES_UP          PIN_DM_RES_UP
        #define IRR_DM_RES_DWN         PIN_DM_RES_DWN
        #define IRR_DM_OD_LO           PIN_DM_OD_LO
        #define IRR_DM_OD_HI           PIN_DM_OD_HI
        #define IRR_DM_STRONG          PIN_DM_STRONG
        #define IRR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IRR_MASK               IRR__MASK
#define IRR_SHIFT              IRR__SHIFT
#define IRR_WIDTH              1u

/* Interrupt constants */
#if defined(IRR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IRR_SetInterruptMode() function.
     *  @{
     */
        #define IRR_INTR_NONE      (uint16)(0x0000u)
        #define IRR_INTR_RISING    (uint16)(0x0001u)
        #define IRR_INTR_FALLING   (uint16)(0x0002u)
        #define IRR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IRR_INTR_MASK      (0x01u) 
#endif /* (IRR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IRR_PS                     (* (reg8 *) IRR__PS)
/* Data Register */
#define IRR_DR                     (* (reg8 *) IRR__DR)
/* Port Number */
#define IRR_PRT_NUM                (* (reg8 *) IRR__PRT) 
/* Connect to Analog Globals */                                                  
#define IRR_AG                     (* (reg8 *) IRR__AG)                       
/* Analog MUX bux enable */
#define IRR_AMUX                   (* (reg8 *) IRR__AMUX) 
/* Bidirectional Enable */                                                        
#define IRR_BIE                    (* (reg8 *) IRR__BIE)
/* Bit-mask for Aliased Register Access */
#define IRR_BIT_MASK               (* (reg8 *) IRR__BIT_MASK)
/* Bypass Enable */
#define IRR_BYP                    (* (reg8 *) IRR__BYP)
/* Port wide control signals */                                                   
#define IRR_CTL                    (* (reg8 *) IRR__CTL)
/* Drive Modes */
#define IRR_DM0                    (* (reg8 *) IRR__DM0) 
#define IRR_DM1                    (* (reg8 *) IRR__DM1)
#define IRR_DM2                    (* (reg8 *) IRR__DM2) 
/* Input Buffer Disable Override */
#define IRR_INP_DIS                (* (reg8 *) IRR__INP_DIS)
/* LCD Common or Segment Drive */
#define IRR_LCD_COM_SEG            (* (reg8 *) IRR__LCD_COM_SEG)
/* Enable Segment LCD */
#define IRR_LCD_EN                 (* (reg8 *) IRR__LCD_EN)
/* Slew Rate Control */
#define IRR_SLW                    (* (reg8 *) IRR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IRR_PRTDSI__CAPS_SEL       (* (reg8 *) IRR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IRR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IRR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IRR_PRTDSI__OE_SEL0        (* (reg8 *) IRR__PRTDSI__OE_SEL0) 
#define IRR_PRTDSI__OE_SEL1        (* (reg8 *) IRR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IRR_PRTDSI__OUT_SEL0       (* (reg8 *) IRR__PRTDSI__OUT_SEL0) 
#define IRR_PRTDSI__OUT_SEL1       (* (reg8 *) IRR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IRR_PRTDSI__SYNC_OUT       (* (reg8 *) IRR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IRR__SIO_CFG)
    #define IRR_SIO_HYST_EN        (* (reg8 *) IRR__SIO_HYST_EN)
    #define IRR_SIO_REG_HIFREQ     (* (reg8 *) IRR__SIO_REG_HIFREQ)
    #define IRR_SIO_CFG            (* (reg8 *) IRR__SIO_CFG)
    #define IRR_SIO_DIFF           (* (reg8 *) IRR__SIO_DIFF)
#endif /* (IRR__SIO_CFG) */

/* Interrupt Registers */
#if defined(IRR__INTSTAT)
    #define IRR_INTSTAT            (* (reg8 *) IRR__INTSTAT)
    #define IRR_SNAP               (* (reg8 *) IRR__SNAP)
    
	#define IRR_0_INTTYPE_REG 		(* (reg8 *) IRR__0__INTTYPE)
#endif /* (IRR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IRR_H */


/* [] END OF FILE */
