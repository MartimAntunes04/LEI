#include <stdio.h>
#include <string.h>

int substituiPalavras(char frase[],char palavra[])
{
    int i,j,tampalavra=strlen(palavra),conta=0,k;
    char aux[100];

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]!=' ')
        {
            aux[j]=frase[i];
            j++;
        }


    else{
        aux[j]='\0';

    if(tampalavra==strlen(aux))
    {
        conta++;

        for(k=0;k<tampalavra;k++)
        {
                frase[i-tampalavra+k]=palavra[k];
        }
    }
    }


    }
return conta;
}

int main() {
    char frase[100] = "esta frase tem varias palavras";
    char palavra[100] = "cao";
    int count = substituiPalavras(frase, palavra);
    printf("Frase alterada: %s\n", frase);
    printf("Numero de palavras substituidas: %d\n", count);
    return 0;
}
