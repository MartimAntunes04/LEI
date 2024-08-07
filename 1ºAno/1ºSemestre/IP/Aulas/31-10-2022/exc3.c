#include <stdio.h>
void main()
{

    int na=0,nn=0,nt=0;
    char tipo;
    float preco,precoSIVA, precoCIVA;

    printf("\nPreco produto: ");
    scanf("%f",&preco);

    while (preco>0)
    {
        printf("Tipo de produto: ");
        fflush(stdin);
        scanf("%c",&tipo);

        while(tipo!='a' && tipo!='n')
        {
            printf("Tipo de produto: ");
            fflush(stdin);
            scanf("%c",&tipo);
        }
        precoSIVA=precoSIVA+preco;
        nt++;

        switch(tipo)
        {
        case 'a':
            na++;
            nt++;
            precoCIVA+=preco*1.06;
            break;
        case 'n':
            nn++;
            nt++;
            precoCIVA+=preco*1.23;
            break;

        }
        printf("\nPreco produto: ");
        scanf("%f",&preco);
    }


    printf("Total produtos alimentares: %d\n",na);
    printf("Total produtos nao alimentares: %d\n",nn);
    printf("Total produtos: %d\n",nt);
    printf("Preco sem IVA: %.2f\n",precoSIVA);
    printf("Preco com IVA: %.2f\n",precoCIVA);



}






