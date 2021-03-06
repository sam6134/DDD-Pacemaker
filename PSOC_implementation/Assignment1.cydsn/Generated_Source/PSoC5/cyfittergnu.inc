.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* USBUART_arb_int */
.set USBUART_arb_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_arb_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_arb_int__INTC_MASK, 0x400000
.set USBUART_arb_int__INTC_NUMBER, 22
.set USBUART_arb_int__INTC_PRIOR_NUM, 7
.set USBUART_arb_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_22
.set USBUART_arb_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_arb_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_bus_reset */
.set USBUART_bus_reset__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_bus_reset__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_bus_reset__INTC_MASK, 0x800000
.set USBUART_bus_reset__INTC_NUMBER, 23
.set USBUART_bus_reset__INTC_PRIOR_NUM, 7
.set USBUART_bus_reset__INTC_PRIOR_REG, CYREG_NVIC_PRI_23
.set USBUART_bus_reset__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_bus_reset__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_Dm */
.set USBUART_Dm__0__INTTYPE, CYREG_PICU15_INTTYPE7
.set USBUART_Dm__0__MASK, 0x80
.set USBUART_Dm__0__PC, CYREG_IO_PC_PRT15_7_6_PC1
.set USBUART_Dm__0__PORT, 15
.set USBUART_Dm__0__SHIFT, 7
.set USBUART_Dm__AG, CYREG_PRT15_AG
.set USBUART_Dm__AMUX, CYREG_PRT15_AMUX
.set USBUART_Dm__BIE, CYREG_PRT15_BIE
.set USBUART_Dm__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USBUART_Dm__BYP, CYREG_PRT15_BYP
.set USBUART_Dm__CTL, CYREG_PRT15_CTL
.set USBUART_Dm__DM0, CYREG_PRT15_DM0
.set USBUART_Dm__DM1, CYREG_PRT15_DM1
.set USBUART_Dm__DM2, CYREG_PRT15_DM2
.set USBUART_Dm__DR, CYREG_PRT15_DR
.set USBUART_Dm__INP_DIS, CYREG_PRT15_INP_DIS
.set USBUART_Dm__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set USBUART_Dm__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USBUART_Dm__LCD_EN, CYREG_PRT15_LCD_EN
.set USBUART_Dm__MASK, 0x80
.set USBUART_Dm__PORT, 15
.set USBUART_Dm__PRT, CYREG_PRT15_PRT
.set USBUART_Dm__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USBUART_Dm__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USBUART_Dm__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USBUART_Dm__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USBUART_Dm__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USBUART_Dm__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USBUART_Dm__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USBUART_Dm__PS, CYREG_PRT15_PS
.set USBUART_Dm__SHIFT, 7
.set USBUART_Dm__SLW, CYREG_PRT15_SLW

/* USBUART_Dp */
.set USBUART_Dp__0__INTTYPE, CYREG_PICU15_INTTYPE6
.set USBUART_Dp__0__MASK, 0x40
.set USBUART_Dp__0__PC, CYREG_IO_PC_PRT15_7_6_PC0
.set USBUART_Dp__0__PORT, 15
.set USBUART_Dp__0__SHIFT, 6
.set USBUART_Dp__AG, CYREG_PRT15_AG
.set USBUART_Dp__AMUX, CYREG_PRT15_AMUX
.set USBUART_Dp__BIE, CYREG_PRT15_BIE
.set USBUART_Dp__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USBUART_Dp__BYP, CYREG_PRT15_BYP
.set USBUART_Dp__CTL, CYREG_PRT15_CTL
.set USBUART_Dp__DM0, CYREG_PRT15_DM0
.set USBUART_Dp__DM1, CYREG_PRT15_DM1
.set USBUART_Dp__DM2, CYREG_PRT15_DM2
.set USBUART_Dp__DR, CYREG_PRT15_DR
.set USBUART_Dp__INP_DIS, CYREG_PRT15_INP_DIS
.set USBUART_Dp__INTSTAT, CYREG_PICU15_INTSTAT
.set USBUART_Dp__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set USBUART_Dp__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USBUART_Dp__LCD_EN, CYREG_PRT15_LCD_EN
.set USBUART_Dp__MASK, 0x40
.set USBUART_Dp__PORT, 15
.set USBUART_Dp__PRT, CYREG_PRT15_PRT
.set USBUART_Dp__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USBUART_Dp__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USBUART_Dp__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USBUART_Dp__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USBUART_Dp__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USBUART_Dp__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USBUART_Dp__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USBUART_Dp__PS, CYREG_PRT15_PS
.set USBUART_Dp__SHIFT, 6
.set USBUART_Dp__SLW, CYREG_PRT15_SLW
.set USBUART_Dp__SNAP, CYREG_PICU_15_SNAP_15

