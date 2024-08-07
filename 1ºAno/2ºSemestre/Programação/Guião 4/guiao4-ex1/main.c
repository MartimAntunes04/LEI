#include <stdio.h>
#include <string.h>
typedef struct paragem par,*ppar;
struct paragem{
char nome[50];
int minutos;
};

void mostratudo(char *nomeFicheiro){
    FILE *f;
    par c;

    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro a abrir ficheiro");
    }
    while(fread(&c,sizeof (par),1,f)==1)
        printf("%s\t%d\n",c.nome,c.minutos);
    fclose(f);
}

int verifica(char *nomeFicheiro,char *paragem){
    FILE *f;
    par c;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro a abrir ficheiro");
    }
    while(fread(&c,sizeof (par),1,f)==1){
        if(strcmp(c.nome,paragem)==0)
            return 1;
        else
            return 0;
    }
    fclose(f);
}

int tempo(char *nomeFicheiro){
    FILE *f;
    par c;
    int conta=0;

    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro no ficheiro");
    }
    while(fread(&c,sizeof (par),1,f)==1){
        conta+=c.minutos;
    }
    fclose(f);
    return conta;
}


int viagem(char *nomeFicheiro,char *partida,char *chegada){
    FILE *f;
    par c;
    int encontrou_partida=0,encontrou_chegada=0;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro ");

    }
    while(fread(&c,sizeof (par),1,f)==1){
        if(strcmp(partida,c.nome)==0) {
            encontrou_partida=1;
        }
        if(strcmp(chegada,c.nome)==0)
            encontrou_chegada=1;
        if(encontrou_partida && encontrou_chegada){
            return c.minutos;

        }
        else{
            return -1;

        }
    }
    fclose(f);
}


int main() {
    int x,y,z;

    mostratudo("cp_ex1.dat");
    x= verifica("cp_ex1.dat","Algarve");
    printf("%d",x);
    y= tempo("cp_ex1.dat");
    printf("%d",y);
    z= viagem("cp_ex1.dat","Lisboa","Coimbra");
    printf("\n%d",z);
}
