import numpy as np
R1=4000;R2=6000;R3=10000;R4=10000;I1=5/1000;V1=5;IA=I1

A=np.array([R2-R3,R2+R3]),
            

B=np.array([-R1-R2-R3,R1+R3,-V1])
solucao=np.linalg.solve(A,B)
IB=solucao[0]



print("IB (mA)= ",IB*1000)
