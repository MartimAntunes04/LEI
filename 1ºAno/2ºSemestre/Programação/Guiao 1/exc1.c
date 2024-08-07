#include <stdio.h>

void main()
{
    int a,b,total,*p=&a,*q=&b,*r=&total;

    printf("Numero: ");
    scanf("%d",p);
    fflush(stdin);

    printf("Numero: ");
    scanf("%d",q);

    *r=*p + *q;
    printf("a= %d \n b=%d\n total=%d\n",a,b,total);
}
