#include <stdio.h>
#include <string.h>

int funcao(char frase[],char maior)
{
    int i,j,k,inicio,tampalavras;
    char palavras[];

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]==' '){
            palavras++;}



        if(frase!=' ')
        {
            inicio=i;
            i=j;
            tampalavras=0;
        }


        while(frase[j]!='\0' && frase[j]!=' ')
        {
            tampalavras++;
            j++;
            if(tampalavras>maior)
            {
                inicio=i;
                maior=tampalavras;
                j=i;            }

        }
      k=0;
    for(i=inicio;i<inicio+maior;i++)
    {
        palavras[k]=frase[i];
        k++;
    }
    palavras[k]='\0';

    }
    printf("A maior palavras e %s",palavras);
return palavras+1;
}





void main()
{
    char frase[20];

    printf("Frase: ");
    gets(frase);

    printf("%d",funcao(frase));
}
