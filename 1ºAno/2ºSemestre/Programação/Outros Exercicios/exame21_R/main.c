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

float sensor(pDivisao p,int sensor){

    float maior=0.0;
    pDivisao aux=p;

    while(aux!=NULL){
        pLeitura leituras=aux->leituras;
        while(leituras!=NULL){
            if(leituras->tipoSensor==sensor){
                printf("%s:%f [%.2d:%.2d]",aux->nome,leituras->valor,leituras->hora.h,leituras->hora.m);

            }
            else{
                printf("-1.0");
            }
            if(leituras->valor>maior){
                maior=leituras->valor;
            }

        }
        aux=aux->prox;


    }

    return maior;

}



pDivisao adiciona(pDivisao lista, char *div, int idS, int h, int m,double val){

    pDivisao divisaoatual=lista;
    pDivisao divisaoanterior=NULL;

    while(divisaoatual!=NULL){

        if(strcmp(divisaoatual->nome,div)==0){
            pLeitura leituras=divisaoatual->leituras;
            pLeitura leituraanterior=NULL;
            while(leituras!=NULL){
                if(leituras->tipoSensor==idS){
                    leituras->hora.h=h;
                    leituras->hora.m=m;
                    leituras->valor=val;
                    return lista;
                }

            }

            if(leituras==NULL){
                pLeitura novoleitura=malloc(sizeof (Leitura));
                if(novoleitura==NULL){
                    return lista;
                }
                novoleitura->tipoSensor=idS;
                novoleitura->hora.m=m;
                novoleitura->hora.h=h;
                novoleitura->valor=val;

                if(leituraanterior==NULL){
                    leituraanterior->prox=novoleitura;
                }
                else{
                    divisaoatual->leituras=novoleitura;
                }
                divisaoatual->nr_leituras++;
                return lista;
            }
        }
     else{
         pDivisao novadivisao=malloc(sizeof(Divisao));
         if(novadivisao==NULL){
             return lista;
         }
        strcpy(novadivisao->nome,div);
        novadivisao->nr_leituras=1;
        pLeitura novaleitura=malloc(sizeof(Leitura));
        novaleitura->tipoSensor=idS;
        novaleitura->hora.h=h;
        novaleitura->hora.m=m;
        novaleitura->valor=val;
        novadivisao->leituras=novaleitura;
        novadivisao->prox=NULL;

        if(divisaoanterior==NULL){
            return novadivisao;
        }
        else{
            divisaoanterior->prox=novadivisao;
            return lista;
        }

     }
    }


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



void carros(char *nomeficheirotxt,char *nomeficheirobinexistente,char *nomeficheirobincriar){

    FILE *ftxt,*fbinexis,*fbincriar;
    ftxt=fopen(nomeficheirotxt,"r");
    if(ftxt==NULL){
        return;
    }

    fbinexis=fopen(nomeficheirobinexistente,"rb");
    if(fbinexis==NULL){
        fclose(ftxt);
      return;
    }

    fbincriar=fopen(nomeficheirobincriar,"wb");
    if(fbincriar==NULL){
        fclose(ftxt);
        fclose(fbinexis);
        return;
    }

    struct cc carta;
    struct venda carro;
    int numcarros;
    while(fscanf(ftxt,"NIF:%d ; ID: %d",&carta.nif,carta.id)==2){
        numcarros=0;
        while(fread(&carro,sizeof (struct venda),1,fbinexis)==1){
            if(carro.nif==carta.nif){
                numcarros++;
                if(numcarros>2){
                    break;
                }

            }

        }
        if(numcarros>=2) {
            fseek(fbincriar, 0, SEEK_SET);
            fwrite(&carta, sizeof(struct cc), 1, fbincriar);
        }
        else{
            carta.id=-1;
            fseek(fbincriar,sizeof (struct cc),SEEK_CUR);
            fwrite(&carta,sizeof (struct cc),1,fbincriar);
        }
    }

    fclose(ftxt);
    fclose(fbinexis);
    fclose(fbincriar);


}






int main() {

    return 0;
}
