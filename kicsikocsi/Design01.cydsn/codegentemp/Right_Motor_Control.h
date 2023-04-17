/*******************************************************************************
* File Name: Right_Motor_Control.h  
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

#if !defined(CY_PINS_Right_Motor_Control_H) /* Pins Right_Motor_Control_H */
#define CY_PINS_Right_Motor_Control_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Right_Motor_Control_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Right_Motor_Control__PORT == 15 && ((Right_Motor_Control__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Right_Motor_Control_Write(uint8 value);
void    Right_Motor_Control_SetDriveMode(uint8 mode);
uint8   Right_Motor_Control_ReadDataReg(void);
uint8   Right_Motor_Control_Read(void);
void    Right_Motor_Control_SetInterruptMode(uint16 position, uint16 mode);
uint8   Right_Motor_Control_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Right_Motor_Control_SetDriveMode() function.
     *  @{
     */
        #define Right_Motor_Control_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Right_Motor_Control_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Right_Motor_Control_DM_RES_UP          PIN_DM_RES_UP
        #define Right_Motor_Control_DM_RES_DWN         PIN_DM_RES_DWN
        #define Right_Motor_Control_DM_OD_LO           PIN_DM_OD_LO
        #define Right_Motor_Control_DM_OD_HI           PIN_DM_OD_HI
        #define Right_Motor_Control_DM_STRONG          PIN_DM_STRONG
        #define Right_Motor_Control_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Right_Motor_Control_MASK               Right_Motor_Control__MASK
#define Right_Motor_Control_SHIFT              Right_Motor_Control__SHIFT
#define Right_Motor_Control_WIDTH              1u

/* Interrupt constants */
#if defined(Right_Motor_Control__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Right_Motor_Control_SetInterruptMode() function.
     *  @{
     */
        #define Right_Motor_Control_INTR_NONE      (uint16)(0x0000u)
        #define Right_Motor_Control_INTR_RISING    (uint16)(0x0001u)
        #define Right_Motor_Control_INTR_FALLING   (uint16)(0x0002u)
        #define Right_Motor_Control_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Right_Motor_Control_INTR_MASK      (0x01u) 
#endif /* (Right_Motor_Control__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Right_Motor_Control_PS                     (* (reg8 *) Right_Motor_Control__PS)
/* Data Register */
#define Right_Motor_Control_DR                     (* (reg8 *) Right_Motor_Control__DR)
/* Port Number */
#define Right_Motor_Control_PRT_NUM                (* (reg8 *) Right_Motor_Control__PRT) 
/* Connect to Analog Globals */                                                  
#define Right_Motor_Control_AG                     (* (reg8 *) Right_Motor_Control__AG)                       
/* Analog MUX bux enable */
#define Right_Motor_Control_AMUX                   (* (reg8 *) Right_Motor_Control__AMUX) 
/* Bidirectional Enable */                                                        
#define Right_Motor_Control_BIE                    (* (reg8 *) Right_Motor_Control__BIE)
/* Bit-mask for Aliased Register Access */
#define Right_Motor_Control_BIT_MASK               (* (reg8 *) Right_Motor_Control__BIT_MASK)
/* Bypass Enable */
#define Right_Motor_Control_BYP                    (* (reg8 *) Right_Motor_Control__BYP)
/* Port wide control signals */                                                   
#define Right_Motor_Control_CTL                    (* (reg8 *) Right_Motor_Control__CTL)
/* Drive Modes */
#define Right_Motor_Control_DM0                    (* (reg8 *) Right_Motor_Control__DM0) 
#define Right_Motor_Control_DM1                    (* (reg8 *) Right_Motor_Control__DM1)
#define Right_Motor_Control_DM2                    (* (reg8 *) Right_Motor_Control__DM2) 
/* Input Buffer Disable Override */
#define Right_Motor_Control_INP_DIS                (* (reg8 *) Right_Motor_Control__INP_DIS)
/* LCD Common or Segment Drive */
#define Right_Motor_Control_LCD_COM_SEG            (* (reg8 *) Right_Motor_Control__LCD_COM_SEG)
/* Enable Segment LCD */
#define Right_Motor_Control_LCD_EN                 (* (reg8 *) Right_Motor_Control__LCD_EN)
/* Slew Rate Control */
#define Right_Motor_Control_SLW                    (* (reg8 *) Right_Motor_Control__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Right_Motor_Control_PRTDSI__CAPS_SEL       (* (reg8 *) Right_Motor_Control__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Right_Motor_Control_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Right_Motor_Control__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Right_Motor_Control_PRTDSI__OE_SEL0        (* (reg8 *) Right_Motor_Control__PRTDSI__OE_SEL0) 
#define Right_Motor_Control_PRTDSI__OE_SEL1        (* (reg8 *) Right_Motor_Control__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Right_Motor_Control_PRTDSI__OUT_SEL0       (* (reg8 *) Right_Motor_Control__PRTDSI__OUT_SEL0) 
#define Right_Motor_Control_PRTDSI__OUT_SEL1       (* (reg8 *) Right_Motor_Control__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Right_Motor_Control_PRTDSI__SYNC_OUT       (* (reg8 *) Right_Motor_Control__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Right_Motor_Control__SIO_CFG)
    #define Right_Motor_Control_SIO_HYST_EN        (* (reg8 *) Right_Motor_Control__SIO_HYST_EN)
    #define Right_Motor_Control_SIO_REG_HIFREQ     (* (reg8 *) Right_Motor_Control__SIO_REG_HIFREQ)
    #define Right_Motor_Control_SIO_CFG            (* (reg8 *) Right_Motor_Control__SIO_CFG)
    #define Right_Motor_Control_SIO_DIFF           (* (reg8 *) Right_Motor_Control__SIO_DIFF)
#endif /* (Right_Motor_Control__SIO_CFG) */

/* Interrupt Registers */
#if defined(Right_Motor_Control__INTSTAT)
    #define Right_Motor_Control_INTSTAT            (* (reg8 *) Right_Motor_Control__INTSTAT)
    #define Right_Motor_Control_SNAP               (* (reg8 *) Right_Motor_Control__SNAP)
    
	#define Right_Motor_Control_0_INTTYPE_REG 		(* (reg8 *) Right_Motor_Control__0__INTTYPE)
#endif /* (Right_Motor_Control__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Right_Motor_Control_H */


/* [] END OF FILE */
