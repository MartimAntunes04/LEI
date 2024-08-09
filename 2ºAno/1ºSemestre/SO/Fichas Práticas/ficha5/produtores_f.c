#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#define SERVER_FIFO "SERVERFIFO"
#define CLIENTE_FIFO "CLIENTE%d"
char CLIENT_FIFO_FINAL[100];
typedef struct
{
    pid_t pid;
    char texto[100];
} dataMSG;

void termina(int s, siginfo_t *i, void *v)
{
    sprintf(CLIENT_FIFO_FINAL, CLIENTE_FIFO, getpid());
    unlink(CLIENT_FIFO_FINAL);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = termina;
    sigaction(SIGINT, &sa, NULL);
    dataMSG msg;
    msg.pid = getpid();
    sprintf(CLIENT_FIFO_FINAL, CLIENTE_FIFO, getpid());
    mkfifo(CLIENT_FIFO_FINAL, 0666);
    char msgRespostas[100];

    int fd_fifo = open(SERVER_FIFO, O_WRONLY);
    if (fd_fifo == -1)
    {
        printf("Erro abrir o fifo do eco, ou o eco não esta a correr");
        return -1;
    }
    while (1)
    {
        printf("introduza a mensagem que quer enviar ao eco:");
        fgets(msg.texto, sizeof(msg.texto), stdin);

        int sizew = write(fd_fifo, &msg, sizeof(msg));
        // espera pela mensagem
        int fd_cliente_recebe = open(CLIENT_FIFO_FINAL, O_RDONLY);
        int sizer = read(fd_cliente_recebe, &msgRespostas, 100);
        if (sizer > 0)
            printf("\n Recebi o eco [%s]", msgRespostas);
        close(fd_cliente_recebe);
        if (strcmp(msgRespostas, "termina\n") == 0)
        {
            close(fd_fifo);
            unlink(CLIENT_FIFO_FINAL);
            return 1;
        }
    }
}