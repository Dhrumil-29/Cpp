#include<stdio.h>

int main() {
long int n;
long int i,year=0;
scanf("%ld",&n);
while(n>0)
{
for(i=1;i<=4;i++)
{
    if(n>0 && i!=4)
    {
    year++;
    n=n-365;
    }
    if(n>0 && i==4) 
    {
    year++;
    n=n-366;
    }
}
    
}
printf("%ld",year);
    return 0;
}
    