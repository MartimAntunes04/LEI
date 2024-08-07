import numpy as np
from  matplotlib import pyplot as plt
from math import pi

f1=50   #20ms
f2=50   #20ms
P=1/f1
PA=P/1000
t=np.arange(0,2*P,PA)
v1=2*np.sin(2*pi*f1*t)
v2=4*np.sin(2*pi*f2*t+pi)

vout=-v1-v2

plt.plot(t,v1,'g',t,v2,'k',t,vout,'r')
plt.axis([0,2*P,-15,15])
plt.grid()
plt.show()
