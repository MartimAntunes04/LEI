#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    int id; // id numérico do cliente
    char cc[10]; // Número do cartão de cidadão
    float valor; // Valor gasto em compras desde o início do mês
    float v_divida; // Valor em divida desde o início do mês
    char cCert; // Cliente certificado (S/N)
};

void cartao(char *nomeFicheiro){
    FILE *f;
    f=fopen(nomeFicheiro,"rb+");
    if(f==NULL){
        return;
    }
    int numclientes,num_certificados;
    fread(&numclientes,sizeof(int),1,f);
    fread(&num_certificados,sizeof(int),1,f);
    struct cliente c;
    for(int i=0;i<numclientes;i++){
        fread(&c,sizeof (struct cliente),1,f);
        strcpy(c.cc,"NA");

        if(c.valor<c.valor*0.1){
            c.cCert='S';
            num_certificados++;
        }
    }

    fseek(f,sizeof(struct cliente),SEEK_CUR);
    fwrite(&c,sizeof (struct cliente),1,f);

    fseek(&num_certificados,sizeof (int),SEEK_SET);
    fwrite(&num_certificados,sizeof(int),1,f);

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



paluno notas(paluno p){
    paluno aux=p;
    int soma=0;
    while(aux!=NULL){
        printf("%s,%d provas",aux->nome,aux->nprovas);
        if(aux->nprovas==0){
            printf("0.0");
        }
        for(int i=0;i<aux->nprovas;i++){
            soma+=aux->notas[i];

        }
        float media=soma/aux->nprovas;
        printf("%.1f",media);
        aux=aux->prox;
    }

}


paluno eliminar(paluno p){
    int maisfaltas=0;
    int contafaltas=0;
    int codigo;
    int flag=0;
    paluno aux=p;
    paluno alunomaisfaltas=NULL;
    while(aux!=NULL){
        pdata listafaltas=aux->faltas;
        while(listafaltas!=NULL){
               contafaltas++;
               listafaltas=listafaltas->prox;
        }
        if(contafaltas>maisfaltas){
            maisfaltas=contafaltas;
            alunomaisfaltas=aux;

            flag=0;
        }
        if(contafaltas=maisfaltas){
            flag=1;
        }
    aux=aux->prox;

    }
    if(flag=0){
           if(p==alunomaisfaltas){
               p=p->prox;
           }
           else{
             paluno anterior=p;
             while(anterior->prox!=alunomaisfaltas){
                    anterior=anterior->prox;
             }
             anterior->prox=alunomaisfaltas->prox;
           }


           free(alunomaisfaltas->notas);

           pdata faltas=alunomaisfaltas->faltas;
           while(faltas!=NULL){
               pdata proxima=faltas->prox;
               free(faltas);
               faltas=proxima;
           }
           free(alunomaisfaltas);
    }
return p;

}


int main() {

    return 0;
}
