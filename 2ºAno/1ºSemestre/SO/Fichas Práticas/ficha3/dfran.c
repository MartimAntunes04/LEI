#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){

        char palavraspt[][20]={"casa","carro","sol","laranja","livro"};
        char palavrasfr[][20]={"maison","voiture","soleil","orange","livre"};

        if(argc!=2){
                printf("Erro argumentos\n");
                return -1;
        }
        char* palavratraduzir=argv[1];  
        int encontra=0;
		for(int i=0;i<sizeof(palavraspt)/sizeof(palavraspt[0]);i++){

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
