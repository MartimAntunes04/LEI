#include <stdio.h>

int main ()
{

 float total_uvas, cooperativa, pessoal, vinho_tinto, vinho_branco;

 printf ("total_uvas: ");
 scanf ("%f", &total_uvas);

 cooperativa=total_uvas*3/4;
 pessoal=total_uvas*1/4;
 vinho_tinto=cooperativa*2/5;
 vinho_branco=cooperativa*3/5;

 printf ("cooperativa: %.2f\n",cooperativa);
 printf ("pessoal: %.2f\n", pessoal);
 printf ("vinho_tinto: %.2f\n", vinho_tinto);
 printf ("vinho_branco: %.2f\n", vinho_branco);

 return 0;


}