/* USBUART_dp_int */
.set USBUART_dp_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_dp_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_dp_int__INTC_MASK, 0x1000
.set USBUART_dp_int__INTC_NUMBER, 12
.set USBUART_dp_int__INTC_PRIOR_NUM, 7
.set USBUART_dp_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_12
.set USBUART_dp_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_dp_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_ep_0 */
.set USBUART_ep_0__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_ep_0__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_ep_0__INTC_MASK, 0x1000000
.set USBUART_ep_0__INTC_NUMBER, 24
.set USBUART_ep_0__INTC_PRIOR_NUM, 7
.set USBUART_ep_0__INTC_PRIOR_REG, CYREG_NVIC_PRI_24
.set USBUART_ep_0__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_ep_0__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_ep_1 */
.set USBUART_ep_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_ep_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_ep_1__INTC_MASK, 0x01
.set USBUART_ep_1__INTC_NUMBER, 0
.set USBUART_ep_1__INTC_PRIOR_NUM, 7
.set USBUART_ep_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set USBUART_ep_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_ep_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_ep_2 */
.set USBUART_ep_2__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_ep_2__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_ep_2__INTC_MASK, 0x02
.set USBUART_ep_2__INTC_NUMBER, 1
.set USBUART_ep_2__INTC_PRIOR_NUM, 7
.set USBUART_ep_2__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set USBUART_ep_2__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_ep_2__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_ep_3 */
.set USBUART_ep_3__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_ep_3__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_ep_3__INTC_MASK, 0x04
.set USBUART_ep_3__INTC_NUMBER, 2
.set USBUART_ep_3__INTC_PRIOR_NUM, 7
.set USBUART_ep_3__INTC_PRIOR_REG, CYREG_NVIC_PRI_2
.set USBUART_ep_3__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_ep_3__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_sof_int */
.set USBUART_sof_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBUART_sof_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBUART_sof_int__INTC_MASK, 0x200000
.set USBUART_sof_int__INTC_NUMBER, 21
.set USBUART_sof_int__INTC_PRIOR_NUM, 7
.set USBUART_sof_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_21
.set USBUART_sof_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBUART_sof_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBUART_USB */
.set USBUART_USB__ARB_CFG, CYREG_USB_ARB_CFG
.set USBUART_USB__ARB_EP1_CFG, CYREG_USB_ARB_EP1_CFG
.set USBUART_USB__ARB_EP1_INT_EN, CYREG_USB_ARB_EP1_INT_EN
.set USBUART_USB__ARB_EP1_SR, CYREG_USB_ARB_EP1_SR
.set USBUART_USB__ARB_EP2_CFG, CYREG_USB_ARB_EP2_CFG
.set USBUART_USB__ARB_EP2_INT_EN, CYREG_USB_ARB_EP2_INT_EN
.set USBUART_USB__ARB_EP2_SR, CYREG_USB_ARB_EP2_SR
.set USBUART_USB__ARB_EP3_CFG, CYREG_USB_ARB_EP3_CFG
.set USBUART_USB__ARB_EP3_INT_EN, CYREG_USB_ARB_EP3_INT_EN
.set USBUART_USB__ARB_EP3_SR, CYREG_USB_ARB_EP3_SR
.set USBUART_USB__ARB_EP4_CFG, CYREG_USB_ARB_EP4_CFG
.set USBUART_USB__ARB_EP4_INT_EN, CYREG_USB_ARB_EP4_INT_EN
.set USBUART_USB__ARB_EP4_SR, CYREG_USB_ARB_EP4_SR
.set USBUART_USB__ARB_EP5_CFG, CYREG_USB_ARB_EP5_CFG
.set USBUART_USB__ARB_EP5_INT_EN, CYREG_USB_ARB_EP5_INT_EN
.set USBUART_USB__ARB_EP5_SR, CYREG_USB_ARB_EP5_SR
.set USBUART_USB__ARB_EP6_CFG, CYREG_USB_ARB_EP6_CFG
.set USBUART_USB__ARB_EP6_INT_EN, CYREG_USB_ARB_EP6_INT_EN
.set USBUART_USB__ARB_EP6_SR, CYREG_USB_ARB_EP6_SR
.set USBUART_USB__ARB_EP7_CFG, CYREG_USB_ARB_EP7_CFG
.set USBUART_USB__ARB_EP7_INT_EN, CYREG_USB_ARB_EP7_INT_EN
.set USBUART_USB__ARB_EP7_SR, CYREG_USB_ARB_EP7_SR
.set USBUART_USB__ARB_EP8_CFG, CYREG_USB_ARB_EP8_CFG
.set USBUART_USB__ARB_EP8_INT_EN, CYREG_USB_ARB_EP8_INT_EN
.set USBUART_USB__ARB_EP8_SR, CYREG_USB_ARB_EP8_SR
.set USBUART_USB__ARB_INT_EN, CYREG_USB_ARB_INT_EN
.set USBUART_USB__ARB_INT_SR, CYREG_USB_ARB_INT_SR
.set USBUART_USB__ARB_RW1_DR, CYREG_USB_ARB_RW1_DR
.set USBUART_USB__ARB_RW1_RA, CYREG_USB_ARB_RW1_RA
.set USBUART_USB__ARB_RW1_RA_MSB, CYREG_USB_ARB_RW1_RA_MSB
.set USBUART_USB__ARB_RW1_WA, CYREG_USB_ARB_RW1_WA
.set USBUART_USB__ARB_RW1_WA_MSB, CYREG_USB_ARB_RW1_WA_MSB
.set USBUART_USB__ARB_RW2_DR, CYREG_USB_ARB_RW2_DR
.set USBUART_USB__ARB_RW2_RA, CYREG_USB_ARB_RW2_RA
.set USBUART_USB__ARB_RW2_RA_MSB, CYREG_USB_ARB_RW2_RA_MSB
.set USBUART_USB__ARB_RW2_WA, CYREG_USB_ARB_RW2_WA
.set USBUART_USB__ARB_RW2_WA_MSB, CYREG_USB_ARB_RW2_WA_MSB
.set USBUART_USB__ARB_RW3_DR, CYREG_USB_ARB_RW3_DR
.set USBUART_USB__ARB_RW3_RA, CYREG_USB_ARB_RW3_RA
.set USBUART_USB__ARB_RW3_RA_MSB, CYREG_USB_ARB_RW3_RA_MSB
.set USBUART_USB__ARB_RW3_WA, CYREG_USB_ARB_RW3_WA
.set USBUART_USB__ARB_RW3_WA_MSB, CYREG_USB_ARB_RW3_WA_MSB
.set USBUART_USB__ARB_RW4_DR, CYREG_USB_ARB_RW4_DR
.set USBUART_USB__ARB_RW4_RA, CYREG_USB_ARB_RW4_RA
.set USBUART_USB__ARB_RW4_RA_MSB, CYREG_USB_ARB_RW4_RA_MSB
.set USBUART_USB__ARB_RW4_WA, CYREG_USB_ARB_RW4_WA
.set USBUART_USB__ARB_RW4_WA_MSB, CYREG_USB_ARB_RW4_WA_MSB
.set USBUART_USB__ARB_RW5_DR, CYREG_USB_ARB_RW5_DR
.set USBUART_USB__ARB_RW5_RA, CYREG_USB_ARB_RW5_RA
.set USBUART_USB__ARB_RW5_RA_MSB, CYREG_USB_ARB_RW5_RA_MSB
.set USBUART_USB__ARB_RW5_WA, CYREG_USB_ARB_RW5_WA
.set USBUART_USB__ARB_RW5_WA_MSB, CYREG_USB_ARB_RW5_WA_MSB
.set USBUART_USB__ARB_RW6_DR, CYREG_USB_ARB_RW6_DR
.set USBUART_USB__ARB_RW6_RA, CYREG_USB_ARB_RW6_RA
.set USBUART_USB__ARB_RW6_RA_MSB, CYREG_USB_ARB_RW6_RA_MSB
.set USBUART_USB__ARB_RW6_WA, CYREG_USB_ARB_RW6_WA
.set USBUART_USB__ARB_RW6_WA_MSB, CYREG_USB_ARB_RW6_WA_MSB
.set USBUART_USB__ARB_RW7_DR, CYREG_USB_ARB_RW7_DR
.set USBUART_USB__ARB_RW7_RA, CYREG_USB_ARB_RW7_RA
.set USBUART_USB__ARB_RW7_RA_MSB, CYREG_USB_ARB_RW7_RA_MSB
.set USBUART_USB__ARB_RW7_WA, CYREG_USB_ARB_RW7_WA
.set USBUART_USB__ARB_RW7_WA_MSB, CYREG_USB_ARB_RW7_WA_MSB
.set USBUART_USB__ARB_RW8_DR, CYREG_USB_ARB_RW8_DR
.set USBUART_USB__ARB_RW8_RA, CYREG_USB_ARB_RW8_RA
.set USBUART_USB__ARB_RW8_RA_MSB, CYREG_USB_ARB_RW8_RA_MSB
.set USBUART_USB__ARB_RW8_WA, CYREG_USB_ARB_RW8_WA
.set USBUART_USB__ARB_RW8_WA_MSB, CYREG_USB_ARB_RW8_WA_MSB
.set USBUART_USB__BUF_SIZE, CYREG_USB_BUF_SIZE
.set USBUART_USB__BUS_RST_CNT, CYREG_USB_BUS_RST_CNT
.set USBUART_USB__CR0, CYREG_USB_CR0
.set USBUART_USB__CR1, CYREG_USB_CR1
.set USBUART_USB__CWA, CYREG_USB_CWA
.set USBUART_USB__CWA_MSB, CYREG_USB_CWA_MSB
.set USBUART_USB__DMA_THRES, CYREG_USB_DMA_THRES
.set USBUART_USB__DMA_THRES_MSB, CYREG_USB_DMA_THRES_MSB
.set USBUART_USB__DYN_RECONFIG, CYREG_USB_DYN_RECONFIG
.set USBUART_USB__EP_ACTIVE, CYREG_USB_EP_ACTIVE
.set USBUART_USB__EP_TYPE, CYREG_USB_EP_TYPE
.set USBUART_USB__EP0_CNT, CYREG_USB_EP0_CNT
.set USBUART_USB__EP0_CR, CYREG_USB_EP0_CR
.set USBUART_USB__EP0_DR0, CYREG_USB_EP0_DR0
.set USBUART_USB__EP0_DR1, CYREG_USB_EP0_DR1
.set USBUART_USB__EP0_DR2, CYREG_USB_EP0_DR2
.set USBUART_USB__EP0_DR3, CYREG_USB_EP0_DR3
.set USBUART_USB__EP0_DR4, CYREG_USB_EP0_DR4
.set USBUART_USB__EP0_DR5, CYREG_USB_EP0_DR5
.set USBUART_USB__EP0_DR6, CYREG_USB_EP0_DR6
.set USBUART_USB__EP0_DR7, CYREG_USB_EP0_DR7
.set USBUART_USB__MEM_DATA, CYREG_USB_MEM_DATA_MBASE
.set USBUART_USB__PM_ACT_CFG, CYREG_PM_ACT_CFG5
.set USBUART_USB__PM_ACT_MSK, 0x01
.set USBUART_USB__PM_STBY_CFG, CYREG_PM_STBY_CFG5
.set USBUART_USB__PM_STBY_MSK, 0x01
.set USBUART_USB__SIE_EP_INT_EN, CYREG_USB_SIE_EP_INT_EN
.set USBUART_USB__SIE_EP_INT_SR, CYREG_USB_SIE_EP_INT_SR
.set USBUART_USB__SIE_EP1_CNT0, CYREG_USB_SIE_EP1_CNT0
.set USBUART_USB__SIE_EP1_CNT1, CYREG_USB_SIE_EP1_CNT1
.set USBUART_USB__SIE_EP1_CR0, CYREG_USB_SIE_EP1_CR0
.set USBUART_USB__SIE_EP2_CNT0, CYREG_USB_SIE_EP2_CNT0
.set USBUART_USB__SIE_EP2_CNT1, CYREG_USB_SIE_EP2_CNT1
.set USBUART_USB__SIE_EP2_CR0, CYREG_USB_SIE_EP2_CR0
.set USBUART_USB__SIE_EP3_CNT0, CYREG_USB_SIE_EP3_CNT0
.set USBUART_USB__SIE_EP3_CNT1, CYREG_USB_SIE_EP3_CNT1
.set USBUART_USB__SIE_EP3_CR0, CYREG_USB_SIE_EP3_CR0
.set USBUART_USB__SIE_EP4_CNT0, CYREG_USB_SIE_EP4_CNT0
.set USBUART_USB__SIE_EP4_CNT1, CYREG_USB_SIE_EP4_CNT1
.set USBUART_USB__SIE_EP4_CR0, CYREG_USB_SIE_EP4_CR0
.set USBUART_USB__SIE_EP5_CNT0, CYREG_USB_SIE_EP5_CNT0
.set USBUART_USB__SIE_EP5_CNT1, CYREG_USB_SIE_EP5_CNT1
.set USBUART_USB__SIE_EP5_CR0, CYREG_USB_SIE_EP5_CR0
.set USBUART_USB__SIE_EP6_CNT0, CYREG_USB_SIE_EP6_CNT0
.set USBUART_USB__SIE_EP6_CNT1, CYREG_USB_SIE_EP6_CNT1
.set USBUART_USB__SIE_EP6_CR0, CYREG_USB_SIE_EP6_CR0
.set USBUART_USB__SIE_EP7_CNT0, CYREG_USB_SIE_EP7_CNT0
.set USBUART_USB__SIE_EP7_CNT1, CYREG_USB_SIE_EP7_CNT1
.set USBUART_USB__SIE_EP7_CR0, CYREG_USB_SIE_EP7_CR0
.set USBUART_USB__SIE_EP8_CNT0, CYREG_USB_SIE_EP8_CNT0
.set USBUART_USB__SIE_EP8_CNT1, CYREG_USB_SIE_EP8_CNT1
.set USBUART_USB__SIE_EP8_CR0, CYREG_USB_SIE_EP8_CR0
.set USBUART_USB__SOF0, CYREG_USB_SOF0
.set USBUART_USB__SOF1, CYREG_USB_SOF1
.set USBUART_USB__USB_CLK_EN, CYREG_USB_USB_CLK_EN
.set USBUART_USB__USBIO_CR0, CYREG_USB_USBIO_CR0
.set USBUART_USB__USBIO_CR1, CYREG_USB_USBIO_CR1

