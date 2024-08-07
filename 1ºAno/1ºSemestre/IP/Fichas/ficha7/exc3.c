#include <stdio.h>
#include <string.h>

void main()
{
    char frase[10];
    int i;

    printf("Frase: ");
    gets(frase);

    for(i=0;i<9;i++)
    {
        printf("\n%s",frase[i]);
    }
}
