#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_funcSignal(int signum,siginfo_t *info, void * secret)
{
	printf("\n[SINAL - %d]\n]",signum);
}

int main(){

	int i;
	printf("PID[%d]\n",getpid());
	struct sigaction sa;
	sa.sa_sigaction = handler_funcSignal;
	sigaction(SIGINT,&sa,NULL);

	scanf("%d",i);

}

