function p = minhaHorner(a,x)
%implementa o metodo de Horner para reduzir o nº de multiplicações no
%calculo da imagem por um polinomio
%inputs:
%a-vetor dos coeficientes a=[an a(n-1) a(n-2) ... a0]
%x- valor/vetor dos objetos
%output:
%p.valor/vetor das imagens pelo pol
%autor, data,email

p=a(1);%inicializao
n=length(a);
for i=2:n
    p=p.*x+a(i);
end
