//
// Created by ASUS on 25/04/2023.
//
#include <stdio.h>
#include <string.h>
#include "pizza.h"

void adiciona_pizza(pizza tab[],int *total){
    printf("Nome: ");
    scanf("%s",tab[*total].nome);
    printf("Tempo de cozedura: ");
    scanf("%d",&tab[*total].tempo);
    printf("Preco: ");
    scanf("%d",&tab[*total].preço);
    (*total)++;
}

void print_pizza(pizza tab[],int *total){
    int i;
    for(i=0;i<*total;i++){
        printf("\nNome:%s",tab[i].nome);
        printf("\nTempo: %d",tab[i].tempo);
        printf("\nPreco: %d",tab[i].preço);
    }
}

void atualiza_preco(pizza tab[],int *total,int preco){
    int i;
    for(i=0;i<*total;i++){
        if(tab[i].tempo==1){
            tab[i].preço=preco;
        }

    }
}

void tempo_pizza(pizza tab[],int *total,int tempo){
    int i;
    for(i=0;i<*total;i++){
        if(tab[i].tempo<tempo){
            printf("\nNome:%s",tab[i].nome);
        }

    }
}