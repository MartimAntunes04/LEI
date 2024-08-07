#include <stdio.h>
int CalculaIMC(float peso, float altura)
{
    return (peso/altura*altura);
}

void main()
{

    float peso, altura,i;

    printf ("Peso: ");
    scanf("%f",&peso);
    printf ("Altura: ");
    scanf ("%f",&altura);

    i=CalculaIMC(peso,altura);

    if (i<=18.5)
    {
        printf ("Abaixo do  peso normal");
    }

    else
    {
        if (i<=25)
        {
            printf ("Peso normal");
        }

        else
            if(i<=30)
        {
            printf ("Acima do peso normal");
        }

        else
        {
            printf ("Obesidade");
        }
    }





}
