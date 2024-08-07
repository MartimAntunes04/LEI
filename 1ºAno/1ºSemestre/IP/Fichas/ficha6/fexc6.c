#include <stdio.h>

void main()
{
    int alunos_turma[24][6],i,j,aprovados=0
    ;

    for(i=0;i<24;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("Aluno e turma[%d][%d]: ",i,j);
            scanf("%d",&alunos_turma);
        }
    }

 if(alunos_turma>=10)
    {
        aprovados++;
        printf("Aprovados= %d",aprovados);
    }



}
