#include <stdio.h>
#include "exc2.h"

int main() {
    int soma=0;
    float media=0.0;

    int*v=NULL;
    int total=0;

    printVals("valoresEx2.bin");

    calcula("valoresEc.2.bin",&soma,&media);
    printf("Soma:%d\t Media:%.2f\n",soma,media);
    return 0;
}
