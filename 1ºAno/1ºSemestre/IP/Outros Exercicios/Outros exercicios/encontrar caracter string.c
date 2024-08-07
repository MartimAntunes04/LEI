#include <stdio.h>
#include <string.h>

int surgeCaracter(char string[],char c)
{
    if(strchr(string,c))
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
void main()
{
    char string[20],c;


    printf("Introduza um caracter: ");
    scanf("%c",&c);

    printf("Introduza uma string: ");
    scanf("%s",string);


    printf("%d",surgeCaracter(string,c));
}
