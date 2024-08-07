
#include <stdio.h>

#include "ponto.h"
#include "ret.h"

/*
int main(int argc, char** argv) {


    ponto2D p1 = {1,3}, p2,ponto1={1,2},ponto2={3,4},ponto3={5,6};


    initPonto(&p2);

    printPonto(p1);

    printPonto(p2);

    movePonto(&p1, 3, -2);
    printPonto(p1);

    if (alinhados(ponto1, ponto2, ponto3)) {
        printf("Os pontos estao alinhados\n");
    } else {
        printf("Os pontos nao estao alinhados\n");
    }


    return 0;
}
*/
////exc2

 int main(int argc, char** argv){
    ret r1={1,2,3,4},r2;
    int ponto_x,ponto_y;
    printret(&r1);

    initRet(&r2);

    printf("Area: %d",area(&r2));

    ////alinea e)

    printf("\nPonto x: ");
    scanf("%d",&ponto_x);
    printf("Ponto y: ");
    scanf("%d",&ponto_y);

    if (dentro_retangulo(&r2, ponto_x, ponto_y)) {
        printf("O pontos esta dentro do retangulo\n");
    } else {
        printf("O ponto nao esta dentro do retangulo\n");
    }
}

////alinea f)

moveret(&r1, 1 , 2);
printret(r1);