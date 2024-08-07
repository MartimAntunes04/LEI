//
// Created by ASUS on 27/04/2023.
//
#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <string.h>






pno adiciona(pno p){
    pno novo,aux;
    novo=malloc(sizeof(no));
    if(novo==NULL)
        return p;

        printf("Dados: Nome-ID PESO ALTURA");
        scanf("%s %d %f %f",novo->nome,&novo->id,&novo->peso,&novo->altura);

        novo->prox=NULL;
        if(p==NULL)
            p=novo;

        else{
            aux=p;
            while(aux->prox!=NULL) {
                aux = aux->prox;
            }
            aux->prox=novo;
        }


    return p;
}

void listarTudo(pno p){
    pno aux;
    aux=p;
    while(aux!=NULL){
        printf("%d:%s-%.2f %.2f\n",aux->id,aux->nome,aux->peso,aux->altura);
        aux=aux->prox;
    }
}

pno elimina(pno p,int x){
    int i;
    pno atual=p,ant=NULL;
    while(atual!=NULL && atual->id!=x){
        ant=atual;
        atual=atual->prox;
    }
    if(atual==NULL)
        return p;
    if(ant==NULL)
        p=atual->prox;
    else{
        ant->prox = atual->prox;
    }
    free(atual);
    return p;

}