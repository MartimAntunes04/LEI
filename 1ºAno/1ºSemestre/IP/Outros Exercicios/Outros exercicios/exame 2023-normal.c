#include <stdio.h>
#include <string.h>

int altarfrase(char s1[])
{
    int i,conta=0,N=strlen(s1),j;
    for(i=0;i<N;i++)
    {
        if(s1[i]=='c'&& s1[i+1]=='h')
        {
            s1[i]='x';
            for(j=i;s1[j]!='\0';j++)
            {
                s1[j+1]=s1[j+2];
            }
            conta++;
        }
    }
return conta;
}

void main()
{
    char s1[50];
    printf("Frase: ");
    gets(s1);
    printf("%d",altarfrase(s1));
    puts(s1);
}
