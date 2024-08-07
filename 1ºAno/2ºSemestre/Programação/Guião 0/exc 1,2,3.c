int maior(int a[],int tam)
{
    int i,n=a[0];
    for(i=1;i<tam;i++)
    {
       if(a[i]>n)
            n=a[i];
    }
return n;
}

int posmaior(int a[],int tam)
{
    int i,n=a[0],posicao;
    for(i=1;i<tam;i++)
    {
        if(a[i]>n)
           posicao=i;
    }
return posicao;
}

int conta(int a[],int tam)
{
    int i,n=a[0],conta=1;
    for(i=1;i<tam;i++)
    {
        if(a[i]==n)
            conta++;
        else if(a[i]>n){
            n=a[i];
            conta=1;
        }
    }
return conta;
}


void main()
{

    int a[8]={1,2,1,2,4,9,9,1},tam=8;
    printf("Maior: %d",maior(a,tam));

    printf("\nPosmaior:%d",posmaior(a,tam));

    printf("\nConta: %d",conta(a,tam));

}
