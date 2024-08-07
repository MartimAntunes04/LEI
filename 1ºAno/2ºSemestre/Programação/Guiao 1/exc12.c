#include <stdio.h>
#include <string.h>

int vetores_iguais(int ncol,int v1[][ncol],int linhas,int v2[][ncol],int colunas)
{
    int i,j;
    if(linhas==colunas)
    {
        return 1;
    }

        for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {


        if(v1[i][j]==v2[i][j]){
            return 1;
        }
    }

}
return 0;
}
void main()
{
    int v1[1][3]={1,2,3};
    int v2[1][3]={5,6,7};
    int linhas=1;
    int colunas=3;


    printf("%d",vetores_iguais(3,v1,1,v2,3));


