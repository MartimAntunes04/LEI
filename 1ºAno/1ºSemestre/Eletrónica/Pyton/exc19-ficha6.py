import numpy as np
R1=200000
R2=50000
R3=5000
R4=2000
V1=21
B=172
VBE=0.66
A=np.array([[0,1,0,0,-1,0],
            [-1,B,0,0,0,0],
            [1,1,-1,0,0,0],
            [R3,0,R4,1,0,0],
            [0,0,-R4,0,0,R2],
            [0,0,0,0,R1,R2]])
B=np.array([0,0,0,V1,VBE,V1])
solucao=np.linalg.solve(A,B)
IC=solucao[0]
VCE=solucao[3]

print("IC= (mA)",solucao[0])
print("VCE= (V)",solucao[3])
