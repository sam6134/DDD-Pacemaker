/*******************************************************************************
* File Name: AVI_Timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "AVI_Timer.h"

static AVI_Timer_backupStruct AVI_Timer_backup;


/*******************************************************************************
* Function Name: AVI_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AVI_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void AVI_Timer_SaveConfig(void) 
{
    #if (!AVI_Timer_UsingFixedFunction)
        AVI_Timer_backup.TimerUdb = AVI_Timer_ReadCounter();
        AVI_Timer_backup.InterruptMaskValue = AVI_Timer_STATUS_MASK;
        #if (AVI_Timer_UsingHWCaptureCounter)
            AVI_Timer_backup.TimerCaptureCounter = AVI_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!AVI_Timer_UDB_CONTROL_REG_REMOVED)
            AVI_Timer_backup.TimerControlRegister = AVI_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: AVI_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AVI_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void AVI_Timer_RestoreConfig(void) 
{   
    #if (!AVI_Timer_UsingFixedFunction)

        AVI_Timer_WriteCounter(AVI_Timer_backup.TimerUdb);
        AVI_Timer_STATUS_MASK =AVI_Timer_backup.InterruptMaskValue;
        #if (AVI_Timer_UsingHWCaptureCounter)
            AVI_Timer_SetCaptureCount(AVI_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!AVI_Timer_UDB_CONTROL_REG_REMOVED)
            AVI_Timer_WriteControlRegister(AVI_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: AVI_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AVI_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void AVI_Timer_Sleep(void) 
{
    #if(!AVI_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(AVI_Timer_CTRL_ENABLE == (AVI_Timer_CONTROL & AVI_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            AVI_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            AVI_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    AVI_Timer_Stop();
    AVI_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: AVI_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AVI_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void AVI_Timer_Wakeup(void) 
{
    AVI_Timer_RestoreConfig();
    #if(!AVI_Timer_UDB_CONTROL_REG_REMOVED)
        if(AVI_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                AVI_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
