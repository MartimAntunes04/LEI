#include <stdio.h>
#include <signal.h>

int main(){
	int pid;
	printf("Introduza o pid do process: ");
	scanf("%d",&pid);

	union sigval val;
	val.sival_int=123;
	sigqueue(pid,SIGINT,val);
	
	return 0;

} 
