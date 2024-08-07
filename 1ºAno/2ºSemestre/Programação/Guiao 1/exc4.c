#include <stdio.h>

void obtemInfo(int tab[],int tam,int *ni, int*np, int*pos, int *val)
{

    int i,maior;
    for(i=0;i<tam;i++)
    {
        if(tab[i]%2==0)
            ++*np;
        else
            ++*ni;

        if(tab[i]>maior){
         maior=tab[i];
         *val=maior;
         *pos=i;

        }
    }
}

int main()
{
    int tab[10]={2,5,8,12,9,4,13,23,7,19};
    int np,ni,pos,val;

    obtemInfo(tab,10,&ni,&np,&pos,&val);

    printf("Impares:%d \n Pares:%d\n",ni,np);
    printf("Maior:%d e posicao %d",val,pos);
}
