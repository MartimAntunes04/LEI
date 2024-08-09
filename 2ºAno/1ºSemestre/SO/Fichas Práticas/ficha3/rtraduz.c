
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char* argv[]){

        char letra[2],palavra[50];
        int id;
	int fd1[2];
	int erro=pipe(fd1);	


        printf("Letra: ");
        scanf("%s",letra);

	if (strcmp(letra,"x")==0){
		return -1;
	}
	else{
		while(getchar()!='\n');
		printf("Palavra:");
		scanf("%s",palavra); //fgets
		
		}	        

 id=fork();
if(id==0){
	if(strcmp(letra,"i")==0){
		palavra[strlen(palavra)+1]='\n';
		execl("rding","rding",palavra,NULL);
		printf("Erro no execl");
		return -1;
	}
	else if(strcmp(letra,"f")==0){
		close(0);   
		dup(fd1[0]);
		close(fd1[0]);
		close(fd1[1]);
		execl("rdfran","rdfran",NULL); //bot ..
		printf("Erro no execl");
	}
}
else if(id > 0){
	if(strcmp(letra,"f")==0){
		close(fd1[0]);
		printf("\n[%s]\n",palavra);
		int size = write(fd1[1],palavra,strlen(palavra)); //read
		printf("\n enviou-%d\n",size);
	}

}

return 1;
}

