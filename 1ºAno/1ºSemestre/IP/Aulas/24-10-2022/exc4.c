#include <stdio.h>
void main()
{
int num_1, num_2, num_3,maior;

printf ("num_1: ");
scanf ("%d",&num_1);
printf ("num_2: ");
scanf("%d",&num_2);
printf ("num_3: ");
scanf ("%d",&num_3);

if (num_2>num_1)
   maior=num_2;
else
    maior=num_1;
if (num_3>maior)
    maior=num_3;

printf ("Maior: %d\n",maior);








}
