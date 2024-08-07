#include <stdio.h>
int valido(int m[][3],int x,int v)
{
    int i;
    if(v<1 || v>100)
        return 0;
    for(i=0;i<x;i++)
        if(m[i][0]==v)
        return 0;
    return 1;
}




void initMat(int mat[][3],int nLin)
{
    int i,v;



    for(i=0;i<nLin;i++)
    {
        do{
        printf("Linha %d",i);
        scanf("%d",&v);

    }while(valido(mat,i,v)==0)
        mat[i][0]=v;
        mat[i][1]=v*v;
        mat[i][2]=v*v*v;

    }





}

void main()
{
    int mat[4][3]={{1,2,3},{10,11,12},{20,21,22},{51,51,52}};
    printMat(mat,4);
}
