#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>


//MOTOR

#define SERVER_FIFO "SERVERFIFO"
#define CLIENTE_FIFO "CLIENTE%d"
char CLIENT_FIFO_FINAL[100];
int listaClientes[100]; // melhorar


typedef struct {
    pid_t pid;
    char texto[100];
    int mapa[10][20];
    char login[100];
    int cordenadatexto;
    int id_MSG  //1 apaanhar o campo login , 2 login texto
}  dataMSG; 

void termina(int s, siginfo_t *i, void *v){
    unlink (SERVER_FIFO);
    printf("\nadeus\n");
    for (int i = 0 ; i <100 ; i ++)
         kill(listaClientes[i],SIGINT);
    exit (1);
  
}

int main(){
    int size;
    int i=0;
    dataMSG msg;
    union sigval dados;
    
    struct sigaction sa;
    sa.sa_sigaction = termina;
    sigaction (SIGINT,&sa,NULL);
    

    if (mkfifo (SERVER_FIFO,0666) == -1 ) {
        perror ("Erro a abrir fifo ou fifo já existe");
        return -1;
    }

    int fd_Server_Fifo = open (SERVER_FIFO,O_RDONLY);
    if (fd_Server_Fifo == -1 ){
        perror ("Erro a abrir fifo ");
        return -1;
    }

    while (1){
        size = read(fd_Server_Fifo,&msg,sizeof(msg));
        if (size > 0){ 
            printf ("Recebi a msg [%s] com o tamanho [%d]\n",msg.texto,size);
            listaClientes[i++] = msg.pid; // não está preparado para ter pids unicos e apagar quando sai um produtor
            if (strcmp(msg.texto,"sair\n")==0){
                close (fd_Server_Fifo);
                sigqueue(getpid(), SIGINT, dados);
            }
            //devolver a msg
           sprintf (CLIENT_FIFO_FINAL,CLIENTE_FIFO,msg.pid);
           int fd_client_Fifo = open (CLIENT_FIFO_FINAL,O_WRONLY);
           write (fd_client_Fifo,&msg.texto,sizeof(msg.texto));
           close (fd_client_Fifo);
        }
    }
}
