#include <stdio.h>

void mostra(char *nomeFicheiro){
    FILE *f;
    int c;

    f=fopen(nomeFicheiro,"r");
    if(f==NULL)
        printf("Erro");
    while((c=fgetc(f))!=EOF)
        putchar(c);
    fclose(f);
}

void calcula_notas(char *nomeFicheiro){
    FILE *f;
    int num_alunos,i,num_provas,pesos[5],notas[5];
    float notafinal;

    f=fopen(nomeFicheiro,"r");
    if(f==NULL)
        printf("Erro");
    fscanf(f,"Numero de alunos: %d",&num_alunos);
    fscanf(f,"Numero de provas:%d",&num_provas);
    fscanf(f,"Peso das provas: %d %d %d %d %d",&pesos[0],&pesos[1],&pesos[2],&pesos[3],&pesos[4]);


     printf("\nNumero de alunos: %d",num_alunos);
    for(i=0;i<num_alunos;i++){
        fscanf(f,"Aluno %*d:");
        notafinal=0;
        for(int j=0;j<num_provas;j++){
            fscanf(f,"%d",&notas[j]);
            notafinal+=notas[j]*pesos[j];
        }
        notafinal/=100;
        printf("\nAluno %d: %.2f%%",i+1,notafinal);
    }
    fclose(f);
}1



int main() {
    mostra("notas_ex9.txt");
    calcula_notas("notas_ex9.txt");
    return 0;
}
