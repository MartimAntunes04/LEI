#include <stdio.h>
#define n 5

int Soma(int a[],int N)
{
    int i,maior=a[0],conta=0,soma;
    for(i=0;i<N;i++)
    {
        if(maior<a[i])
        {
            maior=a[i];
            conta=1;
        }
        else if(maior==a[i])
        {
            conta++;
        }
    }

return maior*conta;

}


void main()
{
    int a[n],i,soma;

    for(i=0;i<n;i++)
    {
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
printf("%d",Soma(a,n));
}

