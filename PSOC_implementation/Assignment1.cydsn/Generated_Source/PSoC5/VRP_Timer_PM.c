/*******************************************************************************
* File Name: VRP_Timer_PM.c
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

#include "VRP_Timer.h"

static VRP_Timer_backupStruct VRP_Timer_backup;


/*******************************************************************************
* Function Name: VRP_Timer_SaveConfig
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
*  VRP_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void VRP_Timer_SaveConfig(void) 
{
    #if (!VRP_Timer_UsingFixedFunction)
        VRP_Timer_backup.TimerUdb = VRP_Timer_ReadCounter();
        VRP_Timer_backup.InterruptMaskValue = VRP_Timer_STATUS_MASK;
        #if (VRP_Timer_UsingHWCaptureCounter)
            VRP_Timer_backup.TimerCaptureCounter = VRP_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!VRP_Timer_UDB_CONTROL_REG_REMOVED)
            VRP_Timer_backup.TimerControlRegister = VRP_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: VRP_Timer_RestoreConfig
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
*  VRP_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void VRP_Timer_RestoreConfig(void) 
{   
    #if (!VRP_Timer_UsingFixedFunction)

        VRP_Timer_WriteCounter(VRP_Timer_backup.TimerUdb);
        VRP_Timer_STATUS_MASK =VRP_Timer_backup.InterruptMaskValue;
        #if (VRP_Timer_UsingHWCaptureCounter)
            VRP_Timer_SetCaptureCount(VRP_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!VRP_Timer_UDB_CONTROL_REG_REMOVED)
            VRP_Timer_WriteControlRegister(VRP_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: VRP_Timer_Sleep
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
*  VRP_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void VRP_Timer_Sleep(void) 
{
    #if(!VRP_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(VRP_Timer_CTRL_ENABLE == (VRP_Timer_CONTROL & VRP_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            VRP_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            VRP_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    VRP_Timer_Stop();
    VRP_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: VRP_Timer_Wakeup
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
*  VRP_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VRP_Timer_Wakeup(void) 
{
    VRP_Timer_RestoreConfig();
    #if(!VRP_Timer_UDB_CONTROL_REG_REMOVED)
        if(VRP_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                VRP_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
