#include <stdio.h>
#include <string.h>

int repeticoes(char s[],int n)
{
    int i;
    for(i=0;s[i]!='/0';i++)
    {

            n=s[i];
    }
    return s[n];
}

void main()
{
    char s[20];
    int n;

    printf("Frase: ");
    gets(s);
    printf("Caracter: ");
    scanf("%d",&n);

    printf("%c",repeticoes);
}
