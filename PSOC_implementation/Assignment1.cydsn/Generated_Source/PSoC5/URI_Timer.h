/*******************************************************************************
* File Name: URI_Timer.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_URI_Timer_H)
#define CY_Timer_v2_60_URI_Timer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 URI_Timer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define URI_Timer_Resolution                 16u
#define URI_Timer_UsingFixedFunction         1u
#define URI_Timer_UsingHWCaptureCounter      0u
#define URI_Timer_SoftwareCaptureMode        0u
#define URI_Timer_SoftwareTriggerMode        0u
#define URI_Timer_UsingHWEnable              0u
#define URI_Timer_EnableTriggerMode          0u
#define URI_Timer_InterruptOnCaptureCount    0u
#define URI_Timer_RunModeUsed                0u
#define URI_Timer_ControlRegRemoved          0u

#if defined(URI_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define URI_Timer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (URI_Timer_UsingFixedFunction)
    #define URI_Timer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define URI_Timer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End URI_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!URI_Timer_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (URI_Timer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!URI_Timer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}URI_Timer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    URI_Timer_Start(void) ;
void    URI_Timer_Stop(void) ;

void    URI_Timer_SetInterruptMode(uint8 interruptMode) ;
uint8   URI_Timer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define URI_Timer_GetInterruptSource() URI_Timer_ReadStatusRegister()

#if(!URI_Timer_UDB_CONTROL_REG_REMOVED)
    uint8   URI_Timer_ReadControlRegister(void) ;
    void    URI_Timer_WriteControlRegister(uint8 control) ;
#endif /* (!URI_Timer_UDB_CONTROL_REG_REMOVED) */

uint16  URI_Timer_ReadPeriod(void) ;
void    URI_Timer_WritePeriod(uint16 period) ;
uint16  URI_Timer_ReadCounter(void) ;
void    URI_Timer_WriteCounter(uint16 counter) ;
uint16  URI_Timer_ReadCapture(void) ;
void    URI_Timer_SoftwareCapture(void) ;

#if(!URI_Timer_UsingFixedFunction) /* UDB Prototypes */
    #if (URI_Timer_SoftwareCaptureMode)
        void    URI_Timer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!URI_Timer_UsingFixedFunction) */

    #if (URI_Timer_SoftwareTriggerMode)
        void    URI_Timer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (URI_Timer_SoftwareTriggerMode) */

    #if (URI_Timer_EnableTriggerMode)
        void    URI_Timer_EnableTrigger(void) ;
        void    URI_Timer_DisableTrigger(void) ;
    #endif /* (URI_Timer_EnableTriggerMode) */


    #if(URI_Timer_InterruptOnCaptureCount)
        void    URI_Timer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (URI_Timer_InterruptOnCaptureCount) */

    #if (URI_Timer_UsingHWCaptureCounter)
        void    URI_Timer_SetCaptureCount(uint8 captureCount) ;
        uint8   URI_Timer_ReadCaptureCount(void) ;
    #endif /* (URI_Timer_UsingHWCaptureCounter) */

    void URI_Timer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void URI_Timer_Init(void)          ;
void URI_Timer_Enable(void)        ;
void URI_Timer_SaveConfig(void)    ;
void URI_Timer_RestoreConfig(void) ;
void URI_Timer_Sleep(void)         ;
void URI_Timer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define URI_Timer__B_TIMER__CM_NONE 0
#define URI_Timer__B_TIMER__CM_RISINGEDGE 1
#define URI_Timer__B_TIMER__CM_FALLINGEDGE 2
#define URI_Timer__B_TIMER__CM_EITHEREDGE 3
#define URI_Timer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define URI_Timer__B_TIMER__TM_NONE 0x00u
#define URI_Timer__B_TIMER__TM_RISINGEDGE 0x04u
#define URI_Timer__B_TIMER__TM_FALLINGEDGE 0x08u
#define URI_Timer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define URI_Timer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define URI_Timer_INIT_PERIOD             23999u
#define URI_Timer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << URI_Timer_CTRL_CAP_MODE_SHIFT))
#define URI_Timer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << URI_Timer_CTRL_TRIG_MODE_SHIFT))
#if (URI_Timer_UsingFixedFunction)
    #define URI_Timer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << URI_Timer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << URI_Timer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define URI_Timer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << URI_Timer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << URI_Timer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << URI_Timer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (URI_Timer_UsingFixedFunction) */
