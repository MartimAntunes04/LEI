#include <stdio.h>
#define n 5

void Somaarray(int a[],int b[], int N,int soma[])
{
  int i;
  for (i=0;i<N;i++)
  {
      soma[i]=a[i]+b[i];
  }


}

void main()
{
    int a[n],b[n],i,soma[n];

    for(i=0;i<n;i++)
    {
        printf ("a[%d]= ",i);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        printf ("b[%d]= ",i);
        scanf("%d",&b[i]);
    }
Somaarray(a,b,n,soma);

    for(i=0;i<n;i++)
    {
        printf("\nSoma[%d]= %d",i,soma[i]);
    }





}
