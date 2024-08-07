import numpy as np
R1=1000
R2=2000
R3=4000
V1=5
A=np.array([[R1+R3,-R3],
            [-R3,R2+R3]])
B=np.array([-V1,V1]
solucao=np.linalg.solve(A,B)
IB=solucao[1]
print("IB= (mA)",sol[1])
