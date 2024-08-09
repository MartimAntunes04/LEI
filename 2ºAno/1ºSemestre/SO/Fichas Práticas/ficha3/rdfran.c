#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){

        char* palavraspt[5]={"casa","carro","sol","laranja","livro"};
        char* palavrasfr[5]={"maison","voiture","soleil","orange","livre"};

        if(argc!=1){
                printf("Erro argumentos\n");
                return -1;
        }
        char palavratraduzir[20];
	printf("Digite palavra: ");
	scanf("%s",palavratraduzir);
        int encontra=0;
		for(int i=0;i<5;i++){

                        if(strcmp(palavratraduzir,palavraspt[i])==0){
                                printf("Traducao: %s\n",palavrasfr[i]);
                                encontra=1;
                        }       
                }

                if (!encontra){
                        printf("Traducao:unkown\n");
                }
return 0;
}
