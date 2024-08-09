function a = gerarPAritmetica_v02(a_1,r,n)
%GERARPARITMENTICA_v02 Gerar uma Progressão Aritmética
%   a = gerarPAritmetica_v01(a_1,r,n)
%   a(i) = a(1)+(i-1)*r
%
%INPUT:
%   a_1 - primeiro elemento da progressão aritmética
%   r - razão da progressão aritmética
%   n - número de elementos da progressão aritmética 
%OUTPUT: 
%   a - vetor com os elementos da progressão aritmética
%
%   29/03/2023 - Martim Antunes  a2022141890@isec.pt
a=zeros(1,n);
a(1)=a_1; % a= a_1
i=2;
while i<=n
    a(i) = a(1)+(i-1)*r;
    i=i+1;
end
end