#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int aves(pCriador p,int numgaiola){

    pCriador aux=p;
    int conta=0;

    while(aux!=NULL){
        pAve aves=aux->lista;
        while(aves!=NULL){
            if(aves->gaiola==numgaiola && aves->avender.d==0){
                conta++;
            }
            aves=aves->prox;
        }
        aux=aux->prox;
    }
    return conta;

}

pCriador RetiraVendidas(pCriador lista){

    pCriador atual=lista;
    pCriador criadoranterior=NULL;

    while(atual!=NULL){
        pAve aves=atual->lista;
        pAve anterior=NULL;
        while(aves!=NULL){
            if(aves->venda.d!=0){

                if(anterior==NULL){
                    aves->prox=atual->lista;

                }
                else{
                    anterior->prox=aves->prox;

                }
                free(aves);
                atual->contador--;
            }
            aves=aves->prox;
        }
        if(atual->lista==NULL){
            if(criadoranterior==NULL){
                atual->prox=lista;
            }
            else{
                criadoranterior->prox=atual->prox;
            }
            free(atual);
        }
        atual=atual->prox;
    }
    return lista;
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

void carros(char *nomeficheirocarta,char *nomeficheirocarros){

    FILE *fcarta,*fcarros,*ftxt;
    fcarta=fopen(nomeficheirocarta,"rb");
    if(fcarta==NULL){
        return;
    }
    fcarros=fopen(nomeficheirocarros,"rb");
    if(fcarros==NULL){
        fclose(fcarta);
        return;
    }

    ftxt=fopen("resumos.txt","w");
    if(ftxt==NULL){
        fclose(fcarta);
        fclose(fcarros);
        return;
    }

    struct cc carta;
    struct dono carro;
    while(fread(&carta,sizeof(struct cc),1,fcarta)==1){

        while(fread(&carro,sizeof(struct dono),1,fcarros)==1){
            if(carta.nif==carro.nif){
                fprintf(ftxt,"%s, %d ,%d",carro.nome,carro.nif,carta.id);
            }
            else{
                fprintf(ftxt,"%s,%d,indisponivel",carro.nome,carro.nif);
            }
        }
    }

    fclose(fcarta);
    fclose(fcarros);
    fclose(ftxt);


}







int main() {

    return 0;
}