/* isr_AEI */
.set isr_AEI__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_AEI__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_AEI__INTC_MASK, 0x08
.set isr_AEI__INTC_NUMBER, 3
.set isr_AEI__INTC_PRIOR_NUM, 7
.set isr_AEI__INTC_PRIOR_REG, CYREG_NVIC_PRI_3
.set isr_AEI__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_AEI__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* isr_AVI */
.set isr_AVI__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_AVI__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_AVI__INTC_MASK, 0x10
.set isr_AVI__INTC_NUMBER, 4
.set isr_AVI__INTC_PRIOR_NUM, 7
.set isr_AVI__INTC_PRIOR_REG, CYREG_NVIC_PRI_4
.set isr_AVI__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_AVI__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* isr_LRI */
.set isr_LRI__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_LRI__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_LRI__INTC_MASK, 0x20
.set isr_LRI__INTC_NUMBER, 5
.set isr_LRI__INTC_PRIOR_NUM, 7
.set isr_LRI__INTC_PRIOR_REG, CYREG_NVIC_PRI_5
.set isr_LRI__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_LRI__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* isr_URI */
.set isr_URI__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_URI__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_URI__INTC_MASK, 0x80
.set isr_URI__INTC_NUMBER, 7
.set isr_URI__INTC_PRIOR_NUM, 7
.set isr_URI__INTC_PRIOR_REG, CYREG_NVIC_PRI_7
.set isr_URI__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_URI__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* isr_VRP */
.set isr_VRP__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_VRP__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_VRP__INTC_MASK, 0x100
.set isr_VRP__INTC_NUMBER, 8
.set isr_VRP__INTC_PRIOR_NUM, 7
.set isr_VRP__INTC_PRIOR_REG, CYREG_NVIC_PRI_8
.set isr_VRP__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_VRP__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* AEI_Timer_TimerHW */
.set AEI_Timer_TimerHW__CAP0, CYREG_TMR0_CAP0
.set AEI_Timer_TimerHW__CAP1, CYREG_TMR0_CAP1
.set AEI_Timer_TimerHW__CFG0, CYREG_TMR0_CFG0
.set AEI_Timer_TimerHW__CFG1, CYREG_TMR0_CFG1
.set AEI_Timer_TimerHW__CFG2, CYREG_TMR0_CFG2
.set AEI_Timer_TimerHW__CNT_CMP0, CYREG_TMR0_CNT_CMP0
.set AEI_Timer_TimerHW__CNT_CMP1, CYREG_TMR0_CNT_CMP1
.set AEI_Timer_TimerHW__PER0, CYREG_TMR0_PER0
.set AEI_Timer_TimerHW__PER1, CYREG_TMR0_PER1
.set AEI_Timer_TimerHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set AEI_Timer_TimerHW__PM_ACT_MSK, 0x01
.set AEI_Timer_TimerHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set AEI_Timer_TimerHW__PM_STBY_MSK, 0x01
.set AEI_Timer_TimerHW__RT0, CYREG_TMR0_RT0
.set AEI_Timer_TimerHW__RT1, CYREG_TMR0_RT1
.set AEI_Timer_TimerHW__SR0, CYREG_TMR0_SR0

