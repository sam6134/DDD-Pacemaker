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
/*****************************************************************************/
/*                 G E N E R A T E D       C    C O D E                      */
/*****************************************************************************/
/* KIELER - Kiel Integrated Environment for Layout Eclipse RichClient        */
/*                                                                           */
/* http://www.informatik.uni-kiel.de/rtsys/kieler/                           */
/* Copyright 2014 by                                                         */
/* + Kiel University                                                         */
/*   + Department of Computer Science                                        */
/*     + Real-Time and Embedded Systems Group                                */
/*                                                                           */
/* This code is provided under the terms of the Eclipse Public License (EPL).*/
/*****************************************************************************/
/*****************************************************************************/
/*                 G E N E R A T E D       C    C O D E                      */
/*****************************************************************************/
/* KIELER - Kiel Integrated Environment for Layout Eclipse RichClient        */
/*                                                                           */
/* http://www.informatik.uni-kiel.de/rtsys/kieler/                           */
/* Copyright 2014 by                                                         */
/* + Kiel University                                                         */
/*   + Department of Computer Science                                        */
/*     + Real-Time and Embedded Systems Group                                */
/*                                                                           */
/* This code is provided under the terms of the Eclipse Public License (EPL).*/
/*****************************************************************************/
char VSense;
char LRIStart;
char LRIExpired;
char VP1;
char LRIReset;
char VPace;
char ASense;
char AEIStart;
char AVIStart;
char PVARPStart;
char VRPStart;
char URIStart;
char AEIExpired;
char AVIExpired;
char PVARPExpired;
char VRPExpired;
char URIExpired;
char VS;
char AS;
char AVIStop;
char AEIStop;
char APace;
char VPace1;
char g0;
char g1;
char g2;
char g3;
char g4;
char g5;
char PRE_g5;
char g6;
char g6b;
char g7;
char g8;
char g9;
char g10;
char g11;
char g12;
char g13;
char PRE_g13;
char g14;
char g15;
char g16;
char g17;
char g18;
char g19;
char PRE_g19;
char g20;
char g21;
char g22;
char PRE_g22;
char g23;
char g24;
char g25;
char g26;
char g27;
char g28;
char g29;
char PRE_g29;
char g30;
char g31;
char g32;
char g33;
char PRE_g33;
char g34;
char g35;
char g36;
char g37;
char g38;
char g39;
char PRE_g39;
char g40;
char g40b;
char g41;
char g42;
char g43;
char g44;
char g45;
char PRE_g45;
char g46;
char g47;
char g48;
char g49;
char g50;
char g51;
char PRE_g51;
char g52;
char g52b;
char g53;
char g54;
char g55;
char g56;
char g57;
char PRE_g57;
char g58;
char g58b;
char g59;
char g60;
char PRE_g60;
char g61;
char g62;
char g63;
char g64;
char g65;
char g66;
char PRE_g66;
char g67;
char g68;
char g69;
char PRE_g69;
char g70;
char g71;
char g72;
char g73;
char PRE_g73;
char g74;
char g74b;
char g75;
char g76;
char g77;
char PRE_g77;
char g78;
char g78b;
char g79;
char g80;
char g81;
char g82;
char PRE_g82;
char g83;
char g84;
char g85;
char _GO;
char _cg3;
char _cg12;
char _cg10;
char _cg6;
char _cg8;
char _cg20;
char _cg23;
char _cg17;
char _cg21;
char _cg30;
char _cg27;
char _cg31;
char _cg37;
char _cg44;
char _cg42;
char _cg40;
char _cg49;
char _cg59;
char _cg56;
char _cg52;
char _cg54;
char _cg67;
char _cg64;
char _cg72;
char _cg74;
char _cg75;
char _cg68;
char _cg70;
char _cg76;
char g15_e1;
char g25_e2;
char g35_e3;
char g47_e4;
char g62_e5;
char g79_e6;
char g80_e1;
char g84_e2;
int _PRE_GO;
void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g5 = 0;
   PRE_g13 = 0;
   PRE_g19 = 0;
   PRE_g22 = 0;
   PRE_g29 = 0;
   PRE_g33 = 0;
   PRE_g39 = 0;
   PRE_g45 = 0;
   PRE_g51 = 0;
   PRE_g57 = 0;
   PRE_g60 = 0;
   PRE_g66 = 0;
   PRE_g69 = 0;
   PRE_g73 = 0;
   PRE_g77 = 0;
   PRE_g82 = 0;
   return;
}
void tick(){
   if(_PRE_GO == 1){
      _GO = 0;
   }
   {
      g0 = _GO;
      g1 = g0;
      g2 = g1;
      g81 = g0;
      g83 =(PRE_g82);
      g82 =(g81||g83);
      if(g82){
         AEIStart = 0;
         AVIStart = 0;
         PVARPStart = 0;
         VRPStart = 0;
         URIStart = 0;
         LRIStart = 0;
         VS = 0;
         AS = 0;
         VP1 = 0;
         AVIStop = 0;
         AEIStop = 0;
         LRIReset = 0;
         APace = 0;
         VPace1 = 0;
         VPace = 0;
      }
      g23 =(PRE_g22);
      _cg23 = ASense;
      g24 =(g23&&_cg23);
      if(g24){
         AS =(AS||1);
      }
      g58 =(PRE_g57);
      g58b = g58;
      if(g58b){
         VPace =(VPace||1);
      }
      g78 =(PRE_g77);
      g78b = g78;
      if(g78b){
         VPace =(VPace||1);
      }
      g70 =(PRE_g69);
      _cg70 = URIExpired;
      g71 =(g70&&_cg70);
      if(g71){
         VPace =(VPace||1);
      }
      g26 = g1;
      g30 =(PRE_g29);
      _cg30 = VRPExpired;
      g34 =(PRE_g33);
      g27 =(g26||(g30&&_cg30)||g34);
      _cg27 = VPace;
      g31 =(g27&&(!(_cg27)));
      _cg31 = VSense;
      g32 =(g31&&_cg31);
      if(g32){
         VS =(VS||1);
      }
      g6 =(PRE_g5);
      g6b = g6;
      _cg6 = VS;
      g8 =(g6b&&(!(_cg6)));
      _cg8 = VPace;
      g10 =(g8&&(!(_cg8)));
      _cg10 = AVIExpired;
      g11 =(g10&&_cg10);
      if(g11){
         VP1 =(VP1||1);
      }
      g7 =(g6b&&_cg6);
      if(g7){
         AVIStop =(AVIStop||1);
      }
      g9 =(g8&&_cg8);
      if(g9){
         AVIStop =(AVIStop||1);
      }
      g14 =(PRE_g13);
      g3 =(g2||g11||g7||g9||g14);
      _cg3 = AS;
      g40 =(PRE_g39);
      g40b = g40;
      _cg40 = AS;
      g42 =(g40b&&(!(_cg40)));
      _cg42 = AEIExpired;
      g43 =(g42&&_cg42);
      if(g43){
         APace =(APace||1);
      }
      g12 =(g3&&(!(_cg3)));
      _cg12 = APace;
      g4 =((g3&&_cg3)||(g12&&_cg12));
      if(g4){
         AVIStart =(AVIStart||1);
      }
      g5 =(g4||(g10&&(!(_cg10))));
      g13 =(g12&&(!(_cg12)));
      g16 = g1;
      g20 =(PRE_g19);
      _cg20 = PVARPExpired;
      g17 =(g24||(g23&&(!(_cg23)))||g16||(g20&&_cg20));
      _cg17 = VPace;
      g21 =(g17&&(!(_cg17)));
      _cg21 = VS;
      g18 =((g17&&_cg17)||(g21&&_cg21));
      if(g18){
         PVARPStart =(PVARPStart||1);
      }
      g19 =(g18||(g20&&(!(_cg20))));
      g22 =(g21&&(!(_cg21)));
      g28 =(g32||(g27&&_cg27));
      if(g28){
         VRPStart =(VRPStart||1);
      }
      g29 =(g28||(g30&&(!(_cg30))));
      g33 =(g31&&(!(_cg31)));
      g36 = g1;
      g41 =(g40b&&_cg40);
      if(g41){
         AEIStop =(AEIStop||1);
      }
      g46 =(PRE_g45);
      g37 =(g36||g41||g43||g46);
      _cg37 = VS;
      g44 =(g37&&(!(_cg37)));
      _cg44 = VPace;
      g38 =((g37&&_cg37)||(g44&&_cg44));
      if(g38){
         AEIStart =(AEIStart||1);
      }
      g39 =(g38||(g42&&(!(_cg42))));
      g45 =(g44&&(!(_cg44)));
      g48 = g1;
      g61 =(PRE_g60);
      g49 =(g48||g61);
      _cg49 = VS;
      g59 =(g49&&(!(_cg49)));
      _cg59 = VPace;
      g50 =((g59&&_cg59)||(g49&&_cg49));
      if(g50){
         LRIStart =(LRIStart||1);
      }
      g52 =(PRE_g51);
      g52b = g52;
      _cg52 = VPace;
      g54 =(g52b&&(!(_cg52)));
      _cg54 = VS;
      g55 =(g54&&_cg54);
      if(g55){
         LRIReset =(LRIReset||1);
      }
      g53 =(g52b&&_cg52);
      if(g53){
         LRIReset =(LRIReset||1);
      }
      g56 =(g54&&(!(_cg54)));
      _cg56 = LRIExpired;
      g51 =(g50||g55||g53||g58b||(g56&&(!(_cg56))));
      g57 =(g56&&_cg56);
      if(g57){
         LRIReset =(LRIReset||1);
      }
      g60 =(g59&&(!(_cg59)));
      g63 = g1;
      g67 =(PRE_g66);
      _cg67 = URIExpired;
      g64 =(g63||g71||(g67&&_cg67));
      _cg64 = VS;
      g72 =(g64&&(!(_cg64)));
      _cg72 = VPace;
      g74 =(PRE_g73);
      g74b = g74;
      _cg74 = VS;
      g75 =(g74b&&(!(_cg74)));
      _cg75 = VPace;
      g65 =((g72&&_cg72)||g78b||(g64&&_cg64)||(g75&&_cg75)||(g74b&&_cg74));
      if(g65){
         URIStart =(URIStart||1);
      }
      g68 =(g67&&(!(_cg67)));
      _cg68 = VP1;
      g66 =((g68&&(!(_cg68)))||g65);
      g69 =((g70&&(!(_cg70)))||(g68&&_cg68));
      g76 =(g75&&(!(_cg75)));
      _cg76 = VP1;
      g73 =((g72&&(!(_cg72)))||(g76&&(!(_cg76))));
      g77 =(g76&&_cg76);
      g15_e1 =(!((g6||g14)));
      g25_e2 =(!((g20||g23)));
      g35_e3 =(!((g30||g34)));
      g47_e4 =(!((g40||g46)));
      g62_e5 =(!((g52||g61||g58)));
      g79_e6 =(!((g67||g74||g70||g78)));
      g80_e1 =(!((g6||g14||g20||g23||g30||g34||g40||g46||g52||g61||g67||g74||g70||g78||g58)));
      g84_e2 =(!(g83));
   }
   PRE_g5 = g5;
   PRE_g13 = g13;
   PRE_g19 = g19;
   PRE_g22 = g22;
   PRE_g29 = g29;
   PRE_g33 = g33;
   PRE_g39 = g39;
   PRE_g45 = g45;
   PRE_g51 = g51;
   PRE_g57 = g57;
   PRE_g60 = g60;
   PRE_g66 = g66;
   PRE_g69 = g69;
   PRE_g73 = g73;
   PRE_g77 = g77;
   PRE_g82 = g82;
   _PRE_GO = _GO;
   return;
}


/* [] END OF FILE */
