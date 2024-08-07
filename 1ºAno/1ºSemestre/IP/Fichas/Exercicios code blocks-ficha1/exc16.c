#include <stdio.h>
void main()
{

float num_1,num_2;
char op;

printf("Introduza um numero:" );
scanf("%f",&num_1);
printf("Introduza um numero: ");
scanf("%f",&num_2);
printf("Operacao: ");
fflush(stdin);
scanf("%c",&op);

switch(op)
{
    case '+':
        printf("Resultado: %.2f",num_1+num_2);
        break;
    case '-':
        printf("Resultado: %.2f",num_1-num_2);
        break;
    case'x':
        printf("Resultado: %.2f",num_1*num_2);
        break;
    case '/':
        printf("Resultado: %.2f",num_1/num_2);
        break;
    default:
        printf("Operacao invalida");

}






}
