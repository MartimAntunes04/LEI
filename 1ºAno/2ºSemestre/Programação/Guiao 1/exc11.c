#include <stdio.h>
#include <string.h>

int vetores_iguais(int v1[],int tam1,int v2[],int tam2)
{
    int i;
    if(tam1==tam2)
    {
        return 1;
    }
    for(i=0;v1[i]<tam1;i++)
    {
        if(v1[i]==v2[i])
            return 1;
    }
return 0;
}
void main()
{
    int v1[5]={1,2,3,4,8},v2[3]={5,6,7};

    printf("%d",vetores_iguais(v1,5,v2,3));



}
