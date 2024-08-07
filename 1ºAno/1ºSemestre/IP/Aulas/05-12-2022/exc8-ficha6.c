#include <stdio.h>
#define DIM_TAB 10

void Decrescente(int v[],int dim)
{
    int i, j,aux,k,z,aux2;


for(k=0;k<dim && v[k]<v[k+1];k++)


while(i<k)
{
    for (j=k+1-i;j<dim && v[j]>=v[0];j++);
        aux=v[0];

for (z=j-1;j>=0;z--)
{
    aux2=v[z];
    v[z]=aux;
    aux=aux2;
}
i++;


}


}

void main()

    {
    int v[DIM_TAB] = {1, 16, 19, 20, 23, 26, 32, 36, 21, -106},i;
    Decrescente(v,DIM_TAB);
    for(i=0;i<DIM_TAB;i++)
        printf("\npiramide[%d]=%d",i,v[i]);
}
