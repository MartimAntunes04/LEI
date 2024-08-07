#include <stdio.h>
void main()
{

    int a[10],b[10],i,intersecao[10],reuniao[10],subtracao[10];

    for(i=0;i<10;i++)
    {

        printf("valor a[%d]: ",i);
        scanf("%d",&a[i]);


    }

    for(i=0;i<10;i++)
    {


        printf("valor de b[%d]: ",i);
        scanf("%d",&b[i]);
    }


for(i=0;i<10;i++)
{
    intersecao[i]=a[i]&b[i];
    reuniao[i]=a[i]|b[i];
    subtracao[i]=a[i]^b[i];
    printf("\na[%d]: %d",i,a[i]);
    printf("\nb[%d]: %d",i,b[i]);
    printf("\ni[%d]: %d",i,intersecao[i]);
    printf("\nr[%d]: %d",i,reuniao[i]);
    printf("\ns[%d]: %d",i,subtracao[i]);
}

}
