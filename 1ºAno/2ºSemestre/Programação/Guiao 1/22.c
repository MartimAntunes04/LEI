
#include <stdio.h>
#include <string.h>

#define N	5


void escreve_sin(char *sin[][2], int tot_lin)
{
    int i;
	for(i=0;i<tot_lin;i++)
    {
            printf("%s-%s\n",sin[i][0],sin[i][1]);
    }
}

//22.2
char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{
	int i;
	for(i=0;i<tot_lin;i++)
    {
       if(strcmp(p,sin[i][0])==0)
       {
           return sin[i][1];
       }
       else if(strcmp(p,sin[i][1])==0)
       {
           return sin[i][0];
       }


    }
	return NULL;
}

//22.3



//22.4

int numeropalavras(char *sin[][2],int tot_lin)
{
    int i,j,conta=0;
    for(i=0;i<tot_lin-1;i++)
    {
        for(j=i+1;j<tot_lin;j++)
        {

            if(strcmp (sin[i][0],sin[j][0])==0 || strcmp(sin[i][0],sin[j][1])==0 || strcmp(sin[i][1],sin[j][i])==0, strcmp(sin[i][1],sin[j][1])==0)
            {
                conta++;
            }
        }
    }
    return conta;
}



int main()
{
	char palavra[50], *p;

	char *s[N][2] = {{"estranho", "bizarro"},
					 {"desconfiar", "suspeitar"},
					 {"vermelho", "encarnado"},
					 {"duvidar", "desconfiar"},
					 {"carro", "automovel"}};


	escreve_sin(s, N);		// alinea 22.1

	printf("Palavra a pesquisar: ");
	scanf(" %s", palavra);

	p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2

	if(p == NULL)
		printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
	else
		printf("A palavra %s e sinonimo de %s\n", p, palavra);


//22.3



//22.4


    printf("Numero de palavras que aparecem mais de uma vez na tabela: %d\n",numeropalavras(s,N));


return 0;
}
