#include <stdio.h>
#define N 7
void main()
{

int num[N],i=0,conta=0,soma=0;
float media;

while(i<N)
{
    printf("num [%d]: ",i+1);
    scanf("%d",&num[i]);
    conta++;
    soma+=num[i];
    i++;


}

media=soma/conta;
printf("Media: %.2f",media);


for(i=0;i<N;i++)
{
    if(num[i]<media)
num[i]=0;
printf("\nnum[%d]=%d",i,num[i]);

}





}













