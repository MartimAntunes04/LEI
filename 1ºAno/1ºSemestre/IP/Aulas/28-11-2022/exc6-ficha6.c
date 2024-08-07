#include <stdio.h>
int SomaMaiorArray(int a[],int N)
{
    int i;
    int maior=a[0];
    int ocorrencia=1;
    for(i=1; i<N; i++)
    {
        if(a[i]==maior)
        {
            ocorrencia++;
        }
        else if(a[i]>maior)
        {
            maior=a[i];
            ocorrencia=1;
        }
    }
    return ocorrencia*maior;
}


void main()
{
    int a[5],N=5,soma=0,i=0;
    for(i=0; i<N; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);

    }

    soma=SomaMaiorArray(a,N);
    printf("\nSoma=%d",soma);

}





