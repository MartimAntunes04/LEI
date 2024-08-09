
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
    float resultado;
} DATAMSGR;

void termina(int s, siginfo_t *i, void *v)
{

    unlink(CLIENT_FIFO_FINAL);
    printf("\nadeus\n");
    exit(1);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = termina;
    sigaction(SIGINT, &sa, NULL);
    setbuf(stdout, NULL);
    sprintf(CLIENT_FIFO_FINAL, CLIENT_FIFO, getpid());
    mkfifo(CLIENT_FIFO_FINAL, 0666);
    DATAMSG mensagemEnvio;
    DATAMSGR mensagemResposta;
    mensagemEnvio.pid = getpid();
    int fd_envio, fd_resposta;
    int nfd1,nfd2;

    int nfd;
    fd_set read_fds;
    struct timeval tv;



    while (1)
    {
        
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(fdServer,&read_fds);

        nfd1=select(fd_envio+1,&read_fds,NULL,NULL,NULL);
        if(nfd1(0,&read_fds))
        {
            
        }



        printf("introduza o operador\n");
        scanf(" %c", &mensagemEnvio.operador);
        if (mensagemEnvio.operador == '.')
        {
            close(fd_envio);
            unlink(CLIENT_FIFO_FINAL);
            return 1;
        }
        else
        {
            printf("introduza o numero 1\n");
            scanf("%d", &mensagemEnvio.num1);
            printf("introduza o numero 2\n");
            scanf("%d", &mensagemEnvio.num2);
        }

        fd_envio = open(SERVER_FIFO, O_WRONLY | O_NONBLOCK);
        // testarem sem a flag O_NONBLOCK para verem se o program deteta que terminou o servidor
        if (fd_envio == -1)
        {
            printf("Servidor está encerrado");
            return 1;
        }
        int size = write(fd_envio, &mensagemEnvio, sizeof(mensagemEnvio));
        close(fd_envio);

        fd_resposta = open(CLIENT_FIFO_FINAL, O_RDONLY);
        int sizeR = read(fd_resposta, &mensagemResposta, sizeof(mensagemResposta));
        close(fd_resposta);
        printf("\n%d - Resposta[%f]\n", sizeR, mensagemResposta.resultado);
    }
}