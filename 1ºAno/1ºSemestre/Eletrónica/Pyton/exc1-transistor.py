import numpy as np
RTH=1428.57
VTH=1.42857
R8=100
R9=400
V4=5
B=173
VBE=0.7


A=np.array([[1,1,-1,0],
            [B,-1,0,0],
            [0,R9,R8,1]
            [-RTH,0,R8,0]])
B=np.array([0,0,V4,VBE-VTH])

solucao=np.linalg.solve(A,B)
IB=solucao[0]
IC=solucao[1]
IE=solucao[2]
VCE=solucao[3]

print("IB= (mA)",solucao[0])
print("IC= (mA)",solucao[1])     
print("IE= (mA)",solucao[2])
print("VCE= (V)",solucao[3])
