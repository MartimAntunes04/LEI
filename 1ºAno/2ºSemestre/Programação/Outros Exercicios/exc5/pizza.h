//
// Created by ASUS on 25/04/2023.
//

#ifndef EXC5_PIZZA_H
#define EXC5_PIZZA_H
typedef struct dados pizza;
struct dados{
    char nome[100];
    int tempo,preço;

};

void adiciona_pizza(pizza tab[],int *total);
void print_pizza(pizza tab[],int *total);
void atualiza_preco(pizza tab[],int *total,int preco);
void tempo_pizza(pizza tab[],int *total,int tempo);
#endif //EXC5_PIZZA_H
