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

#define P_ESQ "p_esq"
#define P_DIR "p_dir"
#define ENVIA "envia%d"

typedef struct{
    char fifo[20];
    int stop;
}DADOS;

int listaclientes[10]={0};

typedef struct{
    char nome[20];
    int val;
}MSG;


typedef struct{
    char msg[50];
    int idMsg;
}MSG2;

int adicionacliente(int pid) {
    for (int i = 0; i < 10; i++) {
        if (listaclientes[i] == pid) {
            // ja existe
            return 1;
        }
    }

    // Client nao existe,adicioanar
    for (int i = 0; i < 10; i++) {
        if (listaclientes[i] == 0) {
            listaclientes[i] = pid;
            return 2; // Successfully added the client
        }
    }

    // If the list is full, you might want to handle this case appropriately
    return 3; // Error: List is full
}




void *escuta(void *dados){

    DADOS *pdados = (DADOS *)dados;
    int fd=open(pdados->fifo,O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o pipe");
        exit(EXIT_FAILURE);
    }
     MSG msg;
    do{

        fgets(buffer,sizeof(buffer),stdin);
        

        int sizeEsq = read(fd,&msg,sizeof(msg));
        if(sizeEsq == sizeof(msg)){
        if(strcmp(pdados->fifo,P_ESQ)==0)
        {
            printf("ESQUERDO- Nome:%s,Valor:%d\n",msg.nome,msg.val);
        }
        else if(strcmp(pdados->fifo,P_DIR)==0)
        {
            printf("Direito- Nome:%s,Valor:%d\n ",msg.nome,msg.val);
            fflush(stdout);
        }
        }
    }while(pdados->stop);
    close(fd);
    pthread_exit(NULL);
}


void fim(int s,){
    unlink(P_DIR);
    unlink(P_DIR);
    exit(1);
}

void desbloq(int s,siginfo_t *info,void *c)



int main(){

     struct sigaction act;
    act.sa_sigaction = fim;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT,&act,NULL);


    struct sigaction act1;
    act1.sa_sigaction = desbloq;
    act1.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&act1,NULL);


    setbuf(stdout,NULL);
    mkfifo(P_ESQ, 0666);
    mkfifo(P_DIR, 0666);
    char buffer[100];
    char fifo[100];
     pthread_t t[2];
    MSG2 MSGenvio;
    MSGenvio.idMsg=1;

    DADOS dadosEnviar[2];
    dadosEnviar[0].stop=1;  //thread a
    strcpy(dadosEnviar[0].fifo, P_ESQ);
    dadosEnviar[1].stop = 1;  //thread b
    strcpy(dadosEnviar[1].fifo , P_DIR);

     for(int j=0;j<2;j++){
        if(pthread_create(&t[0],NULL,&escuta,&dadosEnviar[j])!=0)
        return -1;
    }


    do{
        
        fgets(buffer,sizeof(buffer),stdin);
        

        
        if(strcmp(buffer,"sair")==0){
         
            for(int i=0;i<10;i++){
                if(listaclientes[i]!=0)
                {
                    printf("\n--end do pid %d\n",listaclientes[i]);
                    sprintf(fifo,ENVIA,listaclientes[i]);
                    int fd=open(fifo,O_RDWR);
                    int size=write(fd,&MSGenvio,sizeof(MSGenvio));
                    close(fd);
                }
            }
            dadosEnviar[0].stop=0;   //thread a
           dadosEnviar[1].stop = 0; //thread b
            pthread_kill(t[0],SIGUSR1);  //so pa desbloquear
            pthread_kill(t[1],SIGUSR1);
        }
        

    }while(thDados[0].stop);
    for(int j=0;j<2;j++)
        pthread_join(t[j],NULL);
    printf("\nadeus");



unlink(P_ESQ);
unlink(P_DIR);

}