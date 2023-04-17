/*******************************************************************************
* File Name: Right_Motor_PWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Right_Motor_PWM.h"

static Right_Motor_PWM_backupStruct Right_Motor_PWM_backup;


/*******************************************************************************
* Function Name: Right_Motor_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Right_Motor_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Right_Motor_PWM_SaveConfig(void) 
{

    #if(!Right_Motor_PWM_UsingFixedFunction)
        #if(!Right_Motor_PWM_PWMModeIsCenterAligned)
            Right_Motor_PWM_backup.PWMPeriod = Right_Motor_PWM_ReadPeriod();
        #endif /* (!Right_Motor_PWM_PWMModeIsCenterAligned) */
        Right_Motor_PWM_backup.PWMUdb = Right_Motor_PWM_ReadCounter();
        #if (Right_Motor_PWM_UseStatus)
            Right_Motor_PWM_backup.InterruptMaskValue = Right_Motor_PWM_STATUS_MASK;
        #endif /* (Right_Motor_PWM_UseStatus) */

        #if(Right_Motor_PWM_DeadBandMode == Right_Motor_PWM__B_PWM__DBM_256_CLOCKS || \
            Right_Motor_PWM_DeadBandMode == Right_Motor_PWM__B_PWM__DBM_2_4_CLOCKS)
            Right_Motor_PWM_backup.PWMdeadBandValue = Right_Motor_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Right_Motor_PWM_KillModeMinTime)
             Right_Motor_PWM_backup.PWMKillCounterPeriod = Right_Motor_PWM_ReadKillTime();
        #endif /* (Right_Motor_PWM_KillModeMinTime) */

        #if(Right_Motor_PWM_UseControl)
            Right_Motor_PWM_backup.PWMControlRegister = Right_Motor_PWM_ReadControlRegister();
        #endif /* (Right_Motor_PWM_UseControl) */
    #endif  /* (!Right_Motor_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Right_Motor_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Right_Motor_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Right_Motor_PWM_RestoreConfig(void) 
{
        #if(!Right_Motor_PWM_UsingFixedFunction)
            #if(!Right_Motor_PWM_PWMModeIsCenterAligned)
                Right_Motor_PWM_WritePeriod(Right_Motor_PWM_backup.PWMPeriod);
            #endif /* (!Right_Motor_PWM_PWMModeIsCenterAligned) */

            Right_Motor_PWM_WriteCounter(Right_Motor_PWM_backup.PWMUdb);

            #if (Right_Motor_PWM_UseStatus)
                Right_Motor_PWM_STATUS_MASK = Right_Motor_PWM_backup.InterruptMaskValue;
            #endif /* (Right_Motor_PWM_UseStatus) */

            #if(Right_Motor_PWM_DeadBandMode == Right_Motor_PWM__B_PWM__DBM_256_CLOCKS || \
                Right_Motor_PWM_DeadBandMode == Right_Motor_PWM__B_PWM__DBM_2_4_CLOCKS)
                Right_Motor_PWM_WriteDeadTime(Right_Motor_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Right_Motor_PWM_KillModeMinTime)
                Right_Motor_PWM_WriteKillTime(Right_Motor_PWM_backup.PWMKillCounterPeriod);
            #endif /* (Right_Motor_PWM_KillModeMinTime) */

            #if(Right_Motor_PWM_UseControl)
                Right_Motor_PWM_WriteControlRegister(Right_Motor_PWM_backup.PWMControlRegister);
            #endif /* (Right_Motor_PWM_UseControl) */
        #endif  /* (!Right_Motor_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Right_Motor_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Right_Motor_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Right_Motor_PWM_Sleep(void) 
{
    #if(Right_Motor_PWM_UseControl)
        if(Right_Motor_PWM_CTRL_ENABLE == (Right_Motor_PWM_CONTROL & Right_Motor_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            Right_Motor_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Right_Motor_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (Right_Motor_PWM_UseControl) */

    /* Stop component */
    Right_Motor_PWM_Stop();

    /* Save registers configuration */
    Right_Motor_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: Right_Motor_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Right_Motor_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Right_Motor_PWM_Wakeup(void) 
{
     /* Restore registers values */
    Right_Motor_PWM_RestoreConfig();

    if(Right_Motor_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Right_Motor_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
