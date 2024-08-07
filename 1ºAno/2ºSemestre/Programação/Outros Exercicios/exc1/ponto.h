//
// Created by ASUS on 25/04/2023.
//

#ifndef EXC1_PONTO_H
#define EXC1_PONTO_H

typedef struct ponto ponto2D;
struct ponto{
    int x,y;
};

void imprime_coordenadas( ponto2D a);
init_ponto(ponto2D *a);
desloque_ponto(ponto2D *a,int deslx,int desly);
#endif //EXC1_PONTO_H
