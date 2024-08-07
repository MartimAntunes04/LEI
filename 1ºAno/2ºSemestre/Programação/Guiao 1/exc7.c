#include <stdio.h>

void procuraDupla(int tab[],int tam,int *m,int *s)
{
    int i;

    if(tab[0]>tab[1]){
        *m=tab[0];
        *s=tab[1];
    }
    else{
        *m=tab[1];
        *s=tab[0];
    }

    for(i=2;i<tam;i++)
    {
        if(tab[i]>*m){
            *s=*m;
            *m=tab[i];}

        else if(tab[i]>*s)
            *s=tab[i];
    }
}

int main()
{
    int tab[8]={-41,-7,-2,-4,-5,-8,-10,-1};
    int m,s;

    procuraDupla(tab,8,&m,&s);
    printf("Maior:%d \n Segundo Maior:%d",m,s);
}
