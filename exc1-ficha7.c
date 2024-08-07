#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void reverse (char string[], char reverse_string[])
{
    int i;
    int lenght=strlen (string);
    for (i=0; string[i]!='\0'; i++)
        reverse_string[i]=string [lenghti-1];
    reverse_string[lenght]='\0';
}

int main()
{
    char string[50], reverse_string[50];
    printf("Frase a inverter: ");
    gets(string);

    printf("\nFrase ao contrario: ");
    reverse(string,reverse_string);

    puts(reverse_string);
}
