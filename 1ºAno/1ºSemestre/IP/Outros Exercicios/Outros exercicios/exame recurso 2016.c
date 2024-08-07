#include <stdio.h>
#include <string.h>

int UltimaPalavra(char frase[],char palavra[],int dmax)
{

   int i=strlen(frase)-1,posicao,j=0;

    if(strlen (frase)==0)
        return -1;

    else

        while{frase[i]==' ')
        i--;
        while(frase[i]!=' ')
            i--;
        i++;
        posicao=i+1;
        while(frase[i]!='\0'&& frase[i]!=' '){
            posicao[j]=frase[i];
            j++;
            i++;
        }
    palavra[j]='\0';

    if(strlen[palavra>dmax){
        return -1;
    }
    return posicao
    }

void main()
{
    char frase[81], palavra[9];
    int dmax,i,j=0;

    printf(Frase: );
    gets(frase);
    p= UltimaPalavra(frase,ultima,strlen{palavra)-1);
if (p>=0)
printf("Ultima palavra: %s, que começa na posicao %d da frase\n",ultima,p);
else
 printf("Nao foi possivel definir a ultima palavra\n");
}






}
