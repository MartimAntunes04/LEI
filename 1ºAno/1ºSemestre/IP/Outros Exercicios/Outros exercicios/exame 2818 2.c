#include <stdio.h>
#define n 5

int EliminaValor(int v[],int tam,int num)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(v[i]==num)
        {
            v[i]--;

        }
    }
    tam--;
return tam;
}

void main()
{
    int v[n],num,i;

    for(i=0;i<n;i++)
    {
        printf("v[%d]= ",i);
        scanf("%d",&v[i]);
    }
    printf("Numero: ");
    scanf("%d",&num);
    printf("v[%d]= %d",i,EliminaValor(v,n,num));
}
