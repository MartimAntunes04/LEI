#include <stdio.h>
#include "lista.h"
int main() {
    pno lista = NULL;
    int i;
    for(i=0;i<2;i++){
        lista = adiciona(lista);
    }
    listarTudo(lista);
    elimina(lista,1);
    listarTudo(lista);
    return 0;
}
