//
// Created by ASUS on 18/05/2023.
//
#include <stdio.h>
#include "exc2.h"

void printVals(char *nome) {
    FILE *f;
    int p;
    f = fopen(nome, "rb");
    if (f == NULL) {
        printf("Erro ao acesso ao ficheiro");
        return;
    }
    while (fread(&p, sizeof(int), 1, f) == 1)
        printf("%d\n", p);
    fclose(f);

}

void calcula(char *nome,int *soma,float *media){
    FILE *f;
    int conta=0;
    int p;
    f=fopen(nome,"rb");
    while(fread(&p,sizeof (int),1,f)==1){
        soma+=p;
        conta++;
        *media=*soma/conta;
    }

    fclose(f);


}

