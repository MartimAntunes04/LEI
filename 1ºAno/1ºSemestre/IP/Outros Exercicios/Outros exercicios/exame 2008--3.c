#include <stdio.h>

void main()
{
    int prateleiras_livros[6],i,prateleiras_dossiers[6],media_livros,soma_livros=0,conta_livros=0,soma_dossiers=0,conta_dossiers=0,media_dossiers;

    for(i=1;i<6;i++)
    {

            printf("prateleiras/livros[%d]: ",i);
            scanf("%d",&prateleiras_livros[i]);

            soma_livros+=prateleiras_livros[i];
            conta_livros++;

            printf("prateleiras/dossiers[%d]: ",i);
            scanf("%d",&prateleiras_dossiers[i]);

            soma_dossiers+=prateleiras_dossiers[i];
            conta_dossiers++;

    }
    media_livros=soma_livros/conta_livros;
    media_dossiers=soma_dossiers/conta_dossiers;

    printf("\nMedia dos livros na estante:%d",media_livros);
    printf("\nMedia dos dossiers na estante: %d",media_dossiers);


    if(soma_livros<media_livros)
        {
        printf("Prateleira com um número de livros inferior a media dos livros da estante");
        }
    else if(soma_livros=media_livros)
    {
        printf("Prateleira com um número de livros igual a media dos livros da estante ");
    }
    else if(soma_livros>media_livros)
        printf("Prateleira com um número de livros superior a media dos livros da estante");





}
