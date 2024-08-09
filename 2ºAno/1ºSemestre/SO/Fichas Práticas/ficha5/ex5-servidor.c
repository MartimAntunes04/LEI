#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#define SERVER_FIFO "SERVIDOR"
#define CLIENT_FIFO "CLIENTE%d"
char CLIENT_FIFO_FINAL[100];

typedef struct
{
    int num1;
    int num2;
    char operador;
    pid_t pid;
} DATAMSG;

typedef struct
{
    int pidCliente;
    float resultado;
} DATAMSGR;

int listaClientes[100] = {0}; 

int verificaCliente(int pid){
    for (int i=0; i < 100 ; i ++){
        if (pid == listaClientes[i]){
            return 1;
        }
    }
    for (int i=0; i < 100 ; i ++){
        if ( listaClientes[i] == 0){
            listaClientes[i] = pid;
            return 0;
        }
    }
    return 0;
}


void termina(int s, siginfo_t *i, void *v)
{
     for (int i = 0 ; i <100 ; i ++)
         kill(listaClientes[i],SIGINT);
    unlink(SERVER_FIFO);
    printf("\nadeus\n");
    exit(1);
}

int main()
{
     setbuf(stdout,NULL); 
    struct sigaction sa;
    union sigval s;
    sa.sa_sigaction = termina;
    sigaction(SIGINT, &sa, NULL);
    DATAMSG msgRecebida;
    DATAMSGR msgEnviar;
    int nfd;
    fd_set read_fds;
    struct timeval tv;
    char mensagemRecebida[100];

    if (mkfifo(SERVER_FIFO, 0666) == -1)
    {
        if (errno == EEXIST)
        {
            printf("Servidor em execução ou fifo já existe");
        }
        printf("Erro abrir fifo");
        return -1;
    }
    int fdServer = open(SERVER_FIFO, O_RDWR);
    //int fdServer = open(SERVER_FIFO, O_RDONLY);
    printf ("vejam este print para verem diferença do bloqueante e não bloq\n");
    if (fdServer == -1)
        return -2;
    while (1)
    {

        tv.tv_sec = 5;
        tv.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(fdServer,&read_fds);
       
        nfd = select(fdServer+1,&read_fds,NULL,NULL,&tv);
        printf("Time->v%d\n",nfd);
        if(FD_ISSET(0,&read_fds))
        {
            fgets(mensagemRecebida,sizeof(mensagemRecebida),stdin);
            printf("\nRecebi do teclado-%s",mensagemRecebida);
            if(strcmp(mensagemRecebida,"encerra")==0)
                sigqueue(getpid(),SIGINT,s);
        }

        else if(FD_ISSET(fdServer,&read_fds))
        {
            int sizeR = read(fdServer, &msgRecebida, sizeof(msgRecebida));
            if (sizeR > 0)  
        {
            if (msgRecebida.operador == '+')
            {
                msgEnviar.resultado = msgRecebida.num1 + msgRecebida.num2;
                printf("\n [%d]+[%d]=[%f]", msgRecebida.num1, msgRecebida.num2, msgEnviar.resultado );
                int v = verificaCliente(msgRecebida.pid);
         
                sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,listaClientes[i++]);
                int fd_resposta = open (CLIENT_FIFO_FINAL,O_WRONLY);
                write(fd_resposta,&msgEnviar,sizeof(msgEnviar));
                close (fd_resposta);
         
         
            }
            else if (msgRecebida.operador == '.')
            {
                close (fdServer);
                kill(getpid(), SIGINT);
                
            }
        }
        }

        
        
        
    }
}