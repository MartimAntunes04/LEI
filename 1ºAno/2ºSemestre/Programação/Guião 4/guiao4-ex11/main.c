#include <stdio.h>


void mostra(char *nomeFicheiro){
    FILE *f;
    int c;

    f=fopen(nomeFicheiro,"r");
    if(f==NULL) {
        printf("Erro");
        return;
    }
    while((c=fgetc(f))!=EOF)
        putchar(c);
}

void fevereiro_4(char *nomeFicheiro){
    FILE *f;
    float minima,maxima;
    int dia;


    f=fopen(nomeFicheiro,"r");
    if(f==NULL){
        printf("Erro");
        return;
    }
    for(int i=1;i<4;i++){
        fscanf(f,"%f",&minima);
        fscanf(f,"%f",&maxima);
    }
    fscanf(f,"%f",&minima);
    fscanf(f,"%f",&maxima);

    printf("Temperatura minima 4 fevereiro: %f\n",minima);
    printf("Temperatura maxima 4 fevereiro: %f",maxima);


    fclose(f);

}

void mostra_bin(char *nomeFicheiro){
    FILE *f;
    float c;

    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro");
        return;
    }
    while(fread(&c,sizeof (float),1,f)==1){
        printf("%f\n",c);
    }
    fclose(f);
}

void fevereiro_4_bin(char *nomeFicheiro){
    FILE *f;
    float minima,maxima,c;

    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro");
        return;
    }
    while(fread(&c,sizeof (float),1,f)==1){
        for(int i=1;i<4;i++){
            fread(&minima,sizeof (float),1,f);
            fread(&maxima,sizeof (float),1,f);
        }
        fread(&minima,sizeof(float),1,f);
        fread(&maxima,sizeof(float),2,f);

        printf("%f",minima);
        printf("%f",maxima);
    }
    fclose(f);
}



int main() {

    //mostra("temperaturas_ex11.txt");
    //fevereiro_4("temperaturas_ex11.txt");

    //mostra_bin("temperaturas_ex11.bin");
    fevereiro_4_bin("temperaturas_ex11.bin");
    return 0;
}
