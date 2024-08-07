#include <stdio.h>
void main()
{

float altura,peso;

printf("Introduza a altura (m): ");
scanf("%f",&altura);
fflush(stdin);
printf("Introduza o peso (kg): ");
scanf("%f", &peso);

if((altura>=1,75 && altura<=1,90) || (peso>=70 && peso<80))
        {

        printf("ACEITE");
        }
else
{

    printf("TOTALMENTE RECUSADO");
}
}
