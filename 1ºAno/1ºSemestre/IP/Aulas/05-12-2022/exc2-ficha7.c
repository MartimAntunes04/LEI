#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void conta_Primeiro (char str [])
{
    int i,j,conta=0;
    char primeiro;
    for(i=0; str[i]==' ';i++)
    primeiro=str[i];
    for(j=i;str[j]!='\0';j++)
        if(toupper(str[j])==touper(primeiro))
        conta++;
    return conta;








}
int main()
{
   char frase [50];
   int conta;
   printf("Introduza a frase: ");
   scanf("%49[^\n]",frase);
   puts(frase);
   conta=conta_Primeiro(frase);
   printf("\nO primeiro caracter surge %d vezes na frase",conta_Primeiro);
   return 0;


}
