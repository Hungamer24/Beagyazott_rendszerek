/*******************************************************************************
* File Name: Left_Motor_DIR.h  
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

#if !defined(CY_PINS_Left_Motor_DIR_H) /* Pins Left_Motor_DIR_H */
#define CY_PINS_Left_Motor_DIR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Left_Motor_DIR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Left_Motor_DIR__PORT == 15 && ((Left_Motor_DIR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Left_Motor_DIR_Write(uint8 value);
void    Left_Motor_DIR_SetDriveMode(uint8 mode);
uint8   Left_Motor_DIR_ReadDataReg(void);
uint8   Left_Motor_DIR_Read(void);
void    Left_Motor_DIR_SetInterruptMode(uint16 position, uint16 mode);
uint8   Left_Motor_DIR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Left_Motor_DIR_SetDriveMode() function.
     *  @{
     */
        #define Left_Motor_DIR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Left_Motor_DIR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Left_Motor_DIR_DM_RES_UP          PIN_DM_RES_UP
        #define Left_Motor_DIR_DM_RES_DWN         PIN_DM_RES_DWN
        #define Left_Motor_DIR_DM_OD_LO           PIN_DM_OD_LO
        #define Left_Motor_DIR_DM_OD_HI           PIN_DM_OD_HI
        #define Left_Motor_DIR_DM_STRONG          PIN_DM_STRONG
        #define Left_Motor_DIR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Left_Motor_DIR_MASK               Left_Motor_DIR__MASK
#define Left_Motor_DIR_SHIFT              Left_Motor_DIR__SHIFT
#define Left_Motor_DIR_WIDTH              1u

/* Interrupt constants */
#if defined(Left_Motor_DIR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Left_Motor_DIR_SetInterruptMode() function.
     *  @{
     */
        #define Left_Motor_DIR_INTR_NONE      (uint16)(0x0000u)
        #define Left_Motor_DIR_INTR_RISING    (uint16)(0x0001u)
        #define Left_Motor_DIR_INTR_FALLING   (uint16)(0x0002u)
        #define Left_Motor_DIR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Left_Motor_DIR_INTR_MASK      (0x01u) 
#endif /* (Left_Motor_DIR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Left_Motor_DIR_PS                     (* (reg8 *) Left_Motor_DIR__PS)
/* Data Register */
#define Left_Motor_DIR_DR                     (* (reg8 *) Left_Motor_DIR__DR)
/* Port Number */
#define Left_Motor_DIR_PRT_NUM                (* (reg8 *) Left_Motor_DIR__PRT) 
/* Connect to Analog Globals */                                                  
#define Left_Motor_DIR_AG                     (* (reg8 *) Left_Motor_DIR__AG)                       
/* Analog MUX bux enable */
#define Left_Motor_DIR_AMUX                   (* (reg8 *) Left_Motor_DIR__AMUX) 
/* Bidirectional Enable */                                                        
#define Left_Motor_DIR_BIE                    (* (reg8 *) Left_Motor_DIR__BIE)
/* Bit-mask for Aliased Register Access */
#define Left_Motor_DIR_BIT_MASK               (* (reg8 *) Left_Motor_DIR__BIT_MASK)
/* Bypass Enable */
#define Left_Motor_DIR_BYP                    (* (reg8 *) Left_Motor_DIR__BYP)
/* Port wide control signals */                                                   
#define Left_Motor_DIR_CTL                    (* (reg8 *) Left_Motor_DIR__CTL)
/* Drive Modes */
#define Left_Motor_DIR_DM0                    (* (reg8 *) Left_Motor_DIR__DM0) 
#define Left_Motor_DIR_DM1                    (* (reg8 *) Left_Motor_DIR__DM1)
#define Left_Motor_DIR_DM2                    (* (reg8 *) Left_Motor_DIR__DM2) 
/* Input Buffer Disable Override */
#define Left_Motor_DIR_INP_DIS                (* (reg8 *) Left_Motor_DIR__INP_DIS)
/* LCD Common or Segment Drive */
#define Left_Motor_DIR_LCD_COM_SEG            (* (reg8 *) Left_Motor_DIR__LCD_COM_SEG)
/* Enable Segment LCD */
#define Left_Motor_DIR_LCD_EN                 (* (reg8 *) Left_Motor_DIR__LCD_EN)
/* Slew Rate Control */
#define Left_Motor_DIR_SLW                    (* (reg8 *) Left_Motor_DIR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Left_Motor_DIR_PRTDSI__CAPS_SEL       (* (reg8 *) Left_Motor_DIR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Left_Motor_DIR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Left_Motor_DIR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Left_Motor_DIR_PRTDSI__OE_SEL0        (* (reg8 *) Left_Motor_DIR__PRTDSI__OE_SEL0) 
#define Left_Motor_DIR_PRTDSI__OE_SEL1        (* (reg8 *) Left_Motor_DIR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Left_Motor_DIR_PRTDSI__OUT_SEL0       (* (reg8 *) Left_Motor_DIR__PRTDSI__OUT_SEL0) 
#define Left_Motor_DIR_PRTDSI__OUT_SEL1       (* (reg8 *) Left_Motor_DIR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Left_Motor_DIR_PRTDSI__SYNC_OUT       (* (reg8 *) Left_Motor_DIR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Left_Motor_DIR__SIO_CFG)
    #define Left_Motor_DIR_SIO_HYST_EN        (* (reg8 *) Left_Motor_DIR__SIO_HYST_EN)
    #define Left_Motor_DIR_SIO_REG_HIFREQ     (* (reg8 *) Left_Motor_DIR__SIO_REG_HIFREQ)
    #define Left_Motor_DIR_SIO_CFG            (* (reg8 *) Left_Motor_DIR__SIO_CFG)
    #define Left_Motor_DIR_SIO_DIFF           (* (reg8 *) Left_Motor_DIR__SIO_DIFF)
#endif /* (Left_Motor_DIR__SIO_CFG) */

/* Interrupt Registers */
#if defined(Left_Motor_DIR__INTSTAT)
    #define Left_Motor_DIR_INTSTAT            (* (reg8 *) Left_Motor_DIR__INTSTAT)
    #define Left_Motor_DIR_SNAP               (* (reg8 *) Left_Motor_DIR__SNAP)
    
	#define Left_Motor_DIR_0_INTTYPE_REG 		(* (reg8 *) Left_Motor_DIR__0__INTTYPE)
#endif /* (Left_Motor_DIR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Left_Motor_DIR_H */


/* [] END OF FILE */
