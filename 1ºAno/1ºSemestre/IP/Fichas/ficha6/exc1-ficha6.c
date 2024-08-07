#include <stdio.h>
#define n 5
int Calculamedia(int a[],int N)
{
    int i,soma=0,conta=0,media;
    for(i=0;i<N;i++)
    {
        soma+=a[i];
        conta=conta+1;
    }

media=soma/conta;
}

void main()
{
    int a[n],i,media;

    for(i=0;i<n;i++)
        {
    printf("a[%d]= ",i);
    scanf("%d",&a[i]);

    }

media=Calculamedia(a,n);
printf("Media=%d",media);

}
