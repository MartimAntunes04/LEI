#include <stdio.h>
void main()
{

    int idade, soma=0,conta_idade=0,media_idade,idade_max,idade_min;

    while (idade>0)
    {
printf("Introduza idade: ");
        scanf("%d",&idade);
idade++;
        soma+=idade;
        conta_idade=conta_idade+1;
        media_idade=soma/conta_idade;
        idade_max>=idade;
        idade_min<=idade;


    }
    printf("idade maxima= %d\n",idade_max);
    printf("idade minima= %d\n",idade_min);
    printf("media das idades= %d\n",media_idade);



}