/* AVI_Timer_TimerHW */
.set AVI_Timer_TimerHW__CAP0, CYREG_TMR1_CAP0
.set AVI_Timer_TimerHW__CAP1, CYREG_TMR1_CAP1
.set AVI_Timer_TimerHW__CFG0, CYREG_TMR1_CFG0
.set AVI_Timer_TimerHW__CFG1, CYREG_TMR1_CFG1
.set AVI_Timer_TimerHW__CFG2, CYREG_TMR1_CFG2
.set AVI_Timer_TimerHW__CNT_CMP0, CYREG_TMR1_CNT_CMP0
.set AVI_Timer_TimerHW__CNT_CMP1, CYREG_TMR1_CNT_CMP1
.set AVI_Timer_TimerHW__PER0, CYREG_TMR1_PER0
.set AVI_Timer_TimerHW__PER1, CYREG_TMR1_PER1
.set AVI_Timer_TimerHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set AVI_Timer_TimerHW__PM_ACT_MSK, 0x02
.set AVI_Timer_TimerHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set AVI_Timer_TimerHW__PM_STBY_MSK, 0x02
.set AVI_Timer_TimerHW__RT0, CYREG_TMR1_RT0
.set AVI_Timer_TimerHW__RT1, CYREG_TMR1_RT1
.set AVI_Timer_TimerHW__SR0, CYREG_TMR1_SR0

