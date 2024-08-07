#include <stdio.h>
int verifica (int sup, int inf, int num)
{
    if (num>=inf && num<=sup)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
void main()
{
    int num,sup,inf;
    printf("num: ");
    scanf ("%d",&num);
    printf ("inf: ");
    scanf("%d",&inf);
    printf("sup: ");
    scanf ("%d",&sup);


printf ("%d",verifica(sup,inf,num));


}
