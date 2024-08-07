#include <stdio.h>
#include <string.h>

int TrocarPorCaracter(char frase[],char par[],char c)
{
    int i,conta=0,j;

    for(i=0;frase[i]!='\0';i++)
    {

        if(frase[i]==par[0]&& frase[i+1]==par[1])
        {
            frase[i]=c;


        for(j=i+1;frase[j]!='\0';j++)
        {
            frase[j+1]=frase[j+2];

        }
        conta++;
        }
    }
return conta;
}

void main()
{
    char frase[20],par[2],c;

    printf("Frase: ");
    gets(frase);


    printf("Par de Caracteres: ");
    gets(par);


    printf("Novo Caracter: ");
    scanf("%c",&c);


    printf("Foram feitas %d alteracoes\n",TrocarPorCaracter(frase,par,c));
    puts(frase);
}
