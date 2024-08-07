#include <stdio.h>
void main()
{

float nota1,nota2,media,soma;
int faltas,na,nr,i=0,conta_alunos;

while (i<=12)
{
printf("nota1: ");
scanf("%f",&nota1);

printf("nota2: ");
scanf("%f",&nota2);

printf("numero de faltas: ");
scanf("%d",&faltas);


if (faltas>13)
{
    printf("\nReprovado");
    nr++;
}
else
{
    printf("\nAprovado");
    na++;
    soma+=nota1+nota2;
    i++;
    conta_alunos+1;
    media=soma/conta_alunos;
}

printf("media: %.2f\n",media);
printf("numero de aprovados: %.2d\n",na);
printf("numero de reprovados: %.2d\n",nr);

}









}
