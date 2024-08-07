#include <stdio.h>
#include <string.h>

int contapalavras(char frase[],int palavras)
{
    int i;
    for(i=0;i<strlen(frase);i++)
    {
        if(palavras==' ')
        {
            palavras++;
        }
    }
    return palavras;
}

void main()
{
    char frase[30];
    int palavras;
    printf("Frase: ");
    gets(frase);
    printf("A frase tem %d palavras",contapalavras(frase,palavras));
}
