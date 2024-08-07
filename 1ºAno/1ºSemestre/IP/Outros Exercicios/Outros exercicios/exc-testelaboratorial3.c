#include <stdio.h>

int Ligametalica(int CC, int DU,int RT)
{
    int classificacao;
    if (CC<70 && DU>50 && RT>80)
    {
        classificacao=3;
    }

    else if(CC<70 && DU>50)
    {
        classificacao=2;
    }
    else if(RT>80)
    {
        classificacao=1;
    }
    else
    {
        classificacao=0;
    }
return classificacao;
}

void main()
{
    int i,testes,RT,DU,CC;

    printf("Numero de testes> " );
    scanf("%d",&testes);

    for (i=0;i<testes;i++)
    {
        printf("RT DU e CC>    ");
        scanf("%d, %d ,%d",&RT,&DU,&CC);

        printf("Classificação deste metal = %d",Ligametalica(CC,DU,RT));
    }









}
