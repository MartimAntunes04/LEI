#include <stdio.h>
#include <string.h>
#include "ponto.h"
////exc1
int main(){

    ponto2D p1={1,2},p2;

    imprime_coordenadas(p1);

    init_ponto(&p2);

    desloque_ponto(&p1, -1,-2);

}
