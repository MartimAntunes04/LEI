#include <stdio.h>

int apagavogais(char frase[])
{
    int i,j,conta=0;
    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]=='a' || frase[i]=='e'|| frase[i]=='i'|| frase[i]=='o'|| frase[i]=='u')
        {

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

    printf("Foram encontradas %d vogais",apagavogais(frase));

}
