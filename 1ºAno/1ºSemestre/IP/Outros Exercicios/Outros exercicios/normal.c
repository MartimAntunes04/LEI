#include <stdio.h>

int alterafrase(char frase[])
{
    int i,j,conta=0;

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]=='c' && frase[i+1]=='h')
        {
            frase[i]='x';

        for(j=i;frase[j]!='\0';j++)
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
    char frase[50];

    printf("Frase: ");
    gets(frase);

    printf("Alteracoes: %d",alterafrase(frase));
    puts(frase);
}
