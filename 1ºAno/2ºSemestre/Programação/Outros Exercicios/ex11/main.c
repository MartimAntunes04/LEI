#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


void calculanotas(paluno p){
    paluno aux=p;
    int i,soma=0;
    float media=0;


    while(aux!=NULL){
        printf("%s,%d provas: ",aux->nome,aux->nprovas);

        if(aux->nprovas==0){
            printf("0.0");
        }
        else {
            for (i = 0; i < aux->nprovas; i++) {
                soma += aux->notas[i];
            }
            media=soma/aux->nprovas;
            printf("%.1f\n",media);
        }
        aux=aux->prox;
    }
}


paluno maisfaltas(paluno p){
    paluno aux=p;
    paluno alunoMaisFaltas = NULL;
    int contafaltas,maxfaltas;

    while(aux!=NULL){
        pdata data=aux->faltas;
        while (data!=NULL){
            contafaltas++;
            data=data->prox;
        }
        if(contafaltas>maxfaltas){
            maxfaltas=contafaltas;
            alunoMaisFaltas=aux;
        }

    aux=aux->prox;
    }
    if(alunoMaisFaltas!=NULL){
       ;
        if(alunoMaisFaltas==){
            p=p->prox;
        }
        else{
            paluno ant=p;
            while(ant!=NULL)
        }
    }
}


int main() {
    paluno lista_alunos = NULL;

    // Aluno 1
    paluno aluno1 = (paluno)malloc(sizeof(aluno));
    strcpy(aluno1->nome, "Ana Silva");
    aluno1->num = 1;
    aluno1->nprovas = 4;
    aluno1->notas = (int*)malloc(aluno1->nprovas * sizeof(int));
    aluno1->notas[0] = 70;
    aluno1->notas[1] = 55;
    aluno1->notas[2] = 80;
    aluno1->notas[3] = 90;
    aluno1->prox = NULL;

    // Aluno 2
    paluno aluno2 = (paluno)malloc(sizeof(aluno));
    strcpy(aluno2->nome, "Joao Santos");
    aluno2->num = 2;
    aluno2->nprovas = 3;
    aluno2->notas = (int*)malloc(aluno2->nprovas * sizeof(int));
    aluno2->notas[0] = 90;
    aluno2->notas[1] = 85;
    aluno2->notas[2] = 95;
    aluno2->prox = NULL;

    // Adicionar alunos à lista
    lista_alunos = aluno1;
    aluno1->prox = aluno2;

    // Calcular e apresentar a média dos alunos
    calculanotas(lista_alunos);
}
