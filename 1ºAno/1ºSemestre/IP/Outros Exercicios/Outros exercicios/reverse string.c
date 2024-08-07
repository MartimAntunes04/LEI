#include <stdio.h>
#include <string.h>

void reverter(char frase[], char reverse_string[])
{
    int i,lenght=strlen(frase);

    for(i=0;i<lenght;i++)
    {
        reverse_string[i]=frase[lenght-i-1];
        reverse_string[lenght]='\0';
    }
}


void main()
{
    char frase[50],reverse_string[50];
    printf("Frase: ");
    gets(frase);

    printf("Frase ao contrario: ");
    reverter(frase,reverse_string);

    puts(reverse_string);
}
