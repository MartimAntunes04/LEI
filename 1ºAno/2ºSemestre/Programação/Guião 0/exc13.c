void igual(char st1[],char st2[], char st3[])
{
    if(strcmp(st1,st2)==0)
        strcpy(st3,"IGUAIS");

    else if(strlen(st1)==strlen(st2))
        strcpy(st3,"TAM IGUAL");

    else if(strcmp(st1,st2)<0){
        strcpy(st1,st2);
        strcat(st3,st2);
    }
    else{
        strcpy(st3,st2);
        strcat(st3,st1);
    }
}


int main()
{
    char st1[10]="AAA",st2[10]="BBBB",st3[20];
    igual(st1,st2,st3);
    puts(st3);
}
