/*******************************************************************************
* File Name: PVARP_Timer_PM.c
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

#include "PVARP_Timer.h"

static PVARP_Timer_backupStruct PVARP_Timer_backup;


/*******************************************************************************
* Function Name: PVARP_Timer_SaveConfig
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
*  PVARP_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PVARP_Timer_SaveConfig(void) 
{
    #if (!PVARP_Timer_UsingFixedFunction)
        PVARP_Timer_backup.TimerUdb = PVARP_Timer_ReadCounter();
        PVARP_Timer_backup.InterruptMaskValue = PVARP_Timer_STATUS_MASK;
        #if (PVARP_Timer_UsingHWCaptureCounter)
            PVARP_Timer_backup.TimerCaptureCounter = PVARP_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!PVARP_Timer_UDB_CONTROL_REG_REMOVED)
            PVARP_Timer_backup.TimerControlRegister = PVARP_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: PVARP_Timer_RestoreConfig
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
*  PVARP_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PVARP_Timer_RestoreConfig(void) 
{   
    #if (!PVARP_Timer_UsingFixedFunction)

        PVARP_Timer_WriteCounter(PVARP_Timer_backup.TimerUdb);
        PVARP_Timer_STATUS_MASK =PVARP_Timer_backup.InterruptMaskValue;
        #if (PVARP_Timer_UsingHWCaptureCounter)
            PVARP_Timer_SetCaptureCount(PVARP_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!PVARP_Timer_UDB_CONTROL_REG_REMOVED)
            PVARP_Timer_WriteControlRegister(PVARP_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: PVARP_Timer_Sleep
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
*  PVARP_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void PVARP_Timer_Sleep(void) 
{
    #if(!PVARP_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(PVARP_Timer_CTRL_ENABLE == (PVARP_Timer_CONTROL & PVARP_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            PVARP_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            PVARP_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    PVARP_Timer_Stop();
    PVARP_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: PVARP_Timer_Wakeup
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
*  PVARP_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PVARP_Timer_Wakeup(void) 
{
    PVARP_Timer_RestoreConfig();
    #if(!PVARP_Timer_UDB_CONTROL_REG_REMOVED)
        if(PVARP_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                PVARP_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
