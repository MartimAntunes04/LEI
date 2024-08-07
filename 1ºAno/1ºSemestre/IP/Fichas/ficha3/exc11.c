#include <stdio.h>
void main()
{

char disciplina;
int nota;

printf("Disciplinas: ");
printf("\nPortugues (P)");
printf("\nIngles (I)");
printf("\nMatematica (M)");

printf("\ndisciplina: ");
scanf("%c",&disciplina);
switch (disciplina)
{
case 'P':
    printf("\nNota obtida de 0-20: ");
    scanf("%d",&nota);
    break;
case 'I':
    printf("\nNota obtida de 0-20: ");
    scanf("%d",&nota);
    break;
case 'M':
    printf("\nNota obtida de 0-20: ");
    scanf("%d",&nota);
    break;
default:
    {printf("Disciplina invalida");}


}

if ((nota>=10)&&(disciplina=='P'||'I'||'M'))
{
    printf("Na disciplina de %c o aluno passou com %d valores",disciplina,nota);
}
else
{
    printf("Na disciplina de %c o aluno reprovou com %d valores",disciplina,nota);
}











}
