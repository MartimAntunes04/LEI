#include <stdio.h>
int Calculacubo(int num)
{
return(num*num*num);
}



void main()
{
    int num;
    printf("numero: ");
    scanf("%d",&num);
    printf("%d",Calculacubo(num));
}

