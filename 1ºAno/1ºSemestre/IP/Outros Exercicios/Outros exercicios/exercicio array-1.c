#include <stdio.h>
#define n 5

int Maior(int a[],int N)
{
    int i,conta=0,maior=a[0];
    for(i=0;i<N;i++)
    {
        if(maior<a[i])
        {
            maior=a[i];
            conta=1;
        }
        else if(maior=a[i])
        {
            conta++;
        }
    }
return maior;
}
void main()
{
    int a[n],i;

    for(i=0;i<n;i++)
    {
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }

printf("Maior numero: %d",Maior(a,n));
}
