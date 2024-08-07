#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    char id[20]; // id alfanumérico do cliente
    int cc; // Número do cartão de cidadão
    float valor; // Valor gasto em compras desde o início do mês
    char cVIP; // Cliente VIP (S/N)
};


int cliente(char *nome_txt,char *nome_binario){
    FILE *ftxt,*fbin;

    ftxt=fopen(nome_txt,"r");
    if(ftxt==NULL){
        printf("Erro a abrir ficheiro");
        return 0;
    }
    fbin=fopen(nome_binario,"wb");
    if(fbin==NULL){
        printf("Erro a abrir ficheiro");
        return 0;
    }

    struct cliente c;
    float soma=0;
    int conta=0;

    while(fscanf(ftxt,"%s %d %f",&c.id,&c.cc,&c.valor)==3){

        fwrite(&c,sizeof(struct cliente),1,fbin);
        soma+=c.valor;
        conta++;
    }

    float media=soma/conta;
    fseek(fbin,sizeof(cliente),SEEK_SET);
    while(fread(&c,sizeof(cliente),1,fbin)==1){
        if(c.valor>media){
            c.cVIP='S';
        }
        else{
            c.cVIP='N';
        }
        fseek(&fbin,-sizeof(cliente),SEEK_CUR);
        fwrite(&c,sizeof (cliente),1,fbin);
    }
    fclose(ftxt);
    fclose(fbin);
    return 1;
}


typedef struct prova teste, *pteste;
typedef struct pessoa aluno, *paluno;
struct prova{
    int *alineas; //Ponteiro para o vetor com as notas obtidas no teste
    int totA; // Número de alíneas do teste
    float nota; // Nota obtida no teste
    pteste prox;
};
struct pessoa{
    char nome[100]; // Nome do aluno
    int num; // Número do aluno
    pteste lista; // Ponteiro para a lista de testes
    paluno prox;
};


int testes(paluno p){
    paluno aux=p;
    int conta=0;
    while(aux!=NULL){
        pteste teste=aux->lista;
        while(teste!=NULL){
            float soma=0;
            for(int i=0;i<teste->totA;i++){
                 soma+=teste->alineas[i];
                ;
            }
            teste->nota=soma/teste->totA;
            conta++;
            teste=teste->prox;

        }
        aux=aux->prox;
    }
    return conta;
}


paluno adicionaTeste(paluno p, char *nome, int num, int al, int notas[]){
    paluno aux=p;
    while(aux!=NULL){
        if(aux->num==num){
            return p;
        }
        else{
            paluno novo=malloc(sizeof (aluno));
            if(novo==NULL){
                printf("Erro alocacao de  memoria");
                return NULL;
            }
            else{
                novo->num=num;
                strcpy(novo->nome,nome);
                novo->lista=NULL;
                novo->prox=NULL;

            }
        }

        pteste novo_teste=malloc(sizeof(teste));
        novo_teste->alineas=malloc(sizeof (int));
            novo_teste->totA=al;
            novo_teste->nota=0.0;
            novo_teste->prox=NULL;

            for(int i=0;i<al;i++){
                novo_teste->alineas[i]=notas[i];
            }
            pteste ptrProva=aux->lista;
            if(ptrProva==NULL){
                aux->lista=novo_teste;

            }
            else{
                while (ptrProva->prox!=NULL){
                    ptrProva=ptrProva->prox;
                }
                ptrProva->prox=novo_teste;
            }


    }
    return p;
}



int main() {

    return 0;
}
