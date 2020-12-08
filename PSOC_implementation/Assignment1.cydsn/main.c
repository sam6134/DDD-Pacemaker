/* ========================================
 *
 * Copyright SAMARTH SINGH (Author), IIT Jammu
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Samarth Singh.
 *
 * ========================================
*/
#include <project.h>
#include "sccchart.h"
#include <stdio.h>

//defining values for timeouts as per the report ( change these values for testing )
#define AVI_VALUE 300
#define AEI_VALUE 900
#define PVARP_VALUE 50
#define VRP_VALUE 150
#define LRI_VALUE 1100
#define URI_VALUE 600


//initialization of TimeOut variables
static volatile unsigned int AVI_TO= 0;
static volatile unsigned int AEI_TO= 0;
static volatile unsigned int PVARP_TO= 0;
static volatile unsigned int VRP_TO= 0;
static volatile unsigned int LRI_TO= 0;
static volatile unsigned int URI_TO= 0;

// Predefining functions for the PSOC to communicate with SCC 
// Read function to read 'A' and 'V' signals
void Uart_Read();
// Write function to write 'A' and 'V' corresponding to pacing
void Uart_Write();

// Defined functions for the SCC to communicate with different timers
void AVI();
void AEI();
void PVARP();
void VRP();
void LRI();
void URI();
// final pacemaker functions
void pacemaker();
// -------------------------------------------------------------
/* Interupt for AVI timer, update the count and if count reaches expiration time
   reset the timer and set AVI Timeout signal.   */ 
int countAVI = 0;
CY_ISR(myAVI_Timer)
{
  countAVI++;
  if(countAVI == AVI_VALUE)  { AVI_TO=1; countAVI = 0; }
}
// -------------------------------------------------------------
/* Interupt for AEI timer, update the count and if count reaches expiration time
   reset the timer and set AEI Timeout signal.   */ 
int countAEI = 0;
CY_ISR(myAEI_Timer)
{
  countAEI++;
  if(countAEI == AEI_VALUE) { AEI_TO=1; countAEI = 0; }
}
// -------------------------------------------------------------
/* Interupt for PVARP timer, update the count and if count reaches expiration time
   reset the timer and set PVARP Timeout signal.   */ 
int countPVARP = 0;
CY_ISR(myPVARP_Timer)
{
  countPVARP++;
  if(countPVARP == PVARP_VALUE)  { PVARP_TO=1; countPVARP = 0; }
}
// -------------------------------------------------------------
/* Interupt for VRP timer, update the count and if count reaches expiration time
   reset the timer and set VRP Timeout signal.   */ 
int countVRP = 0;
CY_ISR(myVRP_Timer)
{
  countVRP++;
  if(countVRP == VRP_VALUE)  { VRP_TO=1; countVRP = 0; }
}
// -------------------------------------------------------------
/* Interupt for LRI timer, update the count and if count reaches expiration time
   reset the timer and set LRI Timeout signal.   */ 
int countLRI = 0;
CY_ISR(myLRI_Timer)
{
  countLRI++;
  if(countLRI == LRI_VALUE)  { LRI_TO=1; countLRI = 0; }
}
// -------------------------------------------------------------
/* Interupt for LRI timer, update the count and if count reaches expiration time
   reset the timer and set LRI Timeout signal.   */ 
int countURI = 0;
CY_ISR(myURI_Timer)
{
  countURI++;
  if(countURI == URI_VALUE) { URI_TO=1; countURI = 0; }
}
// -------------------------------------------------------------
// MAIN FUNCTION
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    // Start the USBUART operation
    USBUART_Start(0,USBUART_5V_OPERATION);
    // while not configured keep the code in wait state.
    while(USBUART_GetConfiguration() == 0)
    {
    }
    // Initialization of the USBUART
    USBUART_CDC_Init();
    // reset signal called from the sccchart file to reset the scc to init states.
    reset();

    for(;;)
    {
        /* The application code. */
        pacemaker();
    }
}

