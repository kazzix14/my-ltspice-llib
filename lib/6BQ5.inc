*
* Generic pentode model: 6BQ5
* Copyright 2003--2006 by Ayumi Nakabayashi, All rights reserved.
* Version 3.01, Generated on Wed Mar 22 17:19:44 2006
.SUBCKT 6BQ5 A G2 G1 K
BGG   GG   0 V=V(G1,K)+0.03372597
BEP   EP   0 V=URAMP(V(A,K))+1e-10
BEG   EG   0 V=URAMP(V(G1,K))+1e-10
BEG2  EG2  0 V=URAMP(V(G2,K))+1e-10
BM1   M1   0 V=(0.014266539*(URAMP(V(EG2)-1e-10)+1e-10))**-0.43210132
BM2   M2   0 V=(0.7763568*(URAMP(V(GG)+V(EG2)/15.676066)+1e-10))**1.9321013
BP    P    0 V=0.0040800354*(URAMP(V(GG)+V(EG2)/20.191832)+1e-10)**1.5
BIK   IK   0 V=U(V(GG))*V(P)+(1-U(V(GG)))*0.0023829269*V(M1)*V(M2)
BIG   IG   0 V=0.0020400177*V(EG)**1.5*(V(EG)/(V(EP)+V(EG))*1.2+0.4)
BIK2  IK2  0 V=V(IK,IG)*(1-0.4*(EXP(-V(EP)/V(EG2)*15)-EXP(-15)))
BIG2T IG2T 0 V=V(IK2)*(0.904015183*(1-V(EP)/(V(EP)+10))**1.5+0.095984817)
BIK3  IK3  0 V=V(IK2)*(V(EP)+2486)/(V(EG2)+2486)
BIK4  IK4  0 V=V(IK3)-URAMP(V(IK3)-(0.0023468355*(V(EP)+URAMP(V(EG2,EP)))**1.5))
BIP   IP   0 V=URAMP(V(IK4,IG2T)-URAMP(V(IK4,IG2T)-(0.0023468355*V(EP)**1.5)))
BIAK  A    K I=V(IP)+1e-10*V(A,K)
BIG2  G2   K I=URAMP(V(IK4,IP))
BIGK  G1   K I=V(IG)
* CAPS
CGA   G1  A  0.5p
CGK   G1  K  6.2p
C12   G1  G2 4.1p
CAK   A   K  6p
.ENDS
