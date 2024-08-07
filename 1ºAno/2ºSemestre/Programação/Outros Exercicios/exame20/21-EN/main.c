#include <stdio.h>
#include <stdlib.h>
#define DIM 100
typedef struct criador Criador, *pCriador;
typedef struct ave Ave, *pAve;
typedef struct {int d, m, a;} Data;
struct criador {
    char nome[DIM]; // Nome do criador das aves (não há 2 iguais)
    int contador; // Número de aves que o criador tem à venda
    pAve lista; // Ponteiro para a lista de aves do criador
    pCriador prox; // Ponteiro para o próximo criador
};
struct ave {
    int id; // Identificador único da ave
    int gaiola; // Número da gaiola onde foi colocada a ave
    Data avender, venda; // datas em que a ave foi colocada à venda e vendida
    pAve prox;
};


int contabiliza(pCriador p,int numero_gaiola){

    pCriador aux=p;
    int conta=0;

    while(aux!=NULL){
        pAve aves=aux->lista;
        while(aves!=NULL){
            if(aves->gaiola==numero_gaiola && aves->venda.d==0 && aves->venda.m==0 && aves->venda.a==0)
                conta++;
                aves=aves->prox;
        }
        aux=aux->prox;
    }
    return conta;

}


pCriador elimina(pCriador p) {
    pCriador aux = p, ant = NULL;

    while (aux != NULL) {
        pAve aves = aux->lista;
        pAve ave_anterior = NULL;
        while (aves != NULL) {
            if (aves->venda.d != 0 || aves->venda.m != 0 || aves->venda.a != 0) {
                if (ave_anterior == NULL) {
                    aux->lista=aves->prox;
                    free(aves);
                    aux=aux->lista;

                }
                else{
                    ave_anterior=aves->prox;
                    free(aves);
                    aves=aves->prox;
                }
                aux->contador--;
            }
            else{
                ave_anterior=aves;
                aves=aves->prox;
            }
            if(aux->lista==NULL){
                if(ant==NULL){
                    p=aux->prox;
                    free(aux);
                    aux=p;
                }
                else{
                    ant->prox=aux->prox;
                    free(aux);
                    aux=aux->prox;
                }

            }
            else{
                ant=aux;
                aux=aux->prox;
            }


        }

return aux;
    }

}



struct cc {
    char nome[100];
    int nif;
    int id;
};

struct dono {
    char nome[100];
    int nif;
    char mat[15];
};


void cria_txt(char *cartaficheiro, char*carroficheiro){
    FILE *fcarta;
    fcarta=fopen(cartaficheiro,"rb");
    if(fcarta==NULL){
        printf("Erro a abrir ficheiro");
        return;
    }
    FILE *fcarro;
    fcarro=fopen(carroficheiro,"rb");
    if(fcarro==NULL){
        printf("Erro a abrir ficheiro");
        return;
    }
    FILE *ftxt;
    ftxt=fopen("resumos.txt","w");
    struct cc carta;
    struct dono carro;
    while(fread(&carta,sizeof(struct cc),1,fcarta)==1){
        int encontrou=0
        scanf("%d",carta.id);
        while(fread(&carro,sizeof(struct dono),1,fcarro)==1){
            if(carta.nif==carro.nif){
                encontrou=1;
                fprintf(ftxt,"%s, %d, %d",carro.nome,carro.nif,carta.id);
                break;
            }
        }
        if(!encontrou){
            fprintf(ftxt,"%s,%d,indisponivel",carro.nome,carro.nif);
        }
    }
fclose(fcarta);
    fclose(fcarro);
    fclose(ftxt);


}




int main() {

    return 0;
}
