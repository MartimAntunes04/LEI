#include <stdio.h>

float media_final(int valor, int valido)
{
    float media,soma;
    int conta;
    media=soma/conta;

    if (valido==1)
    {
        soma+=valor;
        conta++;
        return 0;
    }

    else if(valido==0)
    {
        return media;
    }

}

void main()
{
    int valor,valido,conta;
    float soma,media;

        printf("Introduza um numero: ");
        scanf("%d",&valor);
    while(valor>0 && valor<10)
    {
        printf("Introduza um numero: ");
        scanf("%d",&valor);
    }

    printf("Quer adicionar um numero para a media(sim(1)/nao(0):");
    scanf("%d",&valido);

    printf("Media= %.2d",media_final(valor,valido));

}
