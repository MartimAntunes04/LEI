void escrever(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++)
    ;
    for(i--;i>=0;i--)
        putchar(s[i]);
}


void escreveLinha(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]== ' ')
        {

        putchar('\n');

        }
        else
        {
            putchar(s[i]);
        }
    }
}



int main()
{
    char s[30]=("Ola mundo cruel!");
    escrever(s);
    escreveLinha(s);
    return 0;
}
