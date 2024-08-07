#include <stdio.h>

int main()
{

 float teste1, teste2, exame, nota;

printf ("teste1: ");
scanf ("%f", &teste1);
printf ("teste2: ");
scanf ("%f", &teste2);
printf ("exame: ");
scanf ("%f", &exame);

nota=teste1+teste2+exame;
printf ("nota: %.2f",nota);

return 0;

}
