#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct paciente Paciente, *pPaciente;
typedef struct internamento Inter, *pInter;
typedef struct {int dia, mes;} data;
struct paciente{
    int id; // Identificador único
    char nome[100]; // Nome do paciente
    int ninternamentos; // Número de internamentos nesse ano
    pInter lista; // Ponteiro para a lista de internamentos
};
struct internamento{
    data din; // Data de entrada
    int nDias; // Número de dias internado
    pInter prox;
};


int pacienteComMaisDiasInternamento(pPaciente pacientes, int dimensao) {
    int pacienteID = -1;
    int maxDias = -1;

    for (int i = 0; i < dimensao; i++) {
        int pacienteAtualID = pacientes[i].id;
        int diasInternados = 0;

        pInter interAtual = pacientes[i].lista;
        while (interAtual != NULL) {
            if (interAtual->nDias >= 0) {
                diasInternados += interAtual->nDias;
            }
            interAtual = interAtual->prox;
        }

        if (diasInternados > maxDias) {
            maxDias = diasInternados;
            pacienteID = pacienteAtualID;
        }
    }

    return pacienteID;
}

pPaciente elimina(pPaciente v, int *nPaciente, int id){


    for(int i=0;i<nPaciente;i++) {
        if(v[i].id==id){
            pInter interatual=v[i].lista;
            while(interatual!=NULL){
                pInter prox=interatual->prox;
                free(interatual);
                interatual=prox;
            }

            for(int j=i;j<nPaciente-1;j++){
                v[j]=v[j+1];
            }
            nPaciente--;
        }
        v=realloc(v,*nPaciente*(sizeof(Paciente)));
        return v;


    }

}


typedef struct pcce{
    int id;
    float lat, lon;
    int minutos;
    float potencia;
    int estado;
} PCCE, *pPCCE;


void atualizar(char *nomeficheirobinario,char*nomeficheirotxt){
    FILE *fbinario=fopen(nomeficheirobinario,"wb");
    if(fbinario==NULL){
        printf("Erro a abrir ficheiro");
        return;
    }

    FILE *ftxt=fopen(nomeficheirotxt,"r");
    if(ftxt==NULL){
        printf("Erro a abrir ficheiro");
        return;
    }
    PCCE carro;
    int encontrado=0;
    while(fread(&carro,sizeof (PCCE),1,fbinario)==1) {
        encontrado=0;
        int id, estado, minutos;
        while (fscanf(ftxt, "%d %d %d", &id, &estado, &minutos) == 3) {
            if(id==carro.id){
                carro.estado=estado;
                carro.minutos+=minutos;
                encontrado=1;
                break;
            }


        }
        fseek(fbinario,sizeof (PCCE),SEEK_SET);
        fwrite(&carro,sizeof(PCCE),1,fbinario);
    }

    fclose(fbinario);
    fclose(ftxt);
}


int main() {

    return 0;
}
