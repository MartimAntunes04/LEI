#include <stdio.h>
#include <string.h>

int PontoNoRetangulo(float vInfEsq[],float vSupDir[],float alvo[])
{
    int pontos;
    if(alvo[0]>vInfEsq[0] && alvo[0]<vSupDir[0] && alvo[1]>vInfEsq[1] && alvo[1]<vSupDir[1])
    {
     pontos++;
    }
    else{
        pontos=0;
    }
return pontos;
}
void main()
{
    float vInfEsq[2], vSupDir[2],alvo[2];
    char estudante[5],gameover[5];
    int i,lancamentos=15;

    printf("Novo jogador: ");
    scanf("%s",gameover);

    while (gameover!=strstr(gameover,"fim"))
    {

    printf("E estudante(Sim ou Nao): ");
    scanf("%s",estudante);

    if(strstr(estudante,"Sim"))
    {
        printf("Tem desconto de 50%, o preco da inscricao e 5 euros");
    }
    else if (strstr(estudante,"Nao"))
    {
        printf("O preco da inscricao e 10 euros");
    }



    for (i=0;i<lancamentos;i++)
    {
        printf("\nIntroduza as coordenadas do vertice inferior esquerdo: ");
        scanf("%f %f",&vInfEsq[0],&vInfEsq[1]);

        printf("\nIntroduza as coordenadas do vertice superior direito: ");
        scanf("%f %f",&vSupDir[0],&vSupDir[1]);

        printf("\nIntroduza as coordenadas do ponto: ");
        scanf("%f %f",&alvo[0],&alvo[1]);

    }

    }
printf("%d",PontoNoRetangulo(vInfEsq,vSupDir,alvo));


}
