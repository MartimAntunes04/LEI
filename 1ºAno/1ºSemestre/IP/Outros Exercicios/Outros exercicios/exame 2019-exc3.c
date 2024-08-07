#include <stdio.h>
#include <string.h>

int maiorPalavra(char frase[],char palavra[])
{
    if (palavra>strlen(frase))
    {
        return palavra;
    }
}

void main()
{


char frase[50],palavra[20];

printf("Frase: ");
gets(frase);

printf("Maior palavra de %s: %s",frase,maiorPalavra(frase,palavra));






}
