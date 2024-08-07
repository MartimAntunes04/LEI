#include <stdio.h>
#define n 5

int Somamaior(int a[],int N[])
{
    int i,maior=a[0],conta=0,soma;
    for(i=0;i<N;i++)
    {
        if(maior<a[i])
        {
            maior=a[i];
            conta=1;
        }

        else
        {
            if(maior=a[i])
            {
                conta++;
            }
        }

    }

soma=maior*conta;
return soma;
}
void main()
{
    int i,a[n];

    for(i=0;i<n;i++)
    {


    printf("a[%d]= ",i);
    scanf("%d",&a[i]);
}
printf("%d",Somamaior(a,n));
}
