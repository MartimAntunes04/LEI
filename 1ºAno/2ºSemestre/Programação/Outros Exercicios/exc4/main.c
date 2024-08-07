#include <stdio.h>
#include <string.h>
#include "voo.h"
int main() {

    voo tab[100];
    int total=0,i;

    for(i=0;i<2;i++){
       adicionar_voo(tab,&total);
    }
    print_voo(tab,&total);

    elimina_voo(tab,&total);
}
