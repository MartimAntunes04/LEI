#include <stdio.h>
#include <string.h>


int alterar_string(char frase[],int TAMF,char c)
{
    int i;
    TAMF=strlen(frase);
    for(i=0;i<TAMF;i++)
    {
        if(strchr(frase[i],c))
        {
            c=2*c;
            frase=frase[i];


            return frase[i];
        }
        else{
            return frase[i];
        }
    }

}

void main()
{
    char frase[20],c,TAMF;

    printf("Frase: ");
    gets(frase);
    printf("Caracter: ");
    scanf("%c",&c);

    printf("%s",alterar_string(frase,TAMF,c));
}
