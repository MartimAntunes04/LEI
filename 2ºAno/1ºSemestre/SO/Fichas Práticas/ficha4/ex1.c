#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int contador=0;
void funcSignal(int signum,siginfo_t *info,void *secret){
	printf("\nAi!!\n");
	if(++contador==5){
		printf("\n ok,pronto\n");
		exit(1);
	}


}


int main(){

char nome[50];
struct sigaction sa;
	sa.sa_sigaction = funcSignal;

	sigaction (SIGINT,&sa,NULL);
	
	while(1){
	
	fgets(nome,50,stdin);
	nome[strlen(nome)-1]='\0';
	if(strcmp(nome,"sair")==0)
		return 1;
	else
		printf("\nnome-introduzido:%s\n",nome);

	}
	return -1;
	
}

