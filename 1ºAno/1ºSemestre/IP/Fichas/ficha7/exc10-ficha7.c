#include <stdio.h>
#include <string.h>

int calculadoraInteiros(char c,char num1[],char num2[])
{
    int resultado=0,i=0;
    if(c=='+')
    {
        resultado=num1[i]+num2[i];
    }
    else if(c=='-'){
        resultado=num1[i]-num2[i];
    }
    else if(c=='*')
    {
        resultado=num1[i]*num2[i];
    }
    else if(c=='/')
    {
        resultado=num1[i]/num2[i];
    }
    return resultado;
}

void main()
{
    char num1[10],num2[10],c;
    printf("Num1: ");
    gets(num1);
    printf("Num2: ");
    gets(num2);
    printf("c= ");
    scanf("%c",&c);
    printf("Resultado: %d",calculadoraInteiros(c,num1,num2));
}
