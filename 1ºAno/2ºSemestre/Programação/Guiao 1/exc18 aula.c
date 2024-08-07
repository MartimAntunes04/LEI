#include <stdio.h>
#include <string.h>



void tradutor(char st[])
{
    char *pt[]={"Janeiro","Fevereiro","Marco","Abril"};
    char *eng[]={"January","February","March","April"};
    int i;
    for(i=0;i<4;i++)
    if(strcmp(st,pt[i])==0){
        printf("%s- %s",st,eng[i]);
        return;

    }
printf("Mes %d invalido\n",st);
}
   void main()
   {
       char st[30];
       printf("Mes: ");
       gets(st);

   }


