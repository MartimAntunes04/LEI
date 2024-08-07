#include <stdio.h>
void main()
{

float notas[20];media=0
int i;
for(i=0;i<20;i++)
{

printf("Notas %d: ",i+1);
scanf("%f",&notas[i]);

}

for(i=0,i<20,i+1)
{
     media+=notas[i];


}
   media=media/20
   printf("media=%f",media)



}
