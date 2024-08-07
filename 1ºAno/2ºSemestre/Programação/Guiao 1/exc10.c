#include <stdio.h>


int tres_consecutivos(char *frase)
{
    int i;
    for(i=0;frase[i]!='\0';i++){
        if(frase[i]==frase[i+1]&& frase[i+1]==frase[i+2]){
        return 1;
        }

}
return 0;
}
void main()
{
    char frase[50];
    printf("Frase: ");
    gets(frase);

    printf("%d",tres_consecutivos(&frase));
}
