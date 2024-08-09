#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

//union sigval{
 //   int sival_int;
//    void *sival_ptr;
//}

void recebe(int s,siginfo_t *i,void*t){
    int n=i->si_value,sival_int;
    if(n==1)
        printf("Resposta [%d] - Demasiado Grande\n"i->si_pid);
    else if(n==2)
        printf("Resposta [%d] - Demasiado pequeno\n",i->si_pid);
    else if(n==3)
        printf("Resposta [%d] - Acertou\n",i->si_pid);
}


int main(int argc,char*argv[]){
    
    //c
    //int id=fork();
    //if(id>0)
    //    exit(1);

    int pid;
    printf("O meu pid é [%d]",getpid());
    printf("\nuqual o pid do sorteia?\n");
    scanf("%d",&pid);
    union sigval val;
    struct sigaction sa;
    sa.sa_sigaction=recebe;
    sa.sa_flags=SA_RESTART || SA_SIGINFO;
    sigaction(SIGUSR1,&sa,NULL);

    //val.sival_int=50
    do{
        printf("\nqual o numero\n");
        scanf("%d",&val.sival_int);
        sigqueue(pid,SIGUSR1,val);
    }while(1);



}