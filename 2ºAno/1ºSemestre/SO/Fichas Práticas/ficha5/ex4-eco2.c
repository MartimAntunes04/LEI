#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/select.h>

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

int main()
{
    setbuf(stdout, NULL);
    struct sigaction sa;
    sa.sa_handler = sair;
    sigaction(SIGINT, &sa, NULL);

    union sigval s;

    int nfd;
    fd_set read_fds;
    struct timeval tv;
    int aux = 0;
    char mensagemRecebida[100];
    mkfifo(PIPEA, 0666);
    mkfifo(PIPEB, 0666);

    int fdRecebe1 = open(PIPEA, O_RDWR);
    int fdRecebe2 = open(PIPEB, O_RDWR);

    do
    {
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(fdRecebe1, &read_fds);
        FD_SET(fdRecebe2, &read_fds);
        int maior = max(fdRecebe1, fdRecebe2) + 1;
        nfd = select(maior, &read_fds, NULL, NULL, &tv);
        //printf("Resposta do select [%d]\n", nfd);
        // TRATO TUDO O QUE É DO TECLADO
        if (FD_ISSET(0, &read_fds))
        {
            fgets(mensagemRecebida, sizeof(mensagemRecebida), stdin);
            printf("\nRecebi do teclado - %s", mensagemRecebida);
            if (strcmp(mensagemRecebida, "sair\n") == 0)
                sigqueue(getpid(), SIGINT, s);
        }
        else if (FD_ISSET(fdRecebe1, &read_fds))
        {
            int size = read(fdRecebe1, &mensagemRecebida, sizeof(mensagemRecebida));
            if (size > 0)
            {
                printf("[PIPE_A] - Recebi a msg: %s\n", mensagemRecebida);
                if (strcmp(mensagemRecebida, "sair\n") == 0)
                    sigqueue(getpid(), SIGINT, s);
            }
        }
        else if (FD_ISSET(fdRecebe2, &read_fds))
        {
            int size = read(fdRecebe2, &mensagemRecebida, sizeof(mensagemRecebida));
            if (size > 0)
            {
                printf("[PIPE_B] - Recebi a msg: %s\n", mensagemRecebida);
                if (strcmp(mensagemRecebida, "sair\n") == 0)
                    sigqueue(getpid(), SIGINT, s);
            }
        }
    } while (1);

    return 0;
}