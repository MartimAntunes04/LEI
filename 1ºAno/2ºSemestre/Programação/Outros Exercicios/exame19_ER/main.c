#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int id; //id único do colaborador
    char nome[50];
    float latBase,longBase; //latitude e longitude do seu local base
    int ativo; //1 se o colaborador está ao serviço ou 0 se não está
} Colab, *pColab;

typedef struct Trotinete trot,*ptrot;
struct Trotinete{
    int id,carga;
    float latitude,longitude;
    char estado[10];
};


pColab vetor(char *nomeFicheiro, int *dimensao){
    FILE *f;
    Colab c;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        printf("Erro");
        return NULL;
    }
    fseek(f,0,SEEK_END);
    long tamanho= ftell(f);
    *dimensao=tamanho/sizeof(Colab);

    pColab vetorColaboradores= malloc(*dimensao*sizeof (Colab));
    if(vetorColaboradores==NULL){
        fclose(f);
        return NULL;
    }
    int contador=0;
    fseek(f,0,SEEK_SET);
    while(fread(&vetorColaboradores[contador],sizeof(Colab),1,f)==1){
        if(vetorColaboradores->ativo==1){
            contador++;
        }
    }

    *dimensao=contador;
    vetorColaboradores= realloc(vetorColaboradores,sizeof(Colab)*(*dimensao));
    fclose(f);
    return vetorColaboradores;
}

void criar_ficheiros(char *nome_trotinetes,char *nome_colaboradores){

    FILE*fTrotinetes;
    fTrotinetes=fopen(nome_trotinetes,"r");
    if (fTrotinetes == NULL) {
        printf("Erro ao abrir o ficheiro de trotinetes.\n");
        return;
    }

    FILE *fAvarias;
    fAvarias=fopen("avarias.txt","w");
    if(fAvarias==NULL){
        return;
    }

    FILE *fRecarga;
    fRecarga=fopen("recarga.txt","w");
    if(fRecarga==NULL){
        return;
    }

    trot trotinite;
    while(fscanf(fTrotinetes,"d","f","f","d","s",&trotinite.id,&trotinite.latitude,&trotinite.longitude,&trotinite.carga,&trotinite.estado)==5){
        if(strcmp(trotinite.estado,"avaria")==0 || strcmp(trotinite.estado,"alarme")==0)
            fprintf(fAvarias,"%d,%f,%f,%d,%s",trotinite.id,trotinite.latitude,trotinite.longitude,trotinite.carga,trotinite.estado);

        else if(trotinite.carga<60){
            float distanciaMinima = INFINITY;
            int idColaboradorMaisProximo = -1;

            FILE *fColaboradores;
            fColaboradores=fopen(nome_colaboradores,"rb");
            if(fColaboradores==NULL)
                return;

            Colab colaboladores;
            while(fread(&colaboladores,sizeof(Colab),1,fColaboradores)==1){
                if(colaboladores.ativo==1){
                    float distancia=dist(trotinite.latitude,trotinite.longitude,colaboladores.latBase,colaboladores.longBase);
                    if(distancia<distanciaMinima){
                        distanciaMinima=distancia;
                        idColaboradorMaisProximo=colaboladores.id;
                    }
                }
            }
        fclose(fColaboradores);

            fprintf(fRecarga,"d","f","f","d,%d",trotinite.id,trotinite.latitude,trotinite.longitude,trotinite.carga,idColaboradorMaisProximo);

        }


    }

fclose(fTrotinetes);
    fclose(fAvarias);
    fclose(fRecarga);


}


typedef struct e Exercicio, *pExercicio;
typedef struct c Cliente, *pCliente;
struct c{
    int id; // id inteiro único do cliente
    char nome[80];
    int dia, mes, ano; //data limite para atualizar a lista de exercícios
    pExercicio treino;
};
struct e{
    char id[20]; // id alfanumérico único
    int series, repeticoes; // Número de séries e repetições para este
//exercício
    pExercicio prox;
};



void mostraid(pCliente tab,int dimensao){
    int *contadorExercicios=calloc(dimensao,sizeof(int));
    if(contadorExercicios==NULL){
        return;
    }

    for(int i=0;i<dimensao;i++){
        pCliente cliente=&cliente[i];
        pExercicio exercicio=cliente->treino;
        while(exercicio!=NULL){
            contadorExercicios[exercicio->id]++;
            exercicio=exercicio->prox;
        }
        for(int i=0;i<dimensao;i++){
            pCliente cliente=&cliente[i];
            pExercicio exercicio=cliente->treino;
            while(exercicio!=NULL){
                if(contadorExercicios[exercicio->id]==1){
                    printf("%s",exercicio->id);
                }
                exercicio=exercicio->prox;
            }


        }

    }
    free(contadorExercicios);

}


typedef struct valor no, *pno;
struct valor{
    int num;
    pno dir, esq;
};


int verifica(pno tree1,pno tree2){
    if(tree1==NULL && tree2==NULL){
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }
    if(tree1->num!=tree2->num){
        return 0;

    }
   return verifica(tree1->esq,tree2->esq) && verifica(tree1->dir,tree2->dir);


}


int main() {

    return 0;
}
