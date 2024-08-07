import numpy as np
from math import pi
from matplotlib import pyplot as grafico
Req=400
Rd=100
Vd=0.7
V2=1
V3=4
freq=50
Amplitude=15
periodo=freq**-1
PA=periodo/1000
tempo=np.arange(0,periodo,PA)
vin=Amplitude*np.sin(2*pi*freq*tempo)
vout=vin.copy()
i=0
while (i<len(vin)):
    if(vin[i]>-V3-V2-Vd):
        vout=(-Rd/Rd-Req)*(vin+V2+Vd+V3)-Vd-V2
    else:
        vout=vin+v3
i+=1
grafico.plot(t,vin,t,vout)
grafico.grid()
grafico.show()
