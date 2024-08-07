//
// Created by ASUS on 25/04/2023.
//
#include <stdio.h>
#include "ret.h"

print_ret(ret a){
    printf("%d,%d",a.x,a.y);
    printf("\nAltura: %d",a.altura);
    printf("\nLargura: %d",a.largura);
}

init_ret(ret *a){
    printf("\nPonto: ");
    scanf("%d,%d",&a->x,&a->y);
    printf("Altura: ");
    scanf("%d",&a->altura);
    printf("Largura: ");
    scanf("%d",&a->largura);

}

area_ret(ret *a){
    int area;
    area = a->largura*a->altura;
    return area;
}

desl_ret(ret *a, int deslx,int desly){
    printf("\nPonto : %d,%d",a->x+deslx,a->y+desly);
    printf("\nAltura: %d",a->altura);
    printf("\nLargura: %d",a->altura);
}