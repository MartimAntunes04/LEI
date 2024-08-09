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
}DADOS;

void *minhafuncao(void *dados){

    DADOS *pdados = (DADOS *)dados;
    while(pdados->trinco){
        printf("[%s]\n",pdados->mensagem);
        sleep(7);
    }
    pthread_exit(NULL);

}


int main(){

    pthread_t threadID[2];
    DADOS dados[2];
    dados[0].trinco=1;
    dados[1].trinco = 1;
    strcpy(dados[0].mensagem,"Ola da thread 1");
    strcpy(dados[1].mensagem,"Ola da thread 2");

    for(int i=0;i<2;i++){
    pthread_create(&threadID[i],NULL,&minhafuncao,&dados[i]);
    }

    char ola;
    printf("\nEstou aqui parado, na thread principal\n");
    scanf("%c",&ola);
    dados[0].trinco=0;
    dados[1].trinco=0;
    for(int i=0;i<2;i++){
        pthread_join(threadID[i],NULL); 
    }
    pthread_exit(NULL);
    
}