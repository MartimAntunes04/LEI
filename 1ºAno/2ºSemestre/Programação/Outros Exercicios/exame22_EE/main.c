#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cliente{
    char id[20]; // id alfanumérico do cliente
    int cc; // Número do cartão de cidadão
    float valor; // Valor gasto em compras desde o início do mês
    char cVIP; // Cliente VIP (S/N)
};

int mercearia(char *nomeFicheirotxt,char *nomeFicheirobin){
    FILE *ftxt,*fbin;

    ftxt=fopen(nomeFicheirotxt,"r");
    if(ftxt==NULL){
        return 0;
    }
    fbin=fopen(nomeFicheirobin,"wb");
    if(fbin==NULL){
        fclose(ftxt);
        return 0;
    }
    int conta=0;
    float soma=0.0;
    struct cliente c;
    while(fscanf(ftxt,"%s %d %f",c.id,c.cc,c.valor)==3){
        soma+=c.valor;
        conta++;
    }
    float media=soma/conta;

    while(fscanf(ftxt,"%s %d %f",c.id,&c.cc,&c.valor)==3){
        if(c.valor>media){
          c.cVIP='S';
        }
        else{
            c.cVIP='N';
        }

    }
    fseek(fbin,sizeof(struct cliente),SEEK_SET);
    fwrite(&c,sizeof (struct cliente),1,fbin);

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


int numtestes(paluno p){
    int totaltestes=0;
    paluno aux=p;
    int soma=0;
    while(aux!=NULL) {
        pteste testes = aux->lista;
        while (testes != NULL) {
            int *alineas = testes->alineas;
            for (int i = 0; i < testes->totA; i++) {
                soma+=alineas[i];

            }
            testes->nota = soma / testes->totA;

            testes = testes->prox;
            totaltestes;
        }
        aux = aux->prox;
    }
    return totaltestes;
}

paluno adicionaTeste(paluno p, char *nome, int num, int al, int notas[]) {

    paluno aux = p;

    while (aux != NULL ){
        if(strcmp(aux->nome,nome)==0 && aux->num==num){
            break;
        }
        aux=aux->prox;

    }

    if(aux==NULL){
        paluno novoaluno=malloc(sizeof(aluno));
        if(novoaluno==NULL){
            return p;
        }

        strcpy(novoaluno->nome,nome);
        novoaluno->num=num;
        novoaluno->lista=NULL;
        novoaluno->prox=p;
        aux=novoaluno;
    }

    pteste novoteste=malloc(sizeof(teste));
    if(novoteste==NULL){
        return p;
    }
    novoteste->totA=al;
    novoteste->alineas=malloc(sizeof (int)*al);
    if(novoteste->alineas==NULL){
        return p;
    }

    for(int i=0;i<al;i++){
        novoteste->alineas[i]=notas[i];
    }

    if(aux->lista==NULL){
        aux->lista=novoteste;
    }
    else{
        pteste testeatual=aux->lista;
        while(testeatual->prox!=NULL){
            testeatual=testeatual->prox
        }
        testeatual->prox=novoteste;
    }

   return p;


}







int main() {

    return 0;
}
