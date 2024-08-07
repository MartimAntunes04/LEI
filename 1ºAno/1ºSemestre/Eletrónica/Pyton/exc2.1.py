import numpy as np
V1=1
R1=1000
R2=2000
R3=2000
A=np.array([[1,-1,-1],
            [R1,R2,0],
            [0,-R2,R3]])
B=np.array([0,V1,0])
solucao=np.linalg.solve(A,B)
I1=solucao[0]
I2=solucao[1]
I3=solucao[2]
print("I1= (mA)",solucao[0]*1000)
print("I2= (mA)",solucao[1]*1000)
print("I3= (mA)",solucao[2]*1000)
