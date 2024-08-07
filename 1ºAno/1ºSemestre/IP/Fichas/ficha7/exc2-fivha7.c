#include <stdio.h>
#include <string.h>

int contaPrimeiro(char string[])
{
    char caracter;
    int vezes=0,i;


    for(i=0;i<strlen(string);i++)
    {
        string[i] = toupper(string[i]);
        if (string[i] != ' ' && caracter== ' ')
        {
            caracter = string[i];
            vezes++;
            i++;
        }
        if (caracter != ' ' && string[i] == caracter)
            vezes++;
    }
return vezes;
}

void main()
{
    char string[20],caracter;

    printf("Frase: ");
    gets(string);

    printf("%d",contaPrimeiro(string));
}


