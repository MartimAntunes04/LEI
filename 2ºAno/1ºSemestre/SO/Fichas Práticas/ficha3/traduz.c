#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char* argv[]){

	char letra[2],caracteres[50];
	int res;
	
	printf("Letra: ");
	scanf("%s",letra);

	if(strcmp(letra,"x")==0){
		return -1;
	}
	else if (strcmp(letra,"i")==0){
		printf("Palavra: ");
		scanf("%s",caracteres);
		res=fork();
		if(res==0){	
			execl("ding","ding",caracteres,NULL);
		}

	}
	else if (strcmp(letra,"f")==0){
		printf("Palavra: ");
		scanf("%s",caracteres);
		res=fork();
		if(res==0){
			execl("dfran","dfran",caracteres,NULL);
		}
	}		

return 0;
}
