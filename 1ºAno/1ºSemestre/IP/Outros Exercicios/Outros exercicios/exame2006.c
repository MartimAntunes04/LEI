#include <stdio.h>
#include <string.h>

int func(char frase[],char palavra[],int tamf,int tamp)
{
    int i,j;

    for(i=0;i!='\0';i++)
    {
       palavra[j]=frase[i];
       j = palavra[j] == ' ' && frase[i + 1] != ' ' && frase[i + 1] != '\0' ? 0 : j + 1;
    }
    palavra[j] = '\0';


    if(strcmp(frase,frase[i]==0)){

        return 0;
    }
    else{
        return 1;
    }
}

void main()
{
    char frase[80], palavra[15];
    int tamf,tamp,i;


    printf("Frase: ");
    gets(frase);
    printf("Palavra: ");
    gets(palavra);

    switch(frase[i])
    {
        case'1':printf("%s",func(frase,palavra,tamf,tamp));
        break;

        case '0':printf("Frase nao alterada: %s",frase);
        break;
    }
}
