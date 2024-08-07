#include <stdio.h>
#include <string.h>

int calculadoraInteiros(char c,char num1[],char num2[])
{
    int i,j,resultado;
    for(i=0;num1[i]!='\0';i++)
    {
        for(j=0;num2[i]!='\0';j++)
        {
            if(c=='+')
            {
                resultado=num1[i]+num2[j];
            }
            else if(c=='-')
            {
                resultado=num1[i]-num2[j];
            }
            else if(c=='/')
            {
                resultado=num1[i]/num2[j];
            }
        else if(c=='*')
        {
            resultado=num1[i]*num2[j];
        }
        }
    }
    return resultado;
}

void main()
{
    char num1[10],num2[10],c;

    printf("Numero: ");
    gets(num1);

    printf("Numero: ");
    gets(num2);

    printf("Operacao: ");
    scanf("%c",&c);

    printf("Resultado: %d",calculadoraInteiros(c,num1,num2));

}
