//
// Created by ASUS on 25/04/2023.
//
#include <stdio.h>
#include <string.h>
#include "voo.h"

void adicionar_voo(voo tab[],int *total){
    printf("Numero de voo: ");
    scanf("%d",&tab[*total].num);
    printf("Nome da compamhia: ");
    scanf("%s",tab[*total].nome);
    printf("Cidade destino: ");
    scanf("%s",tab[*total].destino);
    (*total)++;
}

void print_voo(voo tab[],int *total){
    int i;
    for(i=0;i<*total;i++){
        printf("\nNumero de voo:%d",tab[i].num);
        printf("\nNome da companhia: %s",tab[i].nome);
        printf("\nCidade destino: %s",tab[i].destino);
    }
}

void elimina_voo(voo tab[],int *total){
    char st[100];
    int i;
    printf("\nNome da companhia que quer eliminar: ");
    scanf("%s",st);

    for(i=0;i<*total && strcmp(st,tab[i].nome)!=0;i++){
        if(i==*total){
            printf("Essa companhia nao existe");
        }
        else{
            printf("Companhia eliminada");
            tab[i]=tab[*total-1];
            (*total)--;

        }
    }
}