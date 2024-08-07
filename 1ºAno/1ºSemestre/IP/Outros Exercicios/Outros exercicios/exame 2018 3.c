#include <stdio.h>
#include <string.h>

int funcao(char frase[],char maior[])
{
    int palavras,i;
    int lenght=strlen(frase);

    for(i=0;i<lenght;i++)
    {

    if(frase[i]==' ')
        palavras++;
    }


return palavras;
}
void main()
{
    char frase[20],maior[20];


    printf("Frase: ");
    gets(frase);

    printf("Palavras: %d",funcao(frase,maior)+1);


}
