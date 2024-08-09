#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

#define PIPEA "PIPE_A"
#define PIPEB "PIPE_B"


int max(int a, int b)
{
    return (a > b) ? a : b;
}

void sair(int signal)
{
    unlink(PIPEA);
    unlink(PIPEB);
    exit(1);
}


int main(){


    setbuf(stdout, NULL);
    struct sigaction sa;
    sa.sa_handler = sair;
    sigaction(SIGINT, &sa, NULL);

    union sigval s;

    int fd_envio;
    char mensagemEnvio[100];

    while(1){
        printf("Introduza uma string: ");
        fgets(mensagemEnvio,sizeof(mensagemEnvio),stdin);
    

    fd_envio=open(PIPEA,O_WRONLY);
    if (fd_envio == -1)
        {
            printf("Servidor está encerrado");
            return 1;
        }

    int sizew=write(fd_envio,&mensagemEnvio,sizeof(mensagemEnvio));
    close(fd_envio);
}

}