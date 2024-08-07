#include <stdio.h>
int main()
{

int d, m, a;

printf("data dd/mm/aa: ");
scanf ("%d/%d/%d", &d,&m,&a);

if((d==28&&m==2) || (d==30&& (m==4||m==6||m==9||m==11))||(d==31&&m!=12))
{
    d=1;
    m++;//m=m+1;

}
else if (d==31&&m==12)
{
    d=1;
    m=1;
    a++;
}
 else
 {
     d=d+1;
 }
printf("data dia seguinte: %d/%d/%d", d,m,a);
}






