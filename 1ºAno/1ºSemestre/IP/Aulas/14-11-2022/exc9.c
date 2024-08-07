#include <stdio.h>
int arredonda(float n1,float n2)
{
    float media=(n1+n2)/2;
    int media_arredondada;
    if(media-(int)media>=0.5)
        return((int)media+1);
    else
        return((int)media);
}
void main()
{
    int media;
    float n1,n2;
    printf("N1: ");
    scanf("%f",&n1);
    printf("N2: ");
    scanf("%f",&n2);

    printf("\nMedia= %d",arredonda(n1,n2));
}
