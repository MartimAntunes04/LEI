#include <stdio.h>
#include <string.h>

int contaPrimeiro(char frase[])
{
    int i,conta=0,j;
    char primeiro;
        for(i=0;frase[i]==' ';i++)
    {
        primeiro=frase[i];
        for(j=i;frase[j]!='\0';j++)
        {
            if(frase[j]==primeiro)
                conta++;
        }

    }

return conta;
}

void main()
{
    char frase[20];
    printf("Frase: ");
    gets(frase);

    printf("%d",contaPrimeiro(frase));
}
