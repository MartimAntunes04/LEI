#include <stdio.h>
#include <string.h>
#define TAMFRASE 50
#define TAMFIM 75


int func(char s1[],char s2[],char stfim[],int tamf)
{
    int i,conta,maior,x=0,tam1,tam2;

    tam1=strlen(s1);
    tam2=strlen(s2);

    if(tam1>tam2)
    {
        tam1=maior;
    }
    else
    {
        tam2=maior;
    }

    for(i=0;i<maior;i++)
    {conta++;
        if(conta<=tam1)
        {

        stfim[x]=s1[i];
        x++;
    }

    else if(conta<=tam2)
    {
       stfim[x]=s2[i];
       x++;
    }

    }
        if(tam1+tam2<tamf && tam1+tam2>maior)
        {
            return 1;
        }
return 0;
}


void main()
{
 char f1[TAMFRASE], f2[TAMFRASE], final[TAMFIM]=””;
 printf(“Indique a frase 1: “); gets(f1);
 printf(“Indique a frase 2: “); gets(f2);
 if(func(f1, f2, final, TAMFIM))
printf(“Frase modificada:\n%s\n”,final);
 else
printf(“Frase não modificada!\n”);
}
