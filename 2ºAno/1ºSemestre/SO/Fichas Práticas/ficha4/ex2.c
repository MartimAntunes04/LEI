#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int n=20;
int pontuacao=0;
int perdeu=0;


void jogo(){
	srand(time(NULL));
	int num1 = rand()%100;
	int num2 = rand()%100;
	int soma = num1 + num2, somaUser;
	n--;
	printf("\nIntroduza o valor da conta:[%d] + [%d]\n",num1,num2);
	if(scanf("%d",&somaUser)!=1)
	{
		perror("Nao introduzio nada-PERDER");
	}
	if(soma==somaUser)
	{
	pontuacao++;
	printf("Acertou e tem [%d] pontos\n",pontuacao);
	}
	else{
		printf("Perdeu\n");
		if(++perdeu ==2)
			exit(1);
		else
			printf("\n tem mais uma tentativa");
	}


}



void handle_sigalrm(int s,siginfo_t *i,void*v){

	printf("\nAcabou o tempo- PERDEU\n");
	exit(1);
}

int main(){

	int i=0;
	struct sigaction sa;
	sa.sa_sigaction = handle_sigalrm;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGALRM,&sa, NULL);
	while(1){
		if(i==5)
			exit(1);
		else
		{
			alarm(n);
			jogo(); 
		}
		i++;
	}
}

