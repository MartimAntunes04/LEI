#include <stdio.h>

int media(int nlinha,int ncol,int tab[][ncol])
{
    int i,soma=0,conta=0;
    float media=0;
    for(i=0;i<nlinha;i++)
    {
        soma+=tab[ncol];
        conta++;
    }
media=soma/conta;
return media;
}

void main()
{
    int tab[2][4]={{1,2,3,4},{4,5,6,7}};

    printf("%f",media(2,4,tab));
}

