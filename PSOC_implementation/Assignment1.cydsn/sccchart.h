/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef SCCCHARTS_H_
#define SCCCHARTS_H_
void reset();
void tick();

extern char VSense,ASense;
extern char VPace,APace;
extern char LRIExpired,URIExpired,PVARPExpired,AEIExpired,VRPExpired,AVIExpired;
extern char LRIStart,URIStart,PVARPStart,AEIStart,VRPStart,AVIStart;
extern char AVIStop,AEIStop,LRIReset;

#endif

/* [] END OF FILE */
