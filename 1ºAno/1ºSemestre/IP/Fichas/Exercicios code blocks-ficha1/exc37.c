#include <stdio.h>
void main()
{

int num,op=0,resultado=0;

printf("Numero: ");
scanf("%d",&num);


while(num!=1)
{
 num=num%2;
    if(num=0)
    {
        resultado=num/2;
        printf("Resultado: %.2d\n",resultado);
        op++;
    }
    else
    {
        resultado=num*3+1;
        printf("Resultado: %.2f\n",resultado);
        op++;
    }
printf("Numero: ");
scanf("%d",&num);

}

printf("Total de operacoes: %.2d\n",op);















}
