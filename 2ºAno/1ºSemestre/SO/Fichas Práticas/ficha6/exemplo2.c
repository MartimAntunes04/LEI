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


typedef struct{
    int trinco;
    char mensagem[20];
    pthread_mutex_t *m;  //variavel mutex(partilha)
}DADOS;

void *minhafuncao(void *dados){

    DADOS *pdados = (DADOS *)dados;
    
    pthread_mutex_lock(pdados->m);

    pthread_mutex_unlock(pdados->m);

    pthread_exit(NULL);

}


int main(){

    pthread_t threadID[2];
    DADOS dados[2];
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,  NULL);
    dados[0].m = &mutex;
    dados[1].m = &mutex;


    for(int i=0;i<2;i++){
    pthread_create(&threadID[i],NULL,&minhafuncao,&dados[i]);
    }

    
    for(int i=0;i<2;i++){
        pthread_join(threadID[i],NULL); 
    }
    pthread_mutex_unlock(&mutex);
    
}