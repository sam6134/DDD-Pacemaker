/*******************************************************************************
* File Name: AEI_Timer_PM.c
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

#include "AEI_Timer.h"

static AEI_Timer_backupStruct AEI_Timer_backup;


/*******************************************************************************
* Function Name: AEI_Timer_SaveConfig
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
*  AEI_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void AEI_Timer_SaveConfig(void) 
{
    #if (!AEI_Timer_UsingFixedFunction)
        AEI_Timer_backup.TimerUdb = AEI_Timer_ReadCounter();
        AEI_Timer_backup.InterruptMaskValue = AEI_Timer_STATUS_MASK;
        #if (AEI_Timer_UsingHWCaptureCounter)
            AEI_Timer_backup.TimerCaptureCounter = AEI_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!AEI_Timer_UDB_CONTROL_REG_REMOVED)
            AEI_Timer_backup.TimerControlRegister = AEI_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: AEI_Timer_RestoreConfig
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
*  AEI_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void AEI_Timer_RestoreConfig(void) 
{   
    #if (!AEI_Timer_UsingFixedFunction)

        AEI_Timer_WriteCounter(AEI_Timer_backup.TimerUdb);
        AEI_Timer_STATUS_MASK =AEI_Timer_backup.InterruptMaskValue;
        #if (AEI_Timer_UsingHWCaptureCounter)
            AEI_Timer_SetCaptureCount(AEI_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!AEI_Timer_UDB_CONTROL_REG_REMOVED)
            AEI_Timer_WriteControlRegister(AEI_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: AEI_Timer_Sleep
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
*  AEI_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void AEI_Timer_Sleep(void) 
{
    #if(!AEI_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(AEI_Timer_CTRL_ENABLE == (AEI_Timer_CONTROL & AEI_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            AEI_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            AEI_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    AEI_Timer_Stop();
    AEI_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: AEI_Timer_Wakeup
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
*  AEI_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void AEI_Timer_Wakeup(void) 
{
    AEI_Timer_RestoreConfig();
    #if(!AEI_Timer_UDB_CONTROL_REG_REMOVED)
        if(AEI_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                AEI_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
