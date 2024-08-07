#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id; //id único do colaborador
    char nome[50];
    float latBase,longBase; //latitude e longitude do seu local base
    int ativo; //1 se o colaborador está ao serviço ou 0 se não está
} Colab, *pColab;



pColab colaboradores(char *nomeFicheiro,int *tam){

    FILE *f;
    f=fopen(nomeFicheiro,"rb");
    if(f==NULL){
        return NULL;
    }
    pColab vetorColaboradores=NULL;
    Colab c;
    int numerocolaboradores=0;
    while(fread(&c,sizeof(Colab),1,f)==1){
            numerocolaboradores++;
            if(c.ativo==1){
                vetorColaboradores=realloc(vetorColaboradores,sizeof (Colab)*(*tam+1));
                if(vetorColaboradores==NULL){
                    fclose(f);
                    free(vetorColaboradores);
                    return NULL;
                }
               tam++;
                 vetorColaboradores[*tam]=c;
        }

    }
    fclose(f);
    *tam=numerocolaboradores;
    return vetorColaboradores;


}

void trotinetes(char *nomeFicheirotxt,char *nomeFicheirobin){

    FILE *ftxt,*fbin,*ftxtavarias,*ftxtrecargas;

    ftxt=fopen(nomeFicheirotxt,"r");
    if(ftxt==NULL){
        return;
    }
    fbin=fopen(nomeFicheirobin,"rb");
    if(fbin==NULL){
        fclose(ftxt);
        return;
    }

    ftxtavarias=fopen("avarias.txt","w");
    if(ftxtavarias==NULL){
        fclose(ftxt);
        fclose(fbin);
        return;
    }

    ftxtrecargas=fopen("avarias.txt","w");
    if(ftxtrecargas==NULL){
        fclose(ftxt);
        fclose(fbin);
        fclose(ftxtavarias);
        return;
    }

    char estado[10];
    float latitude,longitude;
    int id,carga;
    Colab c;

    while(fscanf(ftxt,"%d %f %f %d %s",&id,&latitude,&longitude,&carga,estado)==5){
            if(strcmp(estado,"avarias")==0 || strcmp(estado,"alarme")==0){
                fprintf(ftxtavarias,"%d %f %f %s",id,latitude,longitude,estado);
            }
            else if(strcmp(estado,"ok")==0 && carga<60) {

                while (fread(&c, sizeof(Colab), 1, fbin) == 1) {
                        if(c.ativo==1 ){
                            float dist(float latA, float longA, float latB, float longB);
                        }
                }
            }
    }



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


void treino(pCliente p,int tam){

   int conta=0;
    for(int i=0;i<tam;i++){
        pExercicio exercicios=p[i].treino;
        while(exercicios!=NULL){
            conta++;
        }
        if(conta==1){
            printf("%s",exercicios->id);
    }


    }
}




pCliente criaED(pCliente p, int dim, int* nDim, int d, int m, int a){

    for(int i=0;i<dim;i++){
        if(p[i].dia > d || (p[i].dia == d && p[i].mes > m) || (p[i].dia == d && p[i].mes == m && p[i].ano > a){
            (*nDim)++;
        }
    }

    pCliente novo=malloc(sizeof(Cliente)*(*nDim));
    if(novo==NULL) {
        return NULL;
    }

    for(int i=0;i<dim;i++){
        if (a[i].dia > d || (a[i].dia == d && a[i].mes > m) || (a[i].dia == d && a[i].mes == m && a[i].ano > a)){
            novo
        }
    }

}


int main() {

    return 0;
}
