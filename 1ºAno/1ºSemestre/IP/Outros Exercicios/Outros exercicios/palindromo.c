#include <stdio.h>
#include <string.h>

int palindromo(char frase[])
{
    int i,j,lenght=strlen(frase),resultado;
    for(i=0,j=lenght-1;i<lenght/2;i++,j--)
    {
        if(frase[i]!=frase[j]){
            resultado=0;
        }
        else{
           resultado=1;
        }


    }


return resultado;
}

void main()
{
    char frase[50];

    printf("Frase: ");
    gets(frase);

    printf("%d",palindromo(frase));
}
