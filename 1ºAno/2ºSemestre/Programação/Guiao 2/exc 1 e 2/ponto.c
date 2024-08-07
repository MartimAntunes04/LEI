
// Created by ASUS on 23/03/2023.
#include <stdio.h>
#include "ponto.h"

//// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}
//
 ///alinea c)
void initPonto(ponto2D* p){
    printf("Coordenadas x:  ");
    scanf("%d",&p->x);

    printf("Coordenada y: ");
    scanf("%d",&p->y);
}

//// alinea d)
void movePonto(ponto2D* p, int dx, int dy) {
     p->x += dx;
     p->y += dy;

    printf("Ponto: (%d,%d)\n",p->x,p->y);
}
//// alinea e)
int alinhados(ponto2D ponto1,ponto2D ponto2,ponto2D ponto3){
    int resultado = (ponto2.y - ponto1.y) * (ponto3.x - ponto2.x) - (ponto3.y - ponto2.y) * (ponto2.x - ponto1.x);
    if(resultado==0){
        return 1;
    }
    else{
        return 0;
    }
}