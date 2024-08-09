#include <stdio.h>
int main(){
int numero;
char string[20];

printf("Digite um numero: ");
scanf("%d",&numero);

printf("\nNumero ao quadrado:%d ",numero*numero);

printf("\nDigite uns caracteres: ");
scanf("%s",string);
return 0;
}
