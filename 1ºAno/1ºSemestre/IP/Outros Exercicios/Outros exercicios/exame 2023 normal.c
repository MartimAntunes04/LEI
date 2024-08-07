#include <stdio.h>
#include <string.h>
#define n 100

int alterafrase( char s1[])
{
    int i,N=strlen(s1),conta=0,j;
    for(i=0;i<N;i++)
    {
        if(s1[i]=='c'&& s1[i+1]=='h')
        {
            s1[i]='x';
            conta++;
        }

    }
    return conta;
}
void main()
{
    char s1[n];
    printf("Frase: ");
    gets(s1);
    printf("\nForam feitas %d alteracoes",alterafrase(s1));
    puts(s1);
}
