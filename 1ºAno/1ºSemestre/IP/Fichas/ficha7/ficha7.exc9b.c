#include <stdio.h>
#include <string.h>

int verifica_caracter(char frase[],char c)
{
    int i,conta=0,x=3;
    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]==c){
            conta++;
        if(conta==x)
        {
            return 1;
        }
    }
    else{
        return 0;
    }
}
}
void main()
{
    char frase[20],c;

    printf("Introduza um caracter: ");
    scanf("%c",&c);
    fflush(stdin);
    printf("Frase: ");
    gets(frase);
    fflush(stdin);
    while(frase!=strstr(frase,"fim"))
    {
        printf("Frase: ");
        gets(frase);
    }

   printf("%s",verifica_caracter(frase,c));
}
