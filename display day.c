#include <stdio.h>

int main() {

int day,month,year,sod,sum=0,i;
scanf("%d %d %d",&day,&month,&year);
int y,m;
y=year-1;
m=month-1;
int l=0;
for(i=1;i<=y;i++)
{
    if ((i%4 == 0 || i%400 == 0) && i%100 != 0)
    {
        l++;
    }
}
int n;
n=(y-l)*365+l*366;
for(i=1;i<=m;i++)
{
    if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
    {
      sod=31;  
    }
    else if(i==4 || i==6 || i==9 || i==11)
    {
        sod=30;
    }
    else if ( (year%4 == 0 || year%400 == 0) && year%100 != 0)
    {
        sod=29;
    }
    else
    {
        sod=28;
    }
    sum=sod+sum;
}
long int total;
total=sum+n+day;
switch(total%7)
{
    case 2:
    {
        printf("Sunday");
        break;
    }
    case 3:
    {
        printf("Monday");
        break;
    }
    case 4:
    {
        printf("Tuesday");
        break;
    }
    case 5:
    {
        printf("Wednesday");
        break;
    }
    case 6:
    {
        printf("Thursday");
        break;
    }
    case 0:
    {
        printf("Friday");
        break;
    }
    case 1:
    {
        printf("Saturday");
        break;
    }
    
    
    
    
}


    return 0;
}
