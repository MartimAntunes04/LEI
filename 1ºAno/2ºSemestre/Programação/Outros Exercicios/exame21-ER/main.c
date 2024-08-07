#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct divisao Divisao, *pDivisao;
typedef struct leitura Leitura, *pLeitura;
struct divisao {
    char nome[100]; // nome da divisão
    int nr_leituras; // número de leituras guardadas
    pLeitura leituras; // tabela de valores dos sensores
    pDivisao prox;};
struct leitura {
    int tipoSensor; // tipo de sensor
    struct {int h, m;} hora; // hora de recolha do valor
    double valor;}; // leitura do sensor


int sensor(pDivisao p,int tipo){
    pDivisao aux=p;
    double maior_valor=-1;
    while(aux!=NULL){
        pLeitura sensores=aux->leituras;
        while(sensores!=NULL){
            if(sensores->tipoSensor==tipo){
                if(sensores->valor>maior_valor)
                    maior_valor=sensores->valor;
                printf ("%s: %.1f [%d:%d]",aux->nome,sensores->valor,sensores->hora.h,sensores->hora.m);
            }
            else{
                return -1;
            }

        }
        aux=aux->prox;
    }
    return maior_valor;
}

pDivisao adiciona(pDivisao lista, char *div, int idS, int h, int m,double val){
    pDivisao aux=lista;

    while(aux!=NULL){
        if(strcmp(aux->nome,div)==0){
            pLeitura sensores=aux->leituras;
            while(sensores!=NULL){
                if(idS==sensores->tipoSensor){
                    sensores->hora.m=m;
                    sensores->hora.h=h;
                    sensores->valor=val;
                }
                else{
                    pLeitura novo_sensor=malloc(sizeof(Leitura));
                    if(novo_sensor==NULL){
                        printf("Erro");
                        return NULL;
                    }
                    else{
                        novo_sensor->tipoSensor=idS;
                        novo_sensor->hora.h=h;
                        novo_sensor->hora.m=h;
                        novo_sensor->valor=val;

                    }
                }

            }
        }
        else{
            pDivisao nova_divisao=malloc(sizeof (Divisao));
            strcpy(nova_divisao->nome,div);
            nova_divisao->nr_leituras=1;
            if(nova_divisao==NULL){
                return NULL;
            }

            else{
                nova_divisao->leituras=NULL;
                nova_divisao->nome=div;
                nova_divisao->nr_leituras=0;
            }
        }
        aux=aux->prox;
    }
    return lista;
}


struct venda{
    struct{int dia, mes;} data;
    int nif;
    char mat[15];
};


struct cc{
    int nif;
    int id;
};


void obtercompradores(char *nomeficheiro_txt,char *nomeficheirovendas,char *nomeficheirobinario){
    FILE *ftxt;
    ftxt=fopen(nomeficheiro_txt,"w");
    if(ftxt==NULL){
        printf("Erro");
        return;
    }
    FILE *fvendas;
    fvendas=fopen(nomeficheirovendas,"rb");
    if(fvendas==NULL){
        printf("Erro");
        return;
    }

    FILE *fbinario;
    fbinario=fopen(nomeficheirobinario,"wb");
    if(fbinario==NULL){
        printf("Erro");
        return;
    }

    struct cc carta;
    while(fscanf(ftxt,"NIF: %d ; ID: %d",&carta.nif,&carta.id)==2){
        
    }


}





int main() {

    return 0;
}
