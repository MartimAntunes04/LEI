#include <stdio.h>

void mostra(char *nomeFicheiro){
    int c;
    FILE *f;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro");
    }
    while(fread(&c,sizeof (int),1,f)==1)
        printf("%d\n",c);
    fclose(f);
}

void calcula(char *nomeFicheiro,int *soma,float *media){
    FILE *f;
    int c;
    int contador=0;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL)
        printf("Erro");
    while(fread(&c,sizeof (int),1,f)==1){
        *soma+=c;
        contador++;
    }
    if (contador > 0) {
        *media = *soma / contador;
    } else {
        *media = 0;
    }

}



int main() {
    int soma;
    float media;

    mostra("valoresEx2.bin");
    calcula("valoresEx3.bin",&soma,&media);
    printf("Soma=%d",soma);
    printf("Media=%f",media);
    return 0;
}
