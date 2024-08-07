#include <stdio.h>
int main ()
{


int dia, mes, ano;
float montante,taxa;


printf ("data atual no formato dia/mes/ano: ");
scanf ("%d/%d/%d", &dia,&mes,&ano);
printf ("Montante: ");
scanf ("%f", &montante);
printf ("Taxa: ");
scanf ("%f",&taxa);
montante+=montante*taxa/100;

printf ("Na data %d/%d/%d o montante e de %f", dia,mes,++ano, montante);

return 0;



}
