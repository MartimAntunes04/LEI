#include <stdio.h>
void roda_elemento(int a[],int N)
{
    int i=N-1,aux=a[N-1];
    for(i=N-1; i>0; i--)
        a[i]=a[i-1];
    a[0]=aux;
}
void main()
{
    int N=5;
    int a[N],i=0,pos,roda;
    for(i=0; i<N; i++)
    {
        printf("\na[%d]= ",i);
        scanf("%d",&a[i]);
    }

    pos=Posicao(a,N);
    roda=N-pos-1;
    for(i=0; i<roda; i++)
    {
        RodaUmInteiro_1(a,N);
    }
    for(i=0; i<N; i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
}
