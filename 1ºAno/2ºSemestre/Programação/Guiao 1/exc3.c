#include <stdio.h>

void zero(int tab[],int tam)
{
    int i,soma,conta=0,media;
    for(i=0;i<tam;i++)
    {
        soma+=tab[i];
        conta++;

    }
    media=soma/conta;

    if(tab[i]<media)
    tab[i]='0';
}

int main()
{
    int tab[10]={2,5,8,12,9,4,13,23,7,19};
    zero(tab,10);

    printf("%d",tab[10]);
}
