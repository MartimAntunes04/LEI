#include <stdio.h>
void main()
{
int num_lados;
float perimetro, area, lado;

printf("num_lados: ");
scanf ("%d", &num_lados);
printf ("comprimento lado: ");
scanf ("%f", &lado);

switch (num_lados)

case 3:
    {
        perimetro=3*lado;
        printf ("perimetro: %.2f\n",perimetro);
        printf ("Triangulo");
        break;

case 4:
    area=lado*lado;
    printf ("area: %.2f\n",area);
    printf ("Quadrado");
    break;
case 5:
    printf ("Pentagono");
    break;

default: printf ("Nao e poligono");


    }













}
