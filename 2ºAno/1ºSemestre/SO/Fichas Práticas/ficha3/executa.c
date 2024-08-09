#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){

	char caracteres[100];
	printf("Digite caracteres: ");
	scanf("%s",caracteres);	
		if(strcmp(caracteres,"port")==0){
			execl("ls","ls",NULL);
		}

		else if(strcmp(caracteres,"ing")==0){
			execl("ls","ls",NULL);
		}

		printf("\nMissao cumprida\n");

return 0;
}
