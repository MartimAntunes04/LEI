#include <stdio.h>
#include <string.h>

int TrocarPorCaracter(char frase[],char palavra[],char carater)
{
    int conta=0;
    if(strchr(frase,palavra))
    {
        palavra=carater;
        conta++;
    }
return conta;
}

void main()
{
    char frase[50],palavra[2],carater;

    printf("Frase: ");
    gets(frase);

    printf("Palavra: ");
    gets(palavra);

    printf("Carater: ");
    scanf("%c",&carater);

    printf("Foram efetuadas %1.1d subtituicoes: \n %s",TrocarPorCaracter(frase,palavra,carater));
}
