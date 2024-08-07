//
// Created by ASUS on 23/03/2023.
//
#include <stdio.h>
#include "ret.h"

////alinea b)
void printret(ret *a){
    int x1 = a->x;
    int y1 = a->y;
    int x2 = a->x + a->largura;
    int y2 = a->y;
    int x3 = a->x + a->largura;
    int y3 = a->y + a->altura;
    int x4 = a->x;
    int y4 = a->y + a->altura;

    printf("Canto inferior esquerdo: (%d,%d)\n", x1, y1);
    printf("Canto inferior direito: (%d,%d)\n", x2, y2);
    printf("Canto superior direito: (%d,%d)\n", x3, y3);
    printf("Canto superior esquerdo: (%d,%d)\n", x4, y4);
}

////alinea c)

void initRet(ret *r){
    printf("Coordenada x: ");
    scanf("%d",&r->x);
    printf("Coordenada y: ");
    scanf("%d",&r->y);
    printf("Altura: ");
    scanf("%d",&r->altura);
    printf("Largura: ");
    scanf("%d",&r->largura);
}

////alinea d)

int area(ret *r){
    int area=r->largura*r->altura;
    return area;
}

////alinea e)
int dentro_retangulo(ret *r,int ponto_x,int ponto_y){

    if (ponto_x > r->x && ponto_x < (r->x + r->largura) && ponto_y > r->y && ponto_y < (r->y + r->altura)) {
        return 1; // ponto está dentro do retângulo
    } else {
        return 0; // ponto está fora do retângulo
    }
}

////alinea f)

void moveret(ret *r,int dx,int dy){
    r->x += dx;
    r->y += dy;

    printf("Retangulo:(%d,%d)",r->x,r->y);
}