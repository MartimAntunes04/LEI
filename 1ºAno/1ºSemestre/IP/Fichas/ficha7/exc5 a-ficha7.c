#include <stdio.h>
#include <string.h>

int duplicacaracter(char frase[],char c)
{
    int i,j;

    for(i=0;frase[i]!='\0';i++)
    {
        if(frase[i]==c)
        {


            for(j=i;frase[j]!='\0';j++)
            {
                frase[j+1]=frase[j];
            }
            frase[i+1]=c;
    return 1;
        }
else{
    return 0;
}
    }

}

void main()
{
    char frase[20],c;


    printf("Frase: ");
    gets(frase);

    printf("Caracter: ");
    scanf("%c",&c);
    printf("%d",duplicacaracter(frase,c));
    puts(frase);

}
