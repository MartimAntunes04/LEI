#include <stdio.h>
#include <string.h>
struct cliente{
    char nome[200];
    char morada[200];
    int conta;
    int montante;
};


void mostra(char *nomeFicheiro) {
    FILE *f;
    struct cliente c;

    f = fopen(nomeFicheiro, "rb");
    if (f == NULL) {
        printf("Erro");
        return;
    }
    while (fread(&c, sizeof(struct cliente), 1, f) == 1) {
        printf("%s\n %s\n %d \n%d\n", c.nome, c.morada, c.conta, c.montante);
    }
    fclose(f);

}
 void elimina(char *nomeFicheiro,char *nome_cliente){
     FILE *f,*novoArquivo;
     struct cliente c;
     f=fopen(nomeFicheiro,"rb+");
     if(f==NULL){
         printf("Erro");
     }
     novoArquivo = fopen("temp.bin", "wb");
     if (novoArquivo == NULL) {
         printf("Erro ao criar o novo arquivo.\n");
         fclose(novoArquivo);
         return;
     }
     while(fread(&c,sizeof(struct cliente),1,f)==1){
         if(strcmp(nome_cliente,c.nome)!=0){
             fwrite(&c,sizeof(struct cliente),1,f);
         }
     }
    fclose(f);
     fclose(novoArquivo);

     remove(nomeFicheiro);
     rename("temp.dat",nomeFicheiro);

 }



int main() {

    mostra("Ex10_clientes1.dat");


    return 0;
}
