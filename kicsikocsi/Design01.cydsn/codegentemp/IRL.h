/*******************************************************************************
* File Name: IRL.h  
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

#if !defined(CY_PINS_IRL_H) /* Pins IRL_H */
#define CY_PINS_IRL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IRL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IRL__PORT == 15 && ((IRL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IRL_Write(uint8 value);
void    IRL_SetDriveMode(uint8 mode);
uint8   IRL_ReadDataReg(void);
uint8   IRL_Read(void);
void    IRL_SetInterruptMode(uint16 position, uint16 mode);
uint8   IRL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IRL_SetDriveMode() function.
     *  @{
     */
        #define IRL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IRL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IRL_DM_RES_UP          PIN_DM_RES_UP
        #define IRL_DM_RES_DWN         PIN_DM_RES_DWN
        #define IRL_DM_OD_LO           PIN_DM_OD_LO
        #define IRL_DM_OD_HI           PIN_DM_OD_HI
        #define IRL_DM_STRONG          PIN_DM_STRONG
        #define IRL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IRL_MASK               IRL__MASK
#define IRL_SHIFT              IRL__SHIFT
#define IRL_WIDTH              1u

/* Interrupt constants */
#if defined(IRL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IRL_SetInterruptMode() function.
     *  @{
     */
        #define IRL_INTR_NONE      (uint16)(0x0000u)
        #define IRL_INTR_RISING    (uint16)(0x0001u)
        #define IRL_INTR_FALLING   (uint16)(0x0002u)
        #define IRL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IRL_INTR_MASK      (0x01u) 
#endif /* (IRL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IRL_PS                     (* (reg8 *) IRL__PS)
/* Data Register */
#define IRL_DR                     (* (reg8 *) IRL__DR)
/* Port Number */
#define IRL_PRT_NUM                (* (reg8 *) IRL__PRT) 
/* Connect to Analog Globals */                                                  
#define IRL_AG                     (* (reg8 *) IRL__AG)                       
/* Analog MUX bux enable */
#define IRL_AMUX                   (* (reg8 *) IRL__AMUX) 
/* Bidirectional Enable */                                                        
#define IRL_BIE                    (* (reg8 *) IRL__BIE)
/* Bit-mask for Aliased Register Access */
#define IRL_BIT_MASK               (* (reg8 *) IRL__BIT_MASK)
/* Bypass Enable */
#define IRL_BYP                    (* (reg8 *) IRL__BYP)
/* Port wide control signals */                                                   
#define IRL_CTL                    (* (reg8 *) IRL__CTL)
/* Drive Modes */
#define IRL_DM0                    (* (reg8 *) IRL__DM0) 
#define IRL_DM1                    (* (reg8 *) IRL__DM1)
#define IRL_DM2                    (* (reg8 *) IRL__DM2) 
/* Input Buffer Disable Override */
#define IRL_INP_DIS                (* (reg8 *) IRL__INP_DIS)
/* LCD Common or Segment Drive */
#define IRL_LCD_COM_SEG            (* (reg8 *) IRL__LCD_COM_SEG)
/* Enable Segment LCD */
#define IRL_LCD_EN                 (* (reg8 *) IRL__LCD_EN)
/* Slew Rate Control */
#define IRL_SLW                    (* (reg8 *) IRL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IRL_PRTDSI__CAPS_SEL       (* (reg8 *) IRL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IRL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IRL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IRL_PRTDSI__OE_SEL0        (* (reg8 *) IRL__PRTDSI__OE_SEL0) 
#define IRL_PRTDSI__OE_SEL1        (* (reg8 *) IRL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IRL_PRTDSI__OUT_SEL0       (* (reg8 *) IRL__PRTDSI__OUT_SEL0) 
#define IRL_PRTDSI__OUT_SEL1       (* (reg8 *) IRL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IRL_PRTDSI__SYNC_OUT       (* (reg8 *) IRL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IRL__SIO_CFG)
    #define IRL_SIO_HYST_EN        (* (reg8 *) IRL__SIO_HYST_EN)
    #define IRL_SIO_REG_HIFREQ     (* (reg8 *) IRL__SIO_REG_HIFREQ)
    #define IRL_SIO_CFG            (* (reg8 *) IRL__SIO_CFG)
    #define IRL_SIO_DIFF           (* (reg8 *) IRL__SIO_DIFF)
#endif /* (IRL__SIO_CFG) */

/* Interrupt Registers */
#if defined(IRL__INTSTAT)
    #define IRL_INTSTAT            (* (reg8 *) IRL__INTSTAT)
    #define IRL_SNAP               (* (reg8 *) IRL__SNAP)
    
	#define IRL_0_INTTYPE_REG 		(* (reg8 *) IRL__0__INTTYPE)
#endif /* (IRL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IRL_H */


/* [] END OF FILE */
