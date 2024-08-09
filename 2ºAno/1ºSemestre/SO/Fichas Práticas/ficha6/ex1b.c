#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>

void acorda(int s,siginfo_t *info,void *t){}
typedef struct{
    char tipo;
    char stop;
    pthread_mutex_t *m;
    
}TDADOS;


void imprime(char simb,int numeroVezes){
    for(int m=0;m<numeroVezes;m++){
        printf("%c",simb);
        fflush(stdout);
        sleep(1);
    }
}

void *tarefa(void *dados){
    TDADOS *pdados = (TDADOS *)dados;
    do{
        srand(time(0));
        int t =rand( ) % (1-5);
        imprime('.',t);

        pthread_mutex_lock(pdados->m); //INICIO DA ZONA CRITICA

        imprime(pdados->tipo,3),

        pthread_mutex_unlock(pdados->m);  //FIM DA ZONA CRITICA

    }while(pdados->stop);
    pthread_exit(NULL);
}






int main(){
    struct sigaction act;
    act.sa_sigaction = acorda;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&act,NULL);
    printf("Bem vindo - Introduza 'sair' para terminar o programa\n");
    char buffer[20];
    pthread_t t[2];
    TDADOS dadosEnviar[2];
    pthread_mutex_t mutex;
    dadosEnviar[0].m=&mutex;
    dadosEnviar[1].m=&mutex;
    pthread_mutex_init(&mutex,NULL);
    dadosEnviar[0].stop=1;  //thread a
    dadosEnviar[0].tipo= 'A';
    dadosEnviar[1].stop = 1;  //thread b
    dadosEnviar[1].tipo = 'B';

    for(int j=0;j<2;j++){
        if(pthread_create(&t[j],NULL,&tarefa,&dadosEnviar[j])!=0)
        return -1;
    }

    do{
        scanf("%s",buffer);
        if(strcmp(buffer,"sair")==0){
            dadosEnviar[0].stop=0;   //thread a
            dadosEnviar[1].stop = 0; //thread b
            pthread_kill(t[0],SIGUSR1);  //so pa desbloquear
        }
        else{
            printf("Comando invalido");
        }

    }while(strcmp(buffer,"sair")!=0);
    for(int j=0;j<2;j++)
        pthread_join(t[j],NULL);
    pthread_mutex_destroy(&mutex);
    printf("\nadeus");

}