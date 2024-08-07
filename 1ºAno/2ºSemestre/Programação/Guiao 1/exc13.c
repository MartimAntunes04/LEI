#include <stdio.h>

int produto_escalar(int a[],int b[],int n)
{
    int i,j,x=0;
    for(i=0;i<n;i++)
    {

            x+=a[i]*b[i];


    }
return x;
}
void main()
{
    int a[3]={1,2,3};
    int b[3]={1,1,1};

    printf("O produto escalar de a com b e %d",produto_escalar(a,b,3));
}
