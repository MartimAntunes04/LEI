#include <stdio.h>
int main()
{

float peso_inserido, peso_somado=0, contador_media=0, peso_max=0, peso_medio;
do{

printf ("Peso: ");
scanf ("%f",&peso_inserido);

if (peso_inserido>=60)
{
   peso_somado+=peso_inserido;
   contador_media=contador_media+1;
}
else{
if (peso_inserido>peso_max)

   peso_max=peso_inserido;

}
}
while (peso_inserido>0);

peso_medio=peso_somado/contador_media;
printf ("Media=%f e max=%f", peso_medio,peso_max);
}
