#include <stdio.h>
int main()
{
float distancia_percorrida,litros_consumidos,velocidade,dura��o;

printf("dura��o: ");
scanf("%f",&dura��o);
printf("velocidade: ");
scanf("%f", &velocidade);

distancia_percorrida=dura��o*velocidade;
litros_consumidos=6,5*distancia_percorrida/100;

printf ("distancia_percorrida: %.2f\n",distancia_percorrida);
printf ("litros_consumidos: %.2f\n", litros_consumidos);

return 0;


}
