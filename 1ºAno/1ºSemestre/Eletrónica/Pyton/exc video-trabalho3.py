import numpy as np
from matplotlib import pyplot as plt
from math import pi

f4=50  #20ms
f5=150 #6.(6)ms
f6=250 #4ms

P=1/f4
PA=P/5000
t=np.arange(0,2*P,PA)
v4=4*np.sin(2*pi*f4*t+pi)
v5=0.45*np.sin(2*pi*f5*t+pi)
v6=0.16*np.sin(2*pi*f6*t)

vout=-v4-v5+4*v6+1

plt.plot(t,v4,'g',t,v5,'k',t,v6,'b',t,vout,'r')
plt.axis([0,2*P,-5,6])
plt.grid()
plt.show()
