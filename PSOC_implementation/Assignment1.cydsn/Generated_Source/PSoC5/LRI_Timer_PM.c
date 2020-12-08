/*******************************************************************************
* File Name: LRI_Timer_PM.c
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

#include "LRI_Timer.h"

static LRI_Timer_backupStruct LRI_Timer_backup;


/*******************************************************************************
* Function Name: LRI_Timer_SaveConfig
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
*  LRI_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LRI_Timer_SaveConfig(void) 
{
    #if (!LRI_Timer_UsingFixedFunction)
        LRI_Timer_backup.TimerUdb = LRI_Timer_ReadCounter();
        LRI_Timer_backup.InterruptMaskValue = LRI_Timer_STATUS_MASK;
        #if (LRI_Timer_UsingHWCaptureCounter)
            LRI_Timer_backup.TimerCaptureCounter = LRI_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!LRI_Timer_UDB_CONTROL_REG_REMOVED)
            LRI_Timer_backup.TimerControlRegister = LRI_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: LRI_Timer_RestoreConfig
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
*  LRI_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LRI_Timer_RestoreConfig(void) 
{   
    #if (!LRI_Timer_UsingFixedFunction)

        LRI_Timer_WriteCounter(LRI_Timer_backup.TimerUdb);
        LRI_Timer_STATUS_MASK =LRI_Timer_backup.InterruptMaskValue;
        #if (LRI_Timer_UsingHWCaptureCounter)
            LRI_Timer_SetCaptureCount(LRI_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!LRI_Timer_UDB_CONTROL_REG_REMOVED)
            LRI_Timer_WriteControlRegister(LRI_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: LRI_Timer_Sleep
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
*  LRI_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void LRI_Timer_Sleep(void) 
{
    #if(!LRI_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(LRI_Timer_CTRL_ENABLE == (LRI_Timer_CONTROL & LRI_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            LRI_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            LRI_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    LRI_Timer_Stop();
    LRI_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: LRI_Timer_Wakeup
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
*  LRI_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LRI_Timer_Wakeup(void) 
{
    LRI_Timer_RestoreConfig();
    #if(!LRI_Timer_UDB_CONTROL_REG_REMOVED)
        if(LRI_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                LRI_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
