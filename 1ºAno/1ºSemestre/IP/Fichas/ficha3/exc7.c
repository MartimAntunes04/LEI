#include <stdio.h>
void main()
{

int tipo,idade,imposto;

printf("Tipo do veiculo: ");
scanf("%d",&tipo);
printf("Idade do veiculo: ");
scanf("%d",&idade);
switch (tipo)
{
case 1:

        if(idade>=5)
        {
            printf("Imposto a pagar=25€");
        }
        else
        {
            printf("Imposto a pagar=45€");
        }
        break;

case 2:
        if(idade>=5)
        {
          printf("Imposto a pagar=50€");
        }
        else
        {
            printf("Imposto a pagar=125€");
        }
        break;
case 3:
        if (idade>=5)
        {
            printf("Imposto a pagar=75€");
        }
        else
        {
            printf("Imposto a pagar=150€");
        }
        break;
case 4:
        if (idade>=5)
        {
            printf("Imposto a pagar=150€");
        }
        else
        {
            printf("Imposto a pagar=250€");
        }
default:
{
printf("veiculo invalido");
}








}





}
