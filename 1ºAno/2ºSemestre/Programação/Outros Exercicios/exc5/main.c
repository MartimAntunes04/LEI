#include <stdio.h>
#include "pizza.h"
int main() {

    pizza tab[10];
    int total=0,i;

    for(i=0;i<2;i++){
        adiciona_pizza(tab,&total);
    }

    print_pizza(tab,&total);

    atualiza_preco(tab,&total,15);

    tempo_pizza(tab,&total,3);

}
