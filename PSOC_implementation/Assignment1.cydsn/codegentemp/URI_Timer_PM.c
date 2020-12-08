/*******************************************************************************
* File Name: URI_Timer_PM.c
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

#include "URI_Timer.h"

static URI_Timer_backupStruct URI_Timer_backup;


/*******************************************************************************
* Function Name: URI_Timer_SaveConfig
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
*  URI_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void URI_Timer_SaveConfig(void) 
{
    #if (!URI_Timer_UsingFixedFunction)
        URI_Timer_backup.TimerUdb = URI_Timer_ReadCounter();
        URI_Timer_backup.InterruptMaskValue = URI_Timer_STATUS_MASK;
        #if (URI_Timer_UsingHWCaptureCounter)
            URI_Timer_backup.TimerCaptureCounter = URI_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!URI_Timer_UDB_CONTROL_REG_REMOVED)
            URI_Timer_backup.TimerControlRegister = URI_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: URI_Timer_RestoreConfig
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
*  URI_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void URI_Timer_RestoreConfig(void) 
{   
    #if (!URI_Timer_UsingFixedFunction)

        URI_Timer_WriteCounter(URI_Timer_backup.TimerUdb);
        URI_Timer_STATUS_MASK =URI_Timer_backup.InterruptMaskValue;
        #if (URI_Timer_UsingHWCaptureCounter)
            URI_Timer_SetCaptureCount(URI_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!URI_Timer_UDB_CONTROL_REG_REMOVED)
            URI_Timer_WriteControlRegister(URI_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: URI_Timer_Sleep
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
*  URI_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void URI_Timer_Sleep(void) 
{
    #if(!URI_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(URI_Timer_CTRL_ENABLE == (URI_Timer_CONTROL & URI_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            URI_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            URI_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    URI_Timer_Stop();
    URI_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: URI_Timer_Wakeup
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
*  URI_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void URI_Timer_Wakeup(void) 
{
    URI_Timer_RestoreConfig();
    #if(!URI_Timer_UDB_CONTROL_REG_REMOVED)
        if(URI_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                URI_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
