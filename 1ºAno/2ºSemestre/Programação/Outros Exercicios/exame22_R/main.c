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


int bolos(char *nomeFicheirobin,char* nomeFicheirotxt,int ano){

    FILE *fbin,*ftxt;

    fbin=fopen(nomeFicheirobin,"rb");
    if(fbin==NULL){
        return 0;
    }
    ftxt=fopen(nomeFicheirotxt,"w");
    if(ftxt==NULL){
        fclose(fbin);
        return 0;
    }

    artigo c;
    int soma=0,conta=0;
    while(fread(&c,sizeof(artigo),1,fbin)==1){
        soma+=c.peso;
        conta++;
    }
    float media=soma/conta;
    fseek(fbin,sizeof (artigo),SEEK_SET);
    while(fread(&c,sizeof(artigo),1,fbin)==1){
        if(c.introducao.ano==ano && c.peso>=media){
            fprintf(ftxt,"%s\t%d",c.nome,c.tempo_confecao);
        }
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


pno_classe senior(pno_classe p){
    pno_classe aux=p;
    pno_classe mais_senior=NULL;

    int maximo=0;
    int conta=0;

    while(aux!=NULL){
        pno_atleta atletas=aux->lista_atletas;
        while(atletas!=NULL){
            if(strcmp(atletas->categoria,"SENIOR")==0){
                conta++;
            }
            atletas=atletas->prox_atleta;
        }
        if(conta>maximo){
            maximo=conta;
            mais_senior=aux;


        }
        else if(conta==maximo) {
            mais_senior=NULL;
        }
        aux=aux->prox_equipa;
    }

    return mais_senior;


}


pno_classe eliminaINF(pno_classe p, char * nomeC){

    pno_classe aux=p;
    pno_classe classeAnterior=NULL;
    while(aux!=NULL){
        if(strcmp(aux->nome_classe,nomeC)==0){
            classeAnterior=aux;
            aux=aux->prox_equipa;
            }
        }

        if(aux==NULL){
            return p;
        }

        pno_atleta atletaatual=aux->lista_atletas;
        pno_atleta atletaanterior=NULL;

        while(atletaatual!=NULL){
            if(strcmp(atletaatual->categoria,"INFANTIL")==0){
                if(atletaanterior==NULL){
                    aux->lista_atletas=atletaatual->prox_atleta;
                    free(atletaatual);
                    atletaatual=aux->lista_atletas;
                }
                else{
                    atletaanterior->prox_atleta=atletaatual->prox_atleta;
                    free(atletaatual);
                    atletaatual=atletaatual->prox_atleta;
                }

            }
            else{
                atletaanterior=atletaatual;
                atletaatual=atletaatual->prox_atleta;
            }


        }
        if(aux->lista_atletas==NULL){
            if(classeAnterior==NULL){
                p=aux->prox_equipa;
            }
            else{
                aux->prox_equipa=classeAnterior->prox_equipa;
            }
            free(aux);
        }
        return p;
    }









int main() {

    return 0;
}
