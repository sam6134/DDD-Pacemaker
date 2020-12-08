/*******************************************************************************
* File Name: isr_AEI.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_AEI_H)
#define CY_ISR_isr_AEI_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_AEI_Start(void);
void isr_AEI_StartEx(cyisraddress address);
void isr_AEI_Stop(void);

CY_ISR_PROTO(isr_AEI_Interrupt);

void isr_AEI_SetVector(cyisraddress address);
cyisraddress isr_AEI_GetVector(void);

void isr_AEI_SetPriority(uint8 priority);
uint8 isr_AEI_GetPriority(void);

void isr_AEI_Enable(void);
uint8 isr_AEI_GetState(void);
void isr_AEI_Disable(void);

void isr_AEI_SetPending(void);
void isr_AEI_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_AEI ISR. */
#define isr_AEI_INTC_VECTOR            ((reg32 *) isr_AEI__INTC_VECT)

/* Address of the isr_AEI ISR priority. */
#define isr_AEI_INTC_PRIOR             ((reg8 *) isr_AEI__INTC_PRIOR_REG)

/* Priority of the isr_AEI interrupt. */
#define isr_AEI_INTC_PRIOR_NUMBER      isr_AEI__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_AEI interrupt. */
#define isr_AEI_INTC_SET_EN            ((reg32 *) isr_AEI__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_AEI interrupt. */
#define isr_AEI_INTC_CLR_EN            ((reg32 *) isr_AEI__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_AEI interrupt state to pending. */
#define isr_AEI_INTC_SET_PD            ((reg32 *) isr_AEI__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_AEI interrupt. */
#define isr_AEI_INTC_CLR_PD            ((reg32 *) isr_AEI__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_AEI_H */


/* [] END OF FILE */
