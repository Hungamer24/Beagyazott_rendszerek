/*******************************************************************************
* File Name: Left_Motor_PM.c
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

#include "Left_Motor.h"

static Left_Motor_backupStruct Left_Motor_backup;


/*******************************************************************************
* Function Name: Left_Motor_SaveConfig
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
*  Left_Motor_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Left_Motor_SaveConfig(void) 
{

    #if(!Left_Motor_UsingFixedFunction)
        #if(!Left_Motor_PWMModeIsCenterAligned)
            Left_Motor_backup.PWMPeriod = Left_Motor_ReadPeriod();
        #endif /* (!Left_Motor_PWMModeIsCenterAligned) */
        Left_Motor_backup.PWMUdb = Left_Motor_ReadCounter();
        #if (Left_Motor_UseStatus)
            Left_Motor_backup.InterruptMaskValue = Left_Motor_STATUS_MASK;
        #endif /* (Left_Motor_UseStatus) */

        #if(Left_Motor_DeadBandMode == Left_Motor__B_PWM__DBM_256_CLOCKS || \
            Left_Motor_DeadBandMode == Left_Motor__B_PWM__DBM_2_4_CLOCKS)
            Left_Motor_backup.PWMdeadBandValue = Left_Motor_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Left_Motor_KillModeMinTime)
             Left_Motor_backup.PWMKillCounterPeriod = Left_Motor_ReadKillTime();
        #endif /* (Left_Motor_KillModeMinTime) */

        #if(Left_Motor_UseControl)
            Left_Motor_backup.PWMControlRegister = Left_Motor_ReadControlRegister();
        #endif /* (Left_Motor_UseControl) */
    #endif  /* (!Left_Motor_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Left_Motor_RestoreConfig
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
*  Left_Motor_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Left_Motor_RestoreConfig(void) 
{
        #if(!Left_Motor_UsingFixedFunction)
            #if(!Left_Motor_PWMModeIsCenterAligned)
                Left_Motor_WritePeriod(Left_Motor_backup.PWMPeriod);
            #endif /* (!Left_Motor_PWMModeIsCenterAligned) */

            Left_Motor_WriteCounter(Left_Motor_backup.PWMUdb);

            #if (Left_Motor_UseStatus)
                Left_Motor_STATUS_MASK = Left_Motor_backup.InterruptMaskValue;
            #endif /* (Left_Motor_UseStatus) */

            #if(Left_Motor_DeadBandMode == Left_Motor__B_PWM__DBM_256_CLOCKS || \
                Left_Motor_DeadBandMode == Left_Motor__B_PWM__DBM_2_4_CLOCKS)
                Left_Motor_WriteDeadTime(Left_Motor_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Left_Motor_KillModeMinTime)
                Left_Motor_WriteKillTime(Left_Motor_backup.PWMKillCounterPeriod);
            #endif /* (Left_Motor_KillModeMinTime) */

            #if(Left_Motor_UseControl)
                Left_Motor_WriteControlRegister(Left_Motor_backup.PWMControlRegister);
            #endif /* (Left_Motor_UseControl) */
        #endif  /* (!Left_Motor_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Left_Motor_Sleep
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
*  Left_Motor_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Left_Motor_Sleep(void) 
{
    #if(Left_Motor_UseControl)
        if(Left_Motor_CTRL_ENABLE == (Left_Motor_CONTROL & Left_Motor_CTRL_ENABLE))
        {
            /*Component is enabled */
            Left_Motor_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Left_Motor_backup.PWMEnableState = 0u;
        }
    #endif /* (Left_Motor_UseControl) */

    /* Stop component */
    Left_Motor_Stop();

    /* Save registers configuration */
    Left_Motor_SaveConfig();
}


/*******************************************************************************
* Function Name: Left_Motor_Wakeup
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
*  Left_Motor_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Left_Motor_Wakeup(void) 
{
     /* Restore registers values */
    Left_Motor_RestoreConfig();

    if(Left_Motor_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Left_Motor_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
