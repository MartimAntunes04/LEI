#include <stdio.h>
#include <string.h>

void palavramaior(char frase[], char palavra[])
{
    int i,j,k,inicio,tampalavra=strlen(palavra),maior;

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]!=' ')
        {
            inicio=i;
            tampalavra=0;




        while(frase[i]!='\0' && frase[i]!=' ')
        {
            tampalavra++;
            i++;}

            if(tampalavra>maior)
            {
                maior=tampalavra;;
                inicio=i-tampalavra;
                j=0;
                for(i=inicio;i<inicio+maior;i++)
{
    palavra[j]=frase[i];
    j++;
}
palavra[j]='\0';

            }
            }
        }
    }







void main()
{
    char frase[50],palavra[50];
    palavramaior(frase,palavra);

    printf("Frase: ");
    gets(frase);

    printf("A maior palavra e %s",palavra);
}
