#include <stdio.h>
void main()
{

    float valor,valor_anterior,soma=0,media;
    int n=0;

    printf("valor: ");
    scanf("%f",&valor);
    valor_anterior=valor;
    while(valor>=valor_anterior)
    {

        soma+=valor;
        n=n+1;
        valor_anterior=valor;
        printf("valor: ");
        scanf("%f",&valor);
    }
    media=soma/n;
    printf("soma: %.2f\n",soma);
    printf("media: %.2f\n",media);




}
