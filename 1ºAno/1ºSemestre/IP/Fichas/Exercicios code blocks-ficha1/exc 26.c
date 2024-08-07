#include<stdio.h>


int main ()
{
    int b,e,resultado=1, i=0;
    printf ("BASE: ");
    scanf("%d", &b);
    printf ("EXPOENTE: ");
    scanf ("%d", &e);

    while (i<e)
    {
        resultado=resultado*b;
        i=i+1;
    }

    printf ("RESULTADO: %d",resultado);

    return 0;

}
