#include <stdio.h>
#include <string.h>

int alterastring(char frase[],char palavra[])
{
    int tamf,tamp,i=0;
    tamf=strlen(frase);
    tamp=strlen(palavra);




    if(tamp==tamf)
       {
        frase[i]=palavra;


       }

    else{
        printf("String nao alterada");
    }

}
void main()
{
    char frase[100], palavra[20];
    printf("String: ");
    gets(frase);

    printf("Palavra: ");
    gets(palavra);

    printf("String alterada: %s",alterastring(frase,palavra));
}
