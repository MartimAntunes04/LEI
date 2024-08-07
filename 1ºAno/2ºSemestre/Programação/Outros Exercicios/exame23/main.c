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


voo* funcao(char *nomeFicheiro,tempo hotaAT,char *codigo,int *tam){
    FILE *f;
    f=fopen(nomeFicheiro,"rb+");
    if(f==NULL){
        return NULL;
    }
    voo *array=NULL;
    voo v;
    while(fread(&v,sizeof(voo),1,f)==1){
        if(v.t.h<hotaAT.h || v.t.h==hotaAT.h && v.t.m<hotaAT.m){
            v.emTerra=0;
            fseek(f,-sizeof(voo),SEEK_CUR);
            fwrite(&v,sizeof(voo),1,f);
        }

        if(strcmp(v.codigo,codigo)==0){
            array= realloc(array,sizeof(voo)*(*tam+1));
            if(array==NULL){
                return NULL;
            }
            array[*tam]=v;
            (*tam)++;
        }
    }
    fclose(f);
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


void salas(pno p,struct sala *s,int tam){
    char codigo[10];
    int maximo=0;
    int flag=0;
    for(int i=0;i<tam;i++){
        if(s[i].total>maximo){
            maximo=s[i].total;
            strcpy(codigo,s[i].id);
            flag=1;
        }
        else if(s[i].total==maximo){
                flag=0;
        }
    }

    if(flag=1){
        pno aux=p;
        while(aux!=NULL){
            if(strcmp(aux->p->id,codigo)==0){
                printf("%s %d",aux->nome,aux->num);
            }
            aux=aux->prox;
        }
    }

}


pno adicionaAl(pno lista, struct sala *s, int tot, char *nome, char *num){
    int minimo=s[0].total;
    int index=0;

    for(int i=0;i<tot;i++){
        if(s[i].total<minimo){
            minimo=s[i].total;
            index=i;
        }
    }

    pno novoaluno=malloc(sizeof(no));
    if(novoaluno==NULL){
        return lista;
    }
    strcpy(novoaluno->nome,nome);
    strcpy(novoaluno->num,num);
    novoaluno->p=&s[index];
    novoaluno->prox=NULL;


    if(lista==NULL){
        lista=novoaluno;
    }
   pno alunoanterior=NULL;
    pno alunoatual=lista;

    while(alunoatual!=NULL){
        if(strcmp(novoaluno->nome,alunoatual->nome)>0){
            break;
        }
        if(alunoanterior==NULL){
            novoaluno->prox=lista;
        }
        else{
            alunoanterior->prox=novoaluno;
            novoaluno->prox=alunoatual;
        }
    }

return lista;


}






int main() {

    return 0;
}
