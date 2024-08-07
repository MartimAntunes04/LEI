import numpy as np
R3=5000
R4=2000
RTH=40000
VTH=4.2
VBE=0.66
B=172
V1=21
A=np.array([[B,-1,0,0],
            [1,1,-1,0],
            [0,R3,R4,1],
            [-RTH,0,-R4,0]])
B=np.array([0,0,V1,-VTH+VBE])
solucao=np.linalg.solve(A,B)
IC=solucao[1]
VCE=solucao[3]
print("IC= (mA)",solucao[1]*1000)
print("VCE= (v)",solucao[3])
