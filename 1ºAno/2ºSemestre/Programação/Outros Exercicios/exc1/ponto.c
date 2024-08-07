//
// Created by ASUS on 25/04/2023.
//
#include <stdio.h>
#include <string.h>
#include "ponto.h"

void imprime_coordenadas( ponto2D a){
    printf("%d,%d",a.x,a.y);
}

init_ponto(ponto2D *a){
    printf("\nPonto: ");
    scanf("%d,%d",&a->x,&a->y);
}

desloque_ponto(ponto2D *a,int deslx,int desly){
    printf("%d,%d",a->x+deslx,a->y+desly);
}