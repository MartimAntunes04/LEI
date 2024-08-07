#include <stdio.h>
#include <string.h>


int susbtituiPalavras(char frase[],char palavra[])
{


    int substituicao,i=0;

    if (strlen(palavra)==strlen(frase[i]))
    {
        frase[i]=palavra;
        substituicao++;
        i++;
    }
return substituicao;


}

void main()
{
    char frase[20], palavra[20];
    int substituicao;

    printf("Frase: ");
    gets(frase);

    printf("Palavra: ");
    gets(palavra);

    printf("Foram substituidas %d palavras na frase %s",susbtituiPalavras(frase,palavra),frase);

}
