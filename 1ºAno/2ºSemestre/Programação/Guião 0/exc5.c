int pesquisa(int a[],int tam,int n)
{
    int i,x;

    for(i=0;i<tam && a[i]<=n;i++)

        if(a[i]==n)

             return 1;

    return 0;



}

void main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10},n,tam=10;
    printf("Numero: ");
    scanf("%d",&n);
    printf("%d",pesquisa(a,tam,n));
}
