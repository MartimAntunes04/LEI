#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){

extern char **environ;
	for(int i=0;environ[i]!=NULL;i++){

		printf("%s",environ[i]);
	}



}
