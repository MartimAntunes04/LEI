#include <stdio.h>
#include <string.h>

void maiorPalavra(char frase[],char palavra[])
{
    int i,j,k, maior, inicio;
    int tamFrase = strlen(frase);
    int tamPalavra = 0;

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]!=' ')
        {
          j=i;
          inicio=i;
          tamPalavra=0;


        for(j=0;frase[j]!='\0' && frase[j]!=' ';j++)
        {
            tamPalavra++;
            j++;
        }
        if(tamPalavra>maior)
        {
            maior=tamPalavra;
            inicio=i;
            i=j;
        }
        }
    }

k=0;
for (i = inicio; i < inicio + maior; i++)
    {
        palavra[k] = frase[i];
        k++;
    }
    palavra[k] = '\0';

    printf("A maior palavra é: %s\n", palavra);

}

void main()
{
    char frase[20],palavra[20];

    printf("Frase: ");
    gets(frase);
     printf("A maior palavra é: %s\n", palavra);
}
