#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct paciente pac,*ppac;
struct paciente{
    char nome[100];
    ppac prox;
};

ppac adiciona(ppac p){
    ppac novo,aux;

    novo=malloc(sizeof(pac));
    if(novo==NULL)
        return p;
    else{
        printf("Nome: ");
        scanf("%s",novo->nome);
        novo->prox=NULL;
    }


    if(p==NULL){
        p=novo;
    }
    else{
        aux=p;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        novo=aux->prox;
    }
    return p;
}


void visualiza(ppac p){
    ppac aux=p;
    while(aux!=NULL){
        printf("Nome: %s",aux->nome);
        aux=aux->prox;
    }

}



ppac elimina(ppac p){

    char nome_paciente[100];
    ppac atual=p,ant=NULL;
    printf("Nome do paciente: ");
    scanf("%s",nome_paciente);

    while(atual!=NULL && strcmp(nome_paciente,atual->nome)!=0){
        ant=atual;
        atual=atual->prox;
    }
    if(atual==NULL)
        return p;
    if(ant==NULL){
        p=atual->prox;
    }
    else{
        ant->prox=atual->prox;
    }
    free(atual);
return p;
}





int main() {
    ppac tab=NULL;
    int i;

    for(i=0;i<2;i++){
        tab= adiciona(tab);
    }
    tab= elimina(tab);
    visualiza(tab);
}
