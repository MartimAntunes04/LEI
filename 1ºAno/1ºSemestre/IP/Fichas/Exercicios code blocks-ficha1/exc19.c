#include <stdio.h>
void main()
{

float a,b,c;

printf("linha a: ");
scanf("%f",&a);
fflush(stdin);
printf("linha b: ");
scanf("%f",&b);
fflush(stdin);
printf("linha c: ");
scanf("%f",&c);
fflush(stdin);

if ((a-b<c) && (c<a+b))
{
    printf("Forma triangulo");
}

else
{
    printf("Nao forma triangulo");
}









}