/* LRI_Timer_TimerHW */
.set LRI_Timer_TimerHW__CAP0, CYREG_TMR2_CAP0
.set LRI_Timer_TimerHW__CAP1, CYREG_TMR2_CAP1
.set LRI_Timer_TimerHW__CFG0, CYREG_TMR2_CFG0
.set LRI_Timer_TimerHW__CFG1, CYREG_TMR2_CFG1
.set LRI_Timer_TimerHW__CFG2, CYREG_TMR2_CFG2
.set LRI_Timer_TimerHW__CNT_CMP0, CYREG_TMR2_CNT_CMP0
.set LRI_Timer_TimerHW__CNT_CMP1, CYREG_TMR2_CNT_CMP1
.set LRI_Timer_TimerHW__PER0, CYREG_TMR2_PER0
.set LRI_Timer_TimerHW__PER1, CYREG_TMR2_PER1
.set LRI_Timer_TimerHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set LRI_Timer_TimerHW__PM_ACT_MSK, 0x04
.set LRI_Timer_TimerHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set LRI_Timer_TimerHW__PM_STBY_MSK, 0x04
.set LRI_Timer_TimerHW__RT0, CYREG_TMR2_RT0
.set LRI_Timer_TimerHW__RT1, CYREG_TMR2_RT1
.set LRI_Timer_TimerHW__SR0, CYREG_TMR2_SR0

