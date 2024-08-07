import numpy as np
R1=1000
R2=1000
R3=1000
R4=1000
V1=4

A=np.array([[R1+R2,-R2],
            [-R2,R2+R3+R4]])
B=np.array([V1,0])
solucao=np.linalg.solve(A,B)
IA=solucao[0]
IB=solucao[1]
print("IA= (mA)",solucao[0]*1000)
print("IB= (mA)",solucao[1]*1000)
