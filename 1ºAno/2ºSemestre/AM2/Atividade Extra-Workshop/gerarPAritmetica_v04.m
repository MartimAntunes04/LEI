function a = gerarPAritmetica_v02(a_1,r,n)
%GERARPARITMENTICA_v03 Gerar uma Progressão Aritmética
%   a = gerarPAritmetica_v03(a_1,r,n)
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
a = a_1:r:a_1+(n-1)*r
end