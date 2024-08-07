int printMat(int mat[][3], int nLin){
    int i,j;
    for(i=0;i<nLin;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",mat[i][j]);

        }
        putchar('\n');
    }


}

int main()
{
    int mat[4][3]={{1,2,3},{10,11,12},{20,21,22},{51,51,52}};
    printMat(mat,4);
}
