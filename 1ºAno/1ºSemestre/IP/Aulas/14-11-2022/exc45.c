#include <stdio.h>
int CalculaNumDivisores(int numero)
{
    int i,divisores=0;
    for (i=1; i<=numero;i++);

        if (numero%i==0)
            divisores++;
    return (divisores);
}

void main()
{
int num,divisores;

printf("Introduza um numero: ");
scanf("%d",&num);
divisores=CalculaNumDivisores(num);
if (divisores>2)
{
    printf("Nao é primo");
}
else
{
    printf("Primo");
}










}

