#include <stdio.h>

void troca(float *a,float *b,float *c)
{
    float x;

    x=*a;
    *a=*c;
    *c=*b;
    *b=x;


}

void main()
{
    float x=1.0,y=2.0,z=3.0;

    troca(&x,&y,&z);
    printf("x=%f\n y=%f\n z=%f",x,y,z);
}
