import numpy as np
from math import pi
from matplotlib import pyplot as grafico
Rd=100;R=200;Va=0.7;V1=1
Amplitude=5
frequencia=50
Periodo=frequencia**-1
PA=Periodo/1000
t=np.arange(0,Periodo,PA)
vin=Amplitude*np.sin(2*pi*frequencia*t)

vout=vin.copy()
i=0
while (i<len(vin)):
        if (vin[i]<Va+V1):
                vout[i]=vin[i]
        else:
                vout[i]=Rd/(R+Rd)*(vin[i]-Va-V1)+Va+V1
        i+=1        



grafico.plot(t,vin,'b',t,vout,'r')
grafico.grid()
grafico.show()
