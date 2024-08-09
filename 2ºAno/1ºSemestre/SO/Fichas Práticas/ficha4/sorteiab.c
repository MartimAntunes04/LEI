#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int num1;
int numAdivinha=0;

void sair(int s){
    printf("Adeus....Adivinhou [%d]\n",numAdivinha);
    exit(1);
}

void sorteia(){
    srand(time(NULL));
    num1 = rand() % 100;
}

void jogo(int s,siginfo_t *i,void*v){
     
     int n=i->si_value.sival_int;
     int aux=9
    if(n>num1){
        aux=1:
        printf("Resposta [%d] - Demasiado Grande\n",i->si_pid);
    }
    else if(n< num1){
        aux=2;
        printf("Resposta [%d] - Demasiado Pequeno\n",i->si_pid);
    }
    else if(n==num1){
        aux=3;
        numAdivinha++;
        printf("Resposta [%d] -Acertou\n ",i->si_pid);
        sorteia();
    }

    union sigval val;
    val.sival_int=aux;
    sigqueue(i->si_pid,SIGUSR1,val);


}
int main(int argc,char*argv[]){

    setbuf(stdout,NULL);

    struct sigaction sa;  //SINAL USR1
    sa.sa_flags=SA_RESTART | SA_SIGINFO; //INICIALIZAR AS flags
    sa.sa_sigaction=jogo;         //registar as funcoes
    sigaction(SIGUSR1,&sa,NULL);
    
    struct sigaction sac;  //SINAL CRLC
    sa.sa_handler = sair;
    sigaction (SIGINT,&sac,NULL);
    printf("[%d]",getpid());
    sorteia();

    do{

    }while(1);

}