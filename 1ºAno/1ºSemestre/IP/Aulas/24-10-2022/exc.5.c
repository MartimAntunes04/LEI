#include <stdio.h>
void main()
{

int b,e;
int resultado=1,i=1;

printf ("base: ");
scanf ("%d,&b");
printf ("expoente: ");
scanf ("%d, &e");

while (i<=e)
{

resultado*=b; //resultado:resultado*b;
i++;
}

printf ("o valor de %d levantado a %d e %d", b,e,resultado);\


}
