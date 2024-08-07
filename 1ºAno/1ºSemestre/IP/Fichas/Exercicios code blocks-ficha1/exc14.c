#include <stdio.h>
void main()
{

    char tipo;
    float preco, precoCIVA;

    printf("Introduza o preco: ");
    scanf("%f",&preco);
    fflush(stdin);



    printf("\nIntroduza o tipo de produto: ");
    scanf("%c",&tipo);




    switch (tipo)
    {
    case 'b':
        precoCIVA=preco*1.05;

        break;

    case 'p':
        precoCIVA=preco*1.30;

        break;

    case 'o':
        precoCIVA=preco*1.20;

        break;
    default:
        printf("Produto invalido");



    }
printf("\nPreco final: %.2f",precoCIVA);


}





