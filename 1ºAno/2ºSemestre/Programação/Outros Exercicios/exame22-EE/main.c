#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
typedef struct atg artigo;
struct atg{
    char nome[TAM];
    int peso; // Em gramas
    int tempo_confecao; // Tempo de confeção em minutos
    struct{
        int dia, mes, ano;
    }introducao; //Data de introdução do produto na ementa
};


int bolos(char *nome_bin,char *nome_txt, int ano){

    FILE *fbin=fopen(nome_bin,"rb");
    if(fbin==NULL){
        printf("Erro a abrir ficheiro");
        return 0;
    }
    FILE *ftxt=fopen(nome_txt,"w");
    if(ftxt==NULL){
        printf("Erro a abrir ficheiro");
        return 0;
    }

    artigo c;
    int soma_pesos=0,conta=0;
    while(fread(&c,sizeof(artigo),1,fbin)==1){
       soma_pesos+=c.peso;
       conta++;
    }
    float media_pesos=soma_pesos/conta;
    if(c.introducao.ano==ano && c.peso>=media_pesos){
        fprintf(ftxt,"%s %d",c.nome,c.tempo_confecao);
    }

    fclose(fbin);
    fclose(ftxt);
    return 1;

}

#define TAM 40
typedef struct atleta no_atleta, *pno_atleta;
typedef struct classe no_classe, *pno_classe;
struct atleta{
    char nome[TAM];
    char categoria[TAM]; // Pode ter os valores: INFANTIL, JUNIOR, SENIOR
    pno_atleta prox_atleta;
};
struct classe{
    char nome_classe[TAM];
    pno_atleta lista_atletas;
    pno_classe prox_equipa;
};


pno_classe verifica(pno_classe p){
    pno_classe aux=p,class_max;
    int maisclases=-1;
    while(aux!=NULL){
        pno_atleta atleta=aux->lista_atletas;
        int conta=0;
        while(atleta!=NULL) {
            if (strcmp(atleta->categoria, "SENIOR") == 0) {
                conta++;
            }
            atleta=atleta->prox_atleta;
        }
            if(conta>maisclases){
                maisclases=conta;
                class_max=aux;

            }
            else if(class_max==aux){
                return NULL;
        }
            aux=aux->prox_equipa;
    }
    return class_max;

}


pno_classe eliminaINF(pno_classe p, char * nomeC){
    pno_classe aux=p,anterior=NULL;
    pno_classe classe_anterior = NULL;

    while(aux!=NULL){
        if(strcmp(aux->nome_classe,nomeC)==0){
        pno_atleta atleta=aux->lista_atletas;
        pno_atleta atleta_anterior=NULL;

        while(atleta!=NULL) {

            if(strcmp(atleta->categoria,"INFANTIL")==0){
                pno_atleta atleta_remover=atleta;

                if(atleta_anterior==NULL){
                    aux->lista_atletas==atleta->prox_atleta;
                }
                else{
                    atleta_anterior->prox_atleta=atleta->prox_atleta;
                }
                atleta=atleta->prox_atleta;
                free(atleta_remover);

            }
            else{
                atleta_anterior=atleta;
                atleta=atleta->prox_atleta;
            }

        }

        if(aux->lista_atletas==NULL){
            pno_classe classe_remover=aux;
            if(classe_anterior==NULL){
                p=aux->prox_equipa;
                free(classe_remover);
            }
            else{
                classe_anterior=aux;
                aux=aux->prox_equipa;
            }

        }
        else{
            classe_anterior=aux;
            aux=aux->prox_equipa;
        }
        }
    }
return p;

}


int main() {

    return 0;
}
