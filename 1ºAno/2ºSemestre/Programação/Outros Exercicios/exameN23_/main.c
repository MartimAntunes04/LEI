#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {int h, m;} tempo;
typedef struct Voo voo;
struct Voo{
    char codigo[6]; // código do voo
    char destino[4]; // código do destino
    int emTerra; // sim = 1; não = 0;
    tempo t; // hora de partida
};


voo *funcao(char *nomeFicheiro,tempo horaatual,char *codigodestino,int *tam){
    FILE *f;
    f=fopen(nomeFicheiro,"rb+");
    if(f==NULL){
        return NULL;
    }
    voo v;
    while(fread(&v,sizeof (voo),1,f)==1){
        if(v.t.h>horaatual.m && v.t.m>horaatual.m){
            v.emTerra=0;
            fseek(f,sizeof (voo),SEEK_CUR);
            fwrite(&v,sizeof (voo),1,f);
        }
    }
    int contador = 0;
    while(fread(&v,sizeof (voo),1,f)==1){
        if(strcmp(v.codigo,codigodestino)==0){
            contador++;
        }
    }
    voo *array=malloc(sizeof (voo)*(contador));
    if(array==NULL){
        fclose(f);
        return NULL;
    }

    fseek(f, 0, SEEK_SET);
    int index = 0;
    while (fread(&v, sizeof(voo), 1, f) == 1) {
        if (strcmp(v.destino, codigodestino) == 0) {
            array[index] = v;
            index++;
        }
    }

    fclose(f);
    *tam=contador;
    return array;


}

struct sala{
    char id[10];
    int total;
};
typedef struct pessoa no, *pno;
struct pessoa{
    char nome[100], num[20]; // Nome e número do aluno
    struct sala* p; // Ptr. para a sala onde o aluno fará o teste
    pno prox;
};


void salamaior(pno p,struct sala *s,int *tam){
    int maximo=0;
    char aux[10];
    int flag=0;
    for(int i=0;i<tam;i++){
        if(s[i].total>maximo){
            maximo=s[i].total;
            strcpy(aux,s[i].id);
            flag=0;
        }
        if(s[i].total==maximo){
            flag=1;
        }

    }

    if(flag==0){
        pno auxiliar=p;
        while(auxiliar!=NULL){
            if(strcmp(auxiliar->p->id,aux)==0){
                printf("%s \n%d",auxiliar->nome,auxiliar->num);
            }
            auxiliar=auxiliar->prox;
        }
    }

}

pno adicionaAl(pno lista, struct sala *s, int tot, char *nome, char *num){

    int minimo=s[0].total;
    int posicao;

    for(int i=0;i<tot;i++){
        if(s[i].total<minimo){
            minimo=s[i].total;
            posicao=1;

        }
    }

    pno novo=malloc(sizeof (no));
    if(novo==NULL){
        return NULL;
    }

    strcpy(novo->nome,nome);
    strcpy(novo->num,num);

    novo->prox=NULL;
    novo->p=&s[posicao];

    s[posicao].total++;

    if(lista==NULL){
        novo=lista;
        return lista;
    }
    pno atual=lista;
    pno anterior=NULL;

    while(atual!=NULL){
        if(strcmp(atual->nome,novo->nome)>0){
            break;
        }
        else{
            if(anterior==NULL){
                novo->prox=lista;
                lista=novo;
            }
            else{
                anterior->prox=novo;
                novo->prox=atual;
            }
        }
    }
    return lista;

}



int main() {
    printf("Hello, World!\n");
    return 0;
}
