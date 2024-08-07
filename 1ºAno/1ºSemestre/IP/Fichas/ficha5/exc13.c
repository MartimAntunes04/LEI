#include <stdio.h>
int PedeAposta (int j)
{
    int aposta;
    printf ("Aposta (0-500) do jogador %d: ",j)
    scanf ("%d",&aposta);
    return aposta;
}
int Compara (int a,int b)
{
    int r
    if (a<b)
    {
        r=-1
    }
    else{
        if(a==b)
    {
        r=0
    }
        else{
            r=1
        }
    }

return r
}

void main()
{


int j=1,alvo,aposta,resultado

aposta=PedeAposta(j);
resultado=Compara(alvo,aposta);

switch (resultado)
{
case -1:
    printf("O numero %d esta abaixo do valor certo",num);
    break;

case 0:
    printf ("O jogador %d acertou",j);
    break;
case 1:
    printf ("O numero %d esta acima do valor certo",num);
    break;

}


if (j==1)
    j=2;
else
    j=1;

    while (resultado!=0);
}




