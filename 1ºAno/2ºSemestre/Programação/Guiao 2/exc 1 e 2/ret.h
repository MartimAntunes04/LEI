//
// Created by ASUS on 23/03/2023.
//

#ifndef UNTITLED_RET_H
#define UNTITLED_RET_H
////alinea a)
typedef struct retangulo ret;
struct retangulo{
    int x,y,altura,largura;

};

void printret(ret *a);

void initRet(ret *r);

int area(ret *r);

int dentro_retangulo(ret *r,int ponto_x,int ponto_y);

void moveret(ret *r,int dx,int dy);

#endif //UNTITLED_RET_H
