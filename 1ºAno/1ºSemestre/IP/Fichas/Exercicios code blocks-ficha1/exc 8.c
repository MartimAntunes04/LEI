#include <stdio.h>

int main ()
{
 float ordenadoliquido, valorSS, valorIRS, vencimento;

printf ("ordenadoliquido: ");
scanf ("%f", &ordenadoliquido);

valorIRS=ordenadoliquido*0.25;
printf ("valorIRS: %.2f\n",valorIRS);

valorSS=ordenadoliquido*0.11;
printf ("valorSS: %.2f\n", valorSS);

vencimento=ordenadoliquido-(valorSS+valorIRS);
printf ("vencimento: %.2f\n", vencimento);

return 0;



}
