#include <stdio.h>
#include <stdlib.h>

int main(){

	char * nomevariavel="PATH";
	char * valorvariavel=getenv(nomevariavel);

	if(valorvariavel!=NULL){
		printf("Variavel ambiente %s tem valor %s",nomevariavel,valorvariavel);
	}	
return 0;
}
