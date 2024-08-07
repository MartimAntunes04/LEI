#include <stdio.h>

int alterastring(char frase[], char c)
{
    int i,conta=0;
    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]==c)
        {
            frase[i]='z';
            conta++;
        }

    }
return conta;
}

void main()
{
    char frase[50],c;

    printf("Frase: ");
    gets(frase);

    printf("Caracter: ");
    scanf("%c",&c);

    printf("Foram feitas %d alteracoes",alterastring(frase,c));
    puts(frase);
}
