#include <stdio.h>
int Verificalimite(int num,int lim_inf,int lim_sup)
{
     if(num>=lim_inf&&num<=lim_sup)
        return 1;
     else
        return 0;
}

void main()
{
    int num,lim_inf,lim_sup;
    printf("Numero: ");
    scanf("%d",&num);
    printf("Limite Inferior: ");
    scanf("%d",&lim_inf);
    printf("Limite Superior: ");
    scanf("%d",&lim_sup);
    if(Verificalimite(num,lim_inf,lim_sup))
    {
        printf("No intervalo");
    }
    else
    {
        printf("Fora");
    }

}