#define URI_Timer_INIT_CAPTURE_COUNT      (2u)
#define URI_Timer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << URI_Timer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (URI_Timer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define URI_Timer_STATUS         (*(reg8 *) URI_Timer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define URI_Timer_STATUS_MASK    (*(reg8 *) URI_Timer_TimerHW__SR0 )
    #define URI_Timer_CONTROL        (*(reg8 *) URI_Timer_TimerHW__CFG0)
    #define URI_Timer_CONTROL2       (*(reg8 *) URI_Timer_TimerHW__CFG1)
    #define URI_Timer_CONTROL2_PTR   ( (reg8 *) URI_Timer_TimerHW__CFG1)
    #define URI_Timer_RT1            (*(reg8 *) URI_Timer_TimerHW__RT1)
    #define URI_Timer_RT1_PTR        ( (reg8 *) URI_Timer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define URI_Timer_CONTROL3       (*(reg8 *) URI_Timer_TimerHW__CFG2)
        #define URI_Timer_CONTROL3_PTR   ( (reg8 *) URI_Timer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define URI_Timer_GLOBAL_ENABLE  (*(reg8 *) URI_Timer_TimerHW__PM_ACT_CFG)
    #define URI_Timer_GLOBAL_STBY_ENABLE  (*(reg8 *) URI_Timer_TimerHW__PM_STBY_CFG)

    #define URI_Timer_CAPTURE_LSB         (* (reg16 *) URI_Timer_TimerHW__CAP0 )
    #define URI_Timer_CAPTURE_LSB_PTR       ((reg16 *) URI_Timer_TimerHW__CAP0 )
    #define URI_Timer_PERIOD_LSB          (* (reg16 *) URI_Timer_TimerHW__PER0 )
    #define URI_Timer_PERIOD_LSB_PTR        ((reg16 *) URI_Timer_TimerHW__PER0 )
    #define URI_Timer_COUNTER_LSB         (* (reg16 *) URI_Timer_TimerHW__CNT_CMP0 )
    #define URI_Timer_COUNTER_LSB_PTR       ((reg16 *) URI_Timer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define URI_Timer_BLOCK_EN_MASK                     URI_Timer_TimerHW__PM_ACT_MSK
    #define URI_Timer_BLOCK_STBY_EN_MASK                URI_Timer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define URI_Timer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define URI_Timer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define URI_Timer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define URI_Timer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define URI_Timer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define URI_Timer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << URI_Timer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define URI_Timer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define URI_Timer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << URI_Timer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define URI_Timer_CTRL_MODE_SHIFT                 0x01u
        #define URI_Timer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << URI_Timer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define URI_Timer_CTRL_RCOD_SHIFT        0x02u
        #define URI_Timer_CTRL_ENBL_SHIFT        0x00u
        #define URI_Timer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define URI_Timer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << URI_Timer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define URI_Timer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << URI_Timer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define URI_Timer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << URI_Timer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define URI_Timer_CTRL_RCOD       ((uint8)((uint8)0x03u << URI_Timer_CTRL_RCOD_SHIFT))
        #define URI_Timer_CTRL_ENBL       ((uint8)((uint8)0x80u << URI_Timer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define URI_Timer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define URI_Timer_RT1_MASK                        ((uint8)((uint8)0x03u << URI_Timer_RT1_SHIFT))
    #define URI_Timer_SYNC                            ((uint8)((uint8)0x03u << URI_Timer_RT1_SHIFT))
    #define URI_Timer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define URI_Timer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << URI_Timer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define URI_Timer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << URI_Timer_SYNCDSI_SHIFT))

    #define URI_Timer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << URI_Timer_CTRL_MODE_SHIFT))
    #define URI_Timer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << URI_Timer_CTRL_MODE_SHIFT))
    #define URI_Timer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << URI_Timer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define URI_Timer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define URI_Timer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define URI_Timer_STATUS_TC_INT_MASK_SHIFT        (URI_Timer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define URI_Timer_STATUS_CAPTURE_INT_MASK_SHIFT   (URI_Timer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define URI_Timer_STATUS_TC                       ((uint8)((uint8)0x01u << URI_Timer_STATUS_TC_SHIFT))
    #define URI_Timer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << URI_Timer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define URI_Timer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << URI_Timer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define URI_Timer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << URI_Timer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define URI_Timer_STATUS              (* (reg8 *) URI_Timer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define URI_Timer_STATUS_MASK         (* (reg8 *) URI_Timer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define URI_Timer_STATUS_AUX_CTRL     (* (reg8 *) URI_Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define URI_Timer_CONTROL             (* (reg8 *) URI_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(URI_Timer_Resolution <= 8u) /* 8-bit Timer */
        #define URI_Timer_CAPTURE_LSB         (* (reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define URI_Timer_CAPTURE_LSB_PTR       ((reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define URI_Timer_PERIOD_LSB          (* (reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define URI_Timer_PERIOD_LSB_PTR        ((reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define URI_Timer_COUNTER_LSB         (* (reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define URI_Timer_COUNTER_LSB_PTR       ((reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(URI_Timer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define URI_Timer_CAPTURE_LSB         (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define URI_Timer_CAPTURE_LSB_PTR       ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define URI_Timer_PERIOD_LSB          (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define URI_Timer_PERIOD_LSB_PTR        ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define URI_Timer_COUNTER_LSB         (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define URI_Timer_COUNTER_LSB_PTR       ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define URI_Timer_CAPTURE_LSB         (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define URI_Timer_CAPTURE_LSB_PTR       ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define URI_Timer_PERIOD_LSB          (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define URI_Timer_PERIOD_LSB_PTR        ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define URI_Timer_COUNTER_LSB         (* (reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define URI_Timer_COUNTER_LSB_PTR       ((reg16 *) URI_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(URI_Timer_Resolution <= 24u)/* 24-bit Timer */
        #define URI_Timer_CAPTURE_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define URI_Timer_CAPTURE_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define URI_Timer_PERIOD_LSB          (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define URI_Timer_PERIOD_LSB_PTR        ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define URI_Timer_COUNTER_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define URI_Timer_COUNTER_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define URI_Timer_CAPTURE_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define URI_Timer_CAPTURE_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define URI_Timer_PERIOD_LSB          (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define URI_Timer_PERIOD_LSB_PTR        ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define URI_Timer_COUNTER_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define URI_Timer_COUNTER_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define URI_Timer_CAPTURE_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define URI_Timer_CAPTURE_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define URI_Timer_PERIOD_LSB          (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define URI_Timer_PERIOD_LSB_PTR        ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define URI_Timer_COUNTER_LSB         (* (reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define URI_Timer_COUNTER_LSB_PTR       ((reg32 *) URI_Timer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define URI_Timer_COUNTER_LSB_PTR_8BIT       ((reg8 *) URI_Timer_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (URI_Timer_UsingHWCaptureCounter)
        #define URI_Timer_CAP_COUNT              (*(reg8 *) URI_Timer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define URI_Timer_CAP_COUNT_PTR          ( (reg8 *) URI_Timer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define URI_Timer_CAPTURE_COUNT_CTRL     (*(reg8 *) URI_Timer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define URI_Timer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) URI_Timer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (URI_Timer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define URI_Timer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define URI_Timer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define URI_Timer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define URI_Timer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define URI_Timer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define URI_Timer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << URI_Timer_CTRL_INTCNT_SHIFT))
    #define URI_Timer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << URI_Timer_CTRL_TRIG_MODE_SHIFT))
    #define URI_Timer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << URI_Timer_CTRL_TRIG_EN_SHIFT))
    #define URI_Timer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << URI_Timer_CTRL_CAP_MODE_SHIFT))
    #define URI_Timer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << URI_Timer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define URI_Timer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define URI_Timer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define URI_Timer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define URI_Timer_STATUS_TC_INT_MASK_SHIFT       URI_Timer_STATUS_TC_SHIFT
    #define URI_Timer_STATUS_CAPTURE_INT_MASK_SHIFT  URI_Timer_STATUS_CAPTURE_SHIFT
    #define URI_Timer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define URI_Timer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define URI_Timer_STATUS_FIFOFULL_INT_MASK_SHIFT URI_Timer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define URI_Timer_STATUS_TC                      ((uint8)((uint8)0x01u << URI_Timer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define URI_Timer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << URI_Timer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define URI_Timer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << URI_Timer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define URI_Timer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << URI_Timer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define URI_Timer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << URI_Timer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define URI_Timer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << URI_Timer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define URI_Timer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << URI_Timer_STATUS_FIFOFULL_SHIFT))

    #define URI_Timer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define URI_Timer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define URI_Timer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define URI_Timer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define URI_Timer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define URI_Timer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_URI_Timer_H */


/* [] END OF FILE */
