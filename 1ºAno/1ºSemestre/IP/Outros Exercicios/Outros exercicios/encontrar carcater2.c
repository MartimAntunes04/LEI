#include <stdio.h>
#include <string.h>


void main()
{
    char string[20],c;
    int x,i;

    printf("Introduza um caracter: ");
    scanf("%c",&c);

    while(string!=strstr(string,"fim"))
    {
        printf("Introduza uma string: ");
        gets(string);
    }

    printf("Amaior string onde o caracter %c surgiu 3 vezes consecutivas é: %s",c,string);
}
