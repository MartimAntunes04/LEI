#include <stdio.h>
void main()
{

    int pai_natais,caixas,ct,soma=0;
    float media;

    printf("Numero de pai Natais da encomenda: ");
    scanf("%d",&pai_natais);

    while(pai_natais>0)
    {
        caixas=pai_natais/10;
        printf("Numero de caixas necessarias: %d",caixas);
        soma+=caixas;
        ct=ct+1;
        printf("\nNumero de pai Natais da encomenda: ");
        scanf("%d",&pai_natais);

    }

    printf("\nResumo da encomenda: ");
    printf("\nNumero total de caixas: %d\n",soma);
    media=soma/ct;
    printf("Media das caixas por encomenda: %.2f\n",media);










}
