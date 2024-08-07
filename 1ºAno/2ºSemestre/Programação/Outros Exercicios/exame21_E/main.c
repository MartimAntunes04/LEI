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



int maisinternamentos(pPaciente p,int dimensao){
    int idPaciente;
    pPaciente aux=p;
    int maisdias=0;
    for(int i=0;i<dimensao;i++){
        pInter internamnetos=aux[i].lista;
        while(internamnetos!=NULL){
            if(internamnetos->nDias>maisdias){
                maisdias=internamnetos->nDias;
               idPaciente=aux[i].id;
            }
            if(internamnetos->nDias==-1){
                return -1;
            }
            if(internamnetos->nDias=maisdias){
                int maisbaixo;
                if(aux->id<maisbaixo){
                    return aux->id;
                }
            }
            internamnetos=internamnetos->prox;

        }


    }
return idPaciente;

}

pPaciente elimina(pPaciente v, int *nPaciente, int id){

    for(int i=0;i<nPaciente;i++){
        if(v[i].id!=id){
            return v;
        }
        else{

            pInter internamentos=v[i].lista;
            while(internamentos!=NULL){
                pInter temp=internamentos;
                internamentos=internamentos->prox;
                free(temp);

            }
            for (int j = i; j < *nPaciente - 1; j++) {
                v[j] = v[j + 1];}
            (*nPaciente)--;



        }
        v=realloc(v,sizeof (Paciente)*(*nPaciente));

    }
return v;


}

typedef struct pcce{
    int id;
    float lat, lon;
    int minutos;
    float potencia;
    int estado;
} PCCE, *pPCCE;



void carros(char *nomeFicheirotxt,char *nomeFicherirobin){

    FILE *fbin,*ftxt;

    fbin=fopen(nomeFicherirobin,"rb+");
    if(fbin==NULL){

        return;
    }

    ftxt=fopen(nomeFicheirotxt,"r");
    if(ftxt==NULL){
        fclose(fbin);
        return;
    }

    PCCE c;
    int id,estado,minutos;

    while(fread(&c,sizeof(PCCE),1,fbin)==1){
        while(fscanf(ftxt,"%d %d %d",&id,&estado,&minutos)==3){
            if(id==c.id){
                c.estado=estado;
                c.minutos=minutos;
                fseek(fbin,-sizeof (PCCE),SEEK_CUR);
                fwrite(&c,sizeof (PCCE),1,fbin);
            }
            else{
                return;
            }
        }
    }



    fclose(fbin);
    fclose(ftxt);
}





int main() {

    return 0;
}
