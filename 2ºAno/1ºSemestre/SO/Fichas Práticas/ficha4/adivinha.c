#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>



//union sigval{
 //   int sival_int;
//    void *sival_ptr;
//}

int main(int argc,char*argv[]){

    int pid;
    printf("O meu pid é [%d]",getpid());
    printf("\nuqual o pid do sorteia?\n");
    scanf("%d",&pid);
    union sigval val;

    //val.sival_int=50
    do{
        printf("\nqual o numero\n");
        scanf("%d",&val.sival_int);
        sigqueue(pid,SIGUSR1,val);
    }while(1);

}


//TERMINAR O BOT
//id=fork;
//if(id>0){
    //sigqueue(pid(bot)id,SIGINT,NULL);
//}
