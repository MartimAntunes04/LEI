#include <stdio.h>

int PontoNoRetangulo(float vInfEsq[],float vSupDir[],float Ponto[])
{
    if(Ponto[0]>=vInfEsq[0] && Ponto[1]>=vInfEsq[1] && Ponto[0]<=vSupDir[0]&& Ponto[1]<=vSupDir[1])
    {
        return 1;
    }
    else{
        return 0;
    }
}


void main()
{
    char participante[2],estudante[2];
    int ponto,total,i,j,lancamento[15],k,l;
    float vInfEsq[2],vSupDir[2],Ponto[2];

    printf("Inserir estudante (S/N)?: ");
    gets(participante);

    if(strchr(participante,'S'))
    {printf("Inserir estudante (S/N)?: ");
    gets(participante);


for(i=0;participante[i]!='N';i++)
        {
            printf("\nParticipante %d",i);

            printf("Estudante (S/N)?: ");
            gets(estudante);

            if(strchr(estudante,'S'))
            {
                printf("\nTem desconto de 50%");
            }
            for(l=0;l<15;l++)
            {
                printf("\nCooredenadas do lancamento %d: ",l);
                scanf("%d %d ",&lancamento[1]);

                ponto=PontoNoRetangulo(vInfEsq,vSupDir,Ponto);
                if(ponto==1)
                {
                    ponto++;
                    total+=ponto;
                }


            }
            printf("\nConseguiu %d pontos",total);
        }
    }
}
