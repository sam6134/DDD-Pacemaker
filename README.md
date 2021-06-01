# DDD-Pacemaker
## Design Logic and Road-Map
The pacemaker design starts with the implementation of 5 timers interacting with each other thus we here tried implementing the design as a system 5 timers i.e AVI Timer, AEI Timer, PVARP Timer, VRP timer, URI Timer, and LRI Timer. We started first implementing the design as a rough blueprint which helped us to found some logics to get correct signals to start the timers AEI, AVI, PVARP, URI, and LRI which restarted on getting a valid V Pulse here a valid V Pulse is a pulse which does not occur again after VRP_Expire seconds after a V_Pulse.(WhereVRP_ExpireisthedurationofVRPTimer)
To counter this we introduced a new signal in our design- VS, which communicates with other timers to denote an onset of a valid pulse. This can be shown in the following figure- <br />
<img src="" width="300" alt="Screenshot"/>
A similar technique was thus then used to generate a dummy signal AS to denote the onset of a valid A_Pulse. A valid A-Pulse is a pulse generated after PVARP_Exp seconds after the onset of a valid V-Pulse thus we emitted the dummy signal AS when the PVARP Timer state is not in a waiting state ( or is still ticking ). Implementation can be understood using the following SCC. <br />
<img src="" width="300" alt="Screenshot"/>

Taking care to check the validity of pulses we can start the corresponding timers on the being triggered by the VS and AS Pulses, generating their corresponding start signals. This will led all timers to wait until a corresponding Expired Signal is not received. <br />

## Addition of Pacing Logic
Now we try to inculcate the pacing logic into our SCC, the V-Pacing occurs in two cases - <br />
1) AVI Timer expires after an A-Pulse and no V-Pulse is observed.<br />
2) LRI Timer expires after a V-Pulse and another V-Pulse is yet not observed.<br />
We address this issue by outputting a V-Pace when the corresponding timers expire, the inclusion of a minimum URI time between the pacing which we need to address. Thus directly pacing on AVI-Timer expiration will not work. To tackle this issue we introduce an intermediate state, extension state and an intermediate signal VP1 in the URI timer SCC. This state transition is activated on receiving a VP1 signal and stays in the state until the URI timer expires, thus outputting the ​V-Pace signal. The following diagram can show a better picture of the representation. <br />
<img src="" width="300" alt="Screenshot"/>

## Implementation on PSOC
The code function was finally added to the psoc workspace along with a header files to communicate our psoc with the tick, reset functions and the Input and Output Variables. <br />
We encountered a problem with the limit of the available number of fixed timers in the PSOC . This was later solved by using the UDP implementation of timers provided by the PSOC. Each timer was set to have a period of 1ms, with interrupts on TC so that we can update each of the counter variables to match their corresponding timings. <br />
The USBUART read and write functions were implemented to communicate with the heart emulator to read ‘A’ ,V’ as the corresponding pulses and to pace the heart with the same symbols when necessary. The other functions implemented were the corresponding timer functions to communicate the timer with the SCC chart logic. The function allowed to start the timer, enable their interputs on receiving a start signal. Also, stop and reset the timer on receiving an expiration signal. <br />
All these functions were encapsulated in a pacemaker function starting with USB read, timers and finally USB write to achieve correct pacing logic of our pacemaker.
