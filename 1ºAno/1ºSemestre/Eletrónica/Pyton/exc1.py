import numpy as np
R1=4000
R2=6000
R3=10000
R4=10000
I1=5/1000
V1=5
IC=I1
A=np.array([[R1+R2+R3,-R3],
            [-R3,R3+R4]])
B=np.array([R2*IC,R4*IC-V1])
solucao=np.linalg.solve(A,B)
IA=solucao[0]
IB=solucao[1]
print("IA= (mA)",solucao[0]*1000)
print("IB= (mA)",solucao[1]*1000)
