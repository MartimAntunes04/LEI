#include <stdio.h>
int Quadrado (int num)
{
  return (num*num);
}

void main()
{
    int num;
    printf ("Numero= ");
    scanf("%d",&num);
    if (num!=0)
    {

        printf("Quadrado: %d",Quadrado(num));

    }
}
