#include <stdio.h>

void escreveMat(int nLin,int nCol,float a[][nCol]){
int i,j;
for(i=0;i<nLin;i++){
    for(j=0;j<nCol;i++){
    printf("%d",a[i][j]);
    putchar('\n');
}
}
}

void main(int argc,char ** argv)
{
    float m1[3][2]={{3.8,2.9,4.5,1.6,1.9,8.6,1.3,5.4}};
    float m2[2][6]={{1.0,2.6,7.1,7.4,2.4,5.8},{4.2,3.4,7.8,5.7,1.7,3.6}};
    int min1=0,max1=0,min2=0,max2=0;

    escreveMat(2,6,m2);
}
