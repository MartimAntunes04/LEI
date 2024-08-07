#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct atleta alt,*palt;
struct atleta{
    char nome[100];
    int tAcumulado[10];
    int kmRapido;
};


int calcula_tempo(char *nomeFicheiro){
    FILE *f;
    int num_concorrentes;
    int primeiroTempo = -1;
    int ultimoTempo = -1;
    int tempoDecorrido = -1;

    f=fopen(nomeFicheiro,"r");
    if(f==NULL){
        printf("Erro a abrir ficheiro");
        return -1;
    }
    fscanf(f,"Atletas:%d\n",&num_concorrentes);
    while (!feof(f)) {
        char linha[100];
        int posicao, tempo;

        // Ler a linha de cabeçalho do km
        fgets(linha, sizeof(linha), f);

        // Ler as linhas de classificação dos atletas
        for (int i = 0; i < num_concorrentes; i++) {
            fgets(linha, sizeof(linha), f);
            sscanf(linha, "%d. %*[^:]: %d", &posicao, &tempo);

            // Atualizar o tempo do primeiro e do último atleta
            if (i == 0 && primeiroTempo == -1) {
                primeiroTempo = tempo;
            }
            if (i == num_concorrentes - 1) {
                ultimoTempo = tempo;
            }
        }
    }

    // Calcular o tempo decorrido entre o primeiro e o último atleta
    if (primeiroTempo != -1 && ultimoTempo != -1) {
        tempoDecorrido = ultimoTempo - primeiroTempo;
    }

    fclose(f);

    return tempoDecorrido;
}

palt vetor(char *nomeFicheiro,int *dimensao){
    int num_atletas;
    FILE *f;
    f=fopen(nomeFicheiro,"r");
    if(f==NULL){
        printf("Erro a abrir ficheiro");
        return NULL;
    }
    fscanf(f,"Atletas:%d",&num_atletas);
    *dimensao=num_atletas;

    palt vetor_atletas=malloc(num_atletas*sizeof (alt));
    if(vetor_atletas==NULL){
        fclose(f);
        return NULL;
    }
    char linha[200];
    for (int i = 0; i <num_atletas; i++) {
        fgets(linha, sizeof(linha), f); // Lê a linha vazia após o número de atletas
        fgets(linha, sizeof(linha), f); // Lê a linha com o nome do atleta

        // Remove o caractere de nova linha no final do nome
        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        strcpy(vetor_atletas[i].nome, linha);

        // Lê os tempos acumulados para cada km
        for (int j = 0; j < 10; j++) {
            fscanf(f, "%*d. %*[^:]: %d", &vetor_atletas[i].tAcumulado[j]);
        }

        // Lê o km mais rápido
        fscanf(f, "%*d. %*[^:]: %*d\n");

        // Verifica se chegou ao final do arquivo
        if (feof(f)) {
            printf("Erro: Informação insuficiente no ficheiro\n");
            free(vetor_atletas);
            fclose(f);
            return NULL;
        }
    }

    fclose(f);
    return vetor_atletas;
}


typedef struct valor no, *pno;
struct valor{
    int num;
    pno dir, esq;
};

void mostra_descrescente(pno tree){
    if(tree==NULL)
        return;
    else{
        mostra_descrescente(tree->dir);
        printf("%d",tree->num);
        mostra_descrescente(tree->esq);
    }
}


typedef struct divisao div, *pdiv;
typedef struct porta no, *pno;
struct divisao{
    int id;
    char nome[100];
    int n_pessoas;
    pno lista;
};
struct porta{
    int id;
    pno prox;
};
struct pessoa{
    char nome[100];
    struct{
        int d,m,a;
    }nasc;
    pdiv local;
};


int verifica(pdiv apartamnento,int tamamho_apartamento,struct pessoa *habitantes,int tamanho_habitantes){
    int conta;

    for(int i;i<tamamho_apartamento;i++){
        pno porta_atual= apartamnento[i].lista;
        int conta=0;

        while(porta_atual!=NULL){
            int conta
        }


    }
}



int main() {

    return 0;
}
