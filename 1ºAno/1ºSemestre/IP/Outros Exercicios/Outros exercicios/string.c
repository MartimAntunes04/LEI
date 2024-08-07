#include <stdio.h>
#include <string.h>

void main()
{


char s1[20],s2[20];


printf("s1: ");
gets(s1);
printf("s2: ");
gets(s2);

if(strcmp(s1,s2)==0)
{
    printf("\nStrings iguais");
}
else
{
    strcat(s1,s2);
    printf("\n%s",strcat(s1,s2));
}
}
