#include <stdio.h>
void main()
{

float freq1,freq2,trabalho,nota_final;

printf("Nota obtida na 1 frequencia de 0-20: ");
scanf("%f",&freq1);
fflush(stdin);
printf("Nota obtida na 2 frequencia de 0-20: ");
scanf("%f",&freq2);
printf("Nota obtida no trabalho de 0-20: ");
scanf("%f",&trabalho);

nota_final=(freq1*0.40)+(freq2*0.40)+(trabalho*0.20);

printf("nota final: %.2f\n",nota_final);

}
