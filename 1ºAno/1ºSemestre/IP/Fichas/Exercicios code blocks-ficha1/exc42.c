#include <stdio.h>
int CalculaArea (float c,float l)
{
    return (c*l);
}

void main()
{
    int divisoes, i=1;
    float c,l,area;

    printf ("Numero de divisoes: ");
    scanf("%d",&divisoes);

    while (divisoes<i)
    {
        printf ("Comprimnento: ");
        scanf("%f",&c);
        printf("Largura: ");
        scanf("%f",&l);
        i++;
        area=CalculaArea(c,l);
        printf (" A divisao %d tem de area= %f",i,area);



    }


}