// The UART read function
void Uart_Read()
{
    uint8 str; // declare an unsigned 8 bit variable for the char
    if(USBUART_DataIsReady() > 0) // if data is ready
    {
        str = USBUART_GetChar(); // get the character inputted using usb get char function

        // Cases corresponding to the onset of VPulse or APulse
        // if input signal is V
        if(str == 'V')
        {
            VSense = 1;
        }else{
            VSense = 0;
        }
        // if inputted signal is A
         if(str == 'A')
        {
            ASense = 1;
        }else{
            ASense = 0;
        }
        
            
    }
}
// UART write function
void Uart_Write()
{
    // wait until USBUART is ready
    while(USBUART_CDCIsReady() == 0){};
    // if VPace signal is set
    if(VPace)
    {
        // Output V in USB stream
        USBUART_PutChar('V');
    }else{}
    // if APace signal is set
    if(APace)
    {
        // Output A in USB stream
        USBUART_PutChar('A');
    }else{}
}
// AVI Timer Function
void AVI()
{
    // if Start signal is set
    if(AVIStart)
    {
        // reset the count value
        countAVI=0;
        // start the timer
        AVI_Timer_Start();
        // enable the interupt
        isr_AVI_StartEx(myAVI_Timer);
    }
    // if stop signal is set
    if(AVIStop)
    {
        // stop the timer
        AVI_Timer_Stop();
        // reset the count
        countAVI = 0;
        // disable the interupt
        isr_AVI_Disable();
    }
    // if timeout occurs
    if(AVI_TO)
    {
        // set the expired signal
        AVIExpired = 1;
        // reset the timeout
        AVI_TO = 0;
        // disable the interupts
        isr_AVI_Disable();
        // stop the timer
        AVI_Timer_Stop();
    }else
    {
        // reset the expired signal in all other cases
        AVIExpired = 0;
    }
}
// AEI Timer function
void AEI()
{
    // if start signal is set
    if(AEIStart)
    {
        // reset count value
        countAEI=0;
        // start AEI timer
        AEI_Timer_Start();
        // enable interupt
        isr_AEI_StartEx(myAEI_Timer);
    }
    // if stop signal is set
    else if(AEIStop)
    {
        // stop the AEI timer
        AEI_Timer_Stop();
        // reset the count
        countAEI = 0;
        // disable the ISR
        isr_AEI_Disable();
    }
    // if timeout signal is set
    if(AEI_TO)
    {
        // set the expired signal
        AEIExpired = 1;
        // reset timeout variable
        AEI_TO = 0;
        // disable the ISR
        isr_AEI_Disable();
        // stop the AEI timer
        AEI_Timer_Stop();
    }else
    {
        // else in all other cases reset the expired signal
        AEIExpired = 0;
    }
}
// PVARP signal
void PVARP()
{
    // if PVARP start signal is set
    if(PVARPStart)
    {
        // reset the count value
        countPVARP=0;
        // start the PVARP timer
        PVARP_Timer_Start();
        // enable isr interupts
        isr_PVARP_StartEx(myPVARP_Timer);
    }
    // if timeout signal is set
    if(PVARP_TO)
    {
        // set the Expired
        PVARPExpired = 1;
        // reset the timeout signal
        PVARP_TO = 0;
        // disable the interupt
        isr_PVARP_Disable();
        // stop the timer
        PVARP_Timer_Stop();
    }else
    {
        // else in all other cases reset the expired signal
        PVARPExpired = 0;
    }
}
// VRP timer signal
void VRP()
{
    // if start signal is set
    if(VRPStart)
    {
        // reset the count value
        countVRP=0;
        // start the vrp timer
        VRP_Timer_Start();
        // enable the interupt
        isr_VRP_StartEx(myVRP_Timer);
    }
    // if timeout signal is set
    if(VRP_TO)
    {
        // set expired signal 
        VRPExpired = 1;
        // reset the timeout variable
        VRP_TO = 0;
        // disable the timer
        isr_VRP_Disable();
        // stop the timer
        VRP_Timer_Stop();
    }else
    {
        // else in all other cases set the expired signal
        VRPExpired = 0;
    }
}
// the LRI timer function
void LRI()
{
     // if the start signal is set   
    if(LRIStart)
    {
        // reset the count value
        countLRI=0;
        // start the LRI timer
        LRI_Timer_Start();
        // enable the isr interupts
        isr_LRI_StartEx(myLRI_Timer);
    }
    // if reset signal is set
    else if(LRIReset){
        // stop the timer
        LRI_Timer_Stop();
        // reset the count value
        countLRI = 0;
        // again start the timer
        LRI_Timer_Start();
    }
    // if timeout signal is set
     if(LRI_TO)
    {
        // set the expired signal
       LRIExpired = 1;
       // reset the timeout signal
       LRI_TO = 0;
       // reset the count value
       countLRI = 0;
       // start the LRI timer
       LRI_Timer_Start();
    }else
    {
        // in all the other cases reset the expired signal
       LRIExpired = 0;
    }
}
// the URI timer function
void URI()
{
    // if the start signal is set
    if(URIStart)
    {
       // reset the count value
        countURI=0;
        // start the URI timer
        URI_Timer_Start();
        // enable the isr interupts
        isr_URI_StartEx(myURI_Timer);
    }
    // if timeout signal is set
    if(URI_TO)
    {
        // set the expired signal
        URIExpired = 1;
        // reset the timeout signal
        URI_TO = 0;
        // disable the isr interupt
        isr_URI_Disable();
        // stop the URI timer
        URI_Timer_Stop();
    }else
    {
       // reset the Expired signal in all other cases
       URIExpired = 0;
    }
}
// the pacemaker function ( main function )
void pacemaker()
{
    // Reseting the sense signals
    VSense = 0;
    ASense = 0;
    // Call read functions
    Uart_Read();
    // One by one call timers
    AVI();
    AEI();
    PVARP();
    VRP();
    LRI();
    URI();
    // call tick functions
    tick();
    // call write function
    Uart_Write();
}
/* [] END OF FILE */
