//
// Created by ASUS on 01/06/2023.
//
#include <stdio.h>
#include <string.h>

void mostraTxt(char *nome){
    FILE  *f;
    int c;
    f=fopen(nome,"r");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro");
        return;
    }
    while((c=fgetc(f))!=EOF)
        putchar(c);
    fclose(f);

}

void mostraTxtlinhas(char *nome){
    FILE *f;
    int linhas;

    f=fopen(nome,"r");
    int c;
    if(f==NULL){
        printf("Erro no acesso ao ficheiro");
        return;
    }
    while((c=fgetc(f))!=EOF   ){
        c++;
        putchar(c);
    }
    fclose(f);
}

void mostralinhas(char *nome,int linha){
    FILE *f;

    f=fopen(nome,"r");
    int c;
    if(f==NULL){
        printf("Erro no acesso ao ficheiro");
        return;
    }


}


void mostratudo(char *nome){
    FILE *f;
    int c;

   f= fopen(nome,"r");
   if(f==NULL){
       printf("Erro no acesso ao ficheiro");
       return;
   }

   while((c= fgetc(f))!=EOF){
       putchar(c);
   }
   fclose(f);
}


void mostra(char *nome){
    FILE *f;
    int totalA=0,totalProvas=0, peso[6]={0},i;


    f= fopen(nome,"r");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro");
        return;
    }
   fscanf(f,"%*[^:] : %d",&totalA);
    fscanf(f,"%*[^:] : %d",&totalProvas);
    fscanf(f,"%*[^:]: " );
    for(i=0;i<totalProvas;i++){
        fscanf(f,"%d",&peso[i]);
    }


    printf("%d\n%d\n",totalA,totalProvas);
    printf("%d",peso[i]);
    fclose(f);
}