/* URI_Timer_TimerHW */
.set URI_Timer_TimerHW__CAP0, CYREG_TMR3_CAP0
.set URI_Timer_TimerHW__CAP1, CYREG_TMR3_CAP1
.set URI_Timer_TimerHW__CFG0, CYREG_TMR3_CFG0
.set URI_Timer_TimerHW__CFG1, CYREG_TMR3_CFG1
.set URI_Timer_TimerHW__CFG2, CYREG_TMR3_CFG2
.set URI_Timer_TimerHW__CNT_CMP0, CYREG_TMR3_CNT_CMP0
.set URI_Timer_TimerHW__CNT_CMP1, CYREG_TMR3_CNT_CMP1
.set URI_Timer_TimerHW__PER0, CYREG_TMR3_PER0
.set URI_Timer_TimerHW__PER1, CYREG_TMR3_PER1
.set URI_Timer_TimerHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set URI_Timer_TimerHW__PM_ACT_MSK, 0x08
.set URI_Timer_TimerHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set URI_Timer_TimerHW__PM_STBY_MSK, 0x08
.set URI_Timer_TimerHW__RT0, CYREG_TMR3_RT0
.set URI_Timer_TimerHW__RT1, CYREG_TMR3_RT1
.set URI_Timer_TimerHW__SR0, CYREG_TMR3_SR0

