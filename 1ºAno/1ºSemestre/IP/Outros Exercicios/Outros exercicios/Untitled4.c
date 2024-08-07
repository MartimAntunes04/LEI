#include <string.h>
#include <stdio.h>

int espelho(char frase,int tamanho)
{
    int i,lenght=strlen(frase);
    char reverse_string[100];
    for(i=0;frase[i]!='\0';i++)
    {
        reverse_string[i]=frase[lenght-i-1];
        reverse_string[tamanho]='\0';

    }
}
return strcat(frase,reverse_string);

void main()
{
    char frase[120];

    printf("Frase: ");
    gets(frase);

    reverse=espelho(frase,tamanho);
    puts(reverse);

}
