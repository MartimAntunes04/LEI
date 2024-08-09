#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#define P_ESQ "p_esq"
#define P_DIR "p_dir"


typedef struct{
    char nome[20];
    int val;
}MSG;

void fim(int s,siginfo_t *info,void *c){
    printf("\nAdeus\n");
    exit(1);
}



int main(int argc,char *argv[]){

    struct sigaction act;
    act.sa_sigaction = fim;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT,&act,NULL);
    MSG msg;
    printf("\nIntroduza um nome:\n");
    scanf("%s",msg.nome);
    do{
        printf("Introduza um valor:\n");
        scanf("%d",&msg.val);
        int fd =open(argv[1],O_WRONLY);
        int size = write(fd,&msg,sizeof(msg));
        close(fd);
    }while(1);



}