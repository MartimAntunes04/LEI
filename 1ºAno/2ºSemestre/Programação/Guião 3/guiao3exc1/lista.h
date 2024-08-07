//
// Created by ASUS on 27/04/2023.
//

#ifndef GUIAO3EXC1_LISTA_H
#define GUIAO3EXC1_LISTA_H


typedef struct pessoa no,*pno;
struct pessoa{
    char nome[50];
    int id;
    float altura,peso;
    pno prox;
};

pno adiciona(pno p);
void listarTudo(pno p);
pno elimina(pno p,int x);




#endif //GUIAO3EXC1_LISTA_H
