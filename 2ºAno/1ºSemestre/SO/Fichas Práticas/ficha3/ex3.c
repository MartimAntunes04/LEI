#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){
setbuf(stdout,NULL);
	if(argc !=3 ){

		printf("\nErro argumento");
		return -1;
	}
	int n = atoi(argv[1]);
	int s = atoi (argv[2]);
	for(int i=0;i<n;i++){
		printf(" * ");
		fflush(stdout);
		sleep(s);
	}

return 0;
}
