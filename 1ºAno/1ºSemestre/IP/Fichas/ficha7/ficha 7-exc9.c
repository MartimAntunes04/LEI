#include <stdio.h>
#include <string.h>


int verifica_caracter(char frase[],char c,int x)
{
        int i,conta=0;
    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]==c)
        {
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
    int x;

    printf("Frase: ");
    gets(frase);

    printf("Caracter: ");
    scanf("%c",&c);
    printf("Existe: ");
    scanf("%d",&x);
    printf("%d",verifica_caracter(frase,c,x));
}
