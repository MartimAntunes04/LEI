import numpy as np
R1=1000;
R3=1000;
R4=1000;
V1=1;
V2=1;
IA=1/1000
A=np.array([[R1+R3],
            [-R3,R4]])
B=np.array([-V1,-V2])
solucao=np.linalg.solve(A,B)
IA=solucao[0]
IB=solucao[1]


print("IB= (mA)",IB*1000)
      
