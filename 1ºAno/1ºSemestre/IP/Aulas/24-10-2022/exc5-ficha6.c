#include <stdio.h>
void main()
{

    int a[10],num,i,cap=1,n=0;

    printf("num: ");
    scanf("%d",&num);

    for(i=0;i<10;i++)
    {
        a[i]=num%10;
        num=num/10;
        printf("\na[%d]: %d",i,a[i]);
        n++;
        if(num==0)
            break;
    }


    for(i=0;i<n/2;i++)
    {
        if(a[i]=a[n-1-i])
        {
            cap=0;
            break;
        }
    }

    if(cap==1)
    {
        printf("\nCapicua");
    }
    else
    {
        printf("\nNao e capicua");
    }
}
