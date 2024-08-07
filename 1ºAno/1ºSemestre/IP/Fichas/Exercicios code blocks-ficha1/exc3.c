#include <stdio.h>

#define PI 3.14159

int main()
{

    float raio, perimetro, area;
    printf ("raio: ");
    scanf ("%f", &raio);
    perimetro= 2*PI*raio;
    area= PI* raio*raio;
    printf ("perimetro: %.2f\n",perimetro);
    printf ("area:%.2f\n",area);

 return 0;
}