/* VRP_Timer_TimerUDB */
.set VRP_Timer_TimerUDB_rstSts_stsreg__0__MASK, 0x01
.set VRP_Timer_TimerUDB_rstSts_stsreg__0__POS, 0
.set VRP_Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB11_12_ST
.set VRP_Timer_TimerUDB_rstSts_stsreg__2__MASK, 0x04
.set VRP_Timer_TimerUDB_rstSts_stsreg__2__POS, 2
.set VRP_Timer_TimerUDB_rstSts_stsreg__3__MASK, 0x08
.set VRP_Timer_TimerUDB_rstSts_stsreg__3__POS, 3
.set VRP_Timer_TimerUDB_rstSts_stsreg__MASK, 0x0D
.set VRP_Timer_TimerUDB_rstSts_stsreg__MASK_REG, CYREG_B0_UDB11_MSK
.set VRP_Timer_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__STATUS_CNT_REG, CYREG_B0_UDB11_ST_CTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB11_ST_CTL
.set VRP_Timer_TimerUDB_rstSts_stsreg__STATUS_REG, CYREG_B0_UDB11_ST
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB11_12_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB11_12_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB11_12_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB11_12_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB11_12_MSK
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB11_12_MSK
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB11_12_MSK
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB11_12_MSK
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK, 0x80
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS, 7
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG, CYREG_B0_UDB11_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB11_ST_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG, CYREG_B0_UDB11_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB11_ST_CTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK, 0x80
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set VRP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG, CYREG_B0_UDB11_MSK
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG, CYREG_B0_UDB10_11_A0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG, CYREG_B0_UDB10_11_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG, CYREG_B0_UDB10_11_D0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG, CYREG_B0_UDB10_11_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG, CYREG_B0_UDB10_11_F0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG, CYREG_B0_UDB10_11_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__A0_A1_REG, CYREG_B0_UDB10_A0_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__A0_REG, CYREG_B0_UDB10_A0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__A1_REG, CYREG_B0_UDB10_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__D0_D1_REG, CYREG_B0_UDB10_D0_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__D0_REG, CYREG_B0_UDB10_D0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__D1_REG, CYREG_B0_UDB10_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__F0_F1_REG, CYREG_B0_UDB10_F0_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__F0_REG, CYREG_B0_UDB10_F0
.set VRP_Timer_TimerUDB_sT16_timerdp_u0__F1_REG, CYREG_B0_UDB10_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_A0_REG, CYREG_B0_UDB11_12_A0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_A1_REG, CYREG_B0_UDB11_12_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_D0_REG, CYREG_B0_UDB11_12_D0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_D1_REG, CYREG_B0_UDB11_12_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_F0_REG, CYREG_B0_UDB11_12_F0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__16BIT_F1_REG, CYREG_B0_UDB11_12_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__A0_A1_REG, CYREG_B0_UDB11_A0_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__A0_REG, CYREG_B0_UDB11_A0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__A1_REG, CYREG_B0_UDB11_A1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__D0_D1_REG, CYREG_B0_UDB11_D0_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__D0_REG, CYREG_B0_UDB11_D0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__D1_REG, CYREG_B0_UDB11_D1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__F0_F1_REG, CYREG_B0_UDB11_F0_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__F0_REG, CYREG_B0_UDB11_F0
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__F1_REG, CYREG_B0_UDB11_F1
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set VRP_Timer_TimerUDB_sT16_timerdp_u1__PER_DP_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL

