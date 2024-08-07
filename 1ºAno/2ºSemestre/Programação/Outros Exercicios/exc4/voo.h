//
// Created by ASUS on 25/04/2023.
//

#ifndef EXC4_VOO_H
#define EXC4_VOO_H
typedef struct aviao voo,*pvoo;
struct aviao{
    int num;
    char nome[100],destino[100];
};

void adicionar_voo(voo tab[],int *total);
void print_voo(voo tab[],int *total);

void elimina_voo(voo tab[],int *total);
#endif //EXC4_VOO_H
