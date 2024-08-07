#include <stdio.h>
int posicao(int a[],int N)
{
    int i;
    int maior=a[0];
    int pos=0;
    for (i=1;i<N;i++)
    {
        if(a[i]>=maior)
        {
            a[i]=maior;
            pos=i;
        }
    }
return pos;
}
void main()
{
    int a[5],N=5,maior,i=0;
    for(i=0;i<N;i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
        maior=posicao(a,N);
        printf("Maior=%d",posicao);
    }
}