/* isr_PVARP */
.set isr_PVARP__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_PVARP__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_PVARP__INTC_MASK, 0x40
.set isr_PVARP__INTC_NUMBER, 6
.set isr_PVARP__INTC_PRIOR_NUM, 7
.set isr_PVARP__INTC_PRIOR_REG, CYREG_NVIC_PRI_6
.set isr_PVARP__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_PVARP__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* PVARP_Timer_TimerUDB */
.set PVARP_Timer_TimerUDB_rstSts_stsreg__0__MASK, 0x01
.set PVARP_Timer_TimerUDB_rstSts_stsreg__0__POS, 0
.set PVARP_Timer_TimerUDB_rstSts_stsreg__2__MASK, 0x04
.set PVARP_Timer_TimerUDB_rstSts_stsreg__2__POS, 2
.set PVARP_Timer_TimerUDB_rstSts_stsreg__3__MASK, 0x08
.set PVARP_Timer_TimerUDB_rstSts_stsreg__3__POS, 3
.set PVARP_Timer_TimerUDB_rstSts_stsreg__MASK, 0x0D
.set PVARP_Timer_TimerUDB_rstSts_stsreg__MASK_REG, CYREG_B0_UDB15_MSK
.set PVARP_Timer_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL
.set PVARP_Timer_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL
.set PVARP_Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB15_ACTL
.set PVARP_Timer_TimerUDB_rstSts_stsreg__STATUS_CNT_REG, CYREG_B0_UDB15_ST_CTL
.set PVARP_Timer_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB15_ST_CTL
.set PVARP_Timer_TimerUDB_rstSts_stsreg__STATUS_REG, CYREG_B0_UDB15_ST
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK, 0x80
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS, 7
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB15_ACTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG, CYREG_B0_UDB15_CTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB15_ST_CTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG, CYREG_B0_UDB15_CTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB15_ST_CTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK, 0x80
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL
.set PVARP_Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG, CYREG_B0_UDB15_MSK
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG, CYREG_B0_UDB14_15_A0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG, CYREG_B0_UDB14_15_A1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG, CYREG_B0_UDB14_15_D0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG, CYREG_B0_UDB14_15_D1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB14_15_ACTL
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG, CYREG_B0_UDB14_15_F0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG, CYREG_B0_UDB14_15_F1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__A0_A1_REG, CYREG_B0_UDB14_A0_A1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__A0_REG, CYREG_B0_UDB14_A0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__A1_REG, CYREG_B0_UDB14_A1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__D0_D1_REG, CYREG_B0_UDB14_D0_D1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__D0_REG, CYREG_B0_UDB14_D0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__D1_REG, CYREG_B0_UDB14_D1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB14_ACTL
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__F0_F1_REG, CYREG_B0_UDB14_F0_F1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__F0_REG, CYREG_B0_UDB14_F0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u0__F1_REG, CYREG_B0_UDB14_F1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__A0_A1_REG, CYREG_B0_UDB15_A0_A1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__A0_REG, CYREG_B0_UDB15_A0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__A1_REG, CYREG_B0_UDB15_A1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__D0_D1_REG, CYREG_B0_UDB15_D0_D1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__D0_REG, CYREG_B0_UDB15_D0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__D1_REG, CYREG_B0_UDB15_D1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB15_ACTL
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__F0_F1_REG, CYREG_B0_UDB15_F0_F1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__F0_REG, CYREG_B0_UDB15_F0
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__F1_REG, CYREG_B0_UDB15_F1
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL
.set PVARP_Timer_TimerUDB_sT16_timerdp_u1__PER_DP_AUX_CTL_REG, CYREG_B0_UDB15_MSK_ACTL

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 19
.set CYDEV_CHIP_DIE_PSOC4A, 11
.set CYDEV_CHIP_DIE_PSOC5LP, 18
.set CYDEV_CHIP_DIE_TMA4, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 11
.set CYDEV_CHIP_MEMBER_4C, 16
.set CYDEV_CHIP_MEMBER_4D, 7
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 12
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4H, 10
.set CYDEV_CHIP_MEMBER_4I, 15
.set CYDEV_CHIP_MEMBER_4J, 8
.set CYDEV_CHIP_MEMBER_4K, 9
.set CYDEV_CHIP_MEMBER_4L, 14
.set CYDEV_CHIP_MEMBER_4M, 13
.set CYDEV_CHIP_MEMBER_4N, 6
.set CYDEV_CHIP_MEMBER_4O, 5
.set CYDEV_CHIP_MEMBER_4U, 3
.set CYDEV_CHIP_MEMBER_5A, 18
.set CYDEV_CHIP_MEMBER_5B, 17
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x000001D8
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP, 1
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
