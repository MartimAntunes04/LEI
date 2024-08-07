#include <stdio.h>
#define n 5
int Arrayigual(int a[], int b[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(a[i]==b[i])
            return 0;
    }
    return 1;
}

void main()
{
    int a[n],b[n],resultado,i;
    for(i=0;i<n;i++)
    {
        printf ("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        printf("b[%d]: ",i);
        scanf("%d",&b[i]);
    }

resultado=Arrayigual(a,b,n);
switch(resultado)
{
case 0:
    printf("Arrays iguais");
     break;
case 1:
    printf("Arrays diferentes");
    break;
}






}
