#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cliente{
    int id; // id numérico do cliente
    char cc[10]; // Número do cartão de cidadão
    float valor; // Valor gasto em compras desde o início do mês
    float v_divida; // Valor em divida desde o início do mês
    char cCert; // Cliente certificado (S/N)
};

void atualizar(char *nomeFicheiro){
    FILE *f;
    struct cliente c;
    int num_clientes,num_certificados;

    f=fopen(nomeFicheiro,"rb+");
    if(f==NULL){
        printf("Erro a abrir ficheiro");
        return;
    }
    fread(&num_clientes,sizeof( int),1,f);
    fread(&num_certificados,sizeof (int),1,f);
    for(int i=0;i<num_clientes;i++){
        fread(&c,sizeof(struct cliente),1,f);
        strcpy(c.cc,"NA");
        if(c.v_divida<c.valor*0.1){
            c.cCert='S';
            num_certificados++;
        }
        else{
            c.cCert='N';
        }
    }
    fseek(f,sizeof (struct cliente),SEEK_CUR);
    fwrite(&c,sizeof(struct cliente),1,f);

    fseek(f,sizeof (int),SEEK_SET);
    fwrite(&num_certificados,sizeof (int),1,f);

    fclose(f);


}


typedef struct data{
    int dia, mes, ano;
    struct data *prox;} *pdata;
typedef struct pessoa aluno, *paluno;
struct pessoa{
    char nome[100]; // Nome do aluno
    int num; // Número do aluno
    int nprovas; // Provas realizadas
    int* notas; // Ponteiro para a tabela com as notas
    pdata faltas; // Ponteiro para a lista com registo de faltas
    paluno prox;
};


void calcula_media(paluno p){
    paluno aux=p;
    int soma=0;
    float media=0;
    while(aux!=NULL) {
        printf("%s,%d : ", aux->nome, aux->nprovas);
        if (aux->nprovas == 0) {
            printf("0.0");
        } else {
            for(int i=0;i<aux->nprovas;i++) {
                soma += aux->notas[i];
            }
        media = (soma / aux->nprovas);
        printf("%.1f", media);

        }
        aux=aux->prox;
    }
}


paluno elimina(paluno p){
    paluno atual=p,ant=NULL,maior_faltas=NULL;
    int conta=0;

    while(atual!=NULL){
        pdata faltas=atual->faltas;
        while(faltas!=NULL){
            conta++;
            faltas=faltas->prox;
        }
        if(conta>maior_faltas){
            maior_faltas=conta;
            maior_faltas=p;

        }
        atual=atual->prox;
    }

    if(maior_faltas!=NULL){
        if(maior_faltas==p){
            p=maior_faltas->prox;
        }
        else{
            paluno anterior=p;
            while(anterior->prox!=maior_faltas){
                anterior=anterior->prox;
            }
            anterior=anterior->prox;
        }
        free(maior_faltas->notas);
    }
    pdata falta_atual=maior_faltas->faltas;
    while(falta_atual!=NULL){
        pdata proxima_falta=falta_atual->prox;
        free(falta_atual);
        falta_atual=proxima_falta;
    }
    free(falta_atual);

    return p;
}


int main() {

    return 0;
}
