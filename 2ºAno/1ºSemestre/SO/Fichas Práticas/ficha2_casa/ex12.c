#include <stdio.h>
#include <stdlib.h>

int main(){

	char nomevariavel[100];
	char valorvariavel[100];
	
	printf("Nome da variavel: ");
	scanf("%s",nomevariavel);

	printf("Valor variavel: ");
	scanf("%s",valorvariavel);

	setenv(nomevariavel,valorvariavel,1);
	

	printf("\n%s",getenv(nomevariavel));
	
	return 0;
}
