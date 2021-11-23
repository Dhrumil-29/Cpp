#include <stdio.h>

int main() {
int i,j,l,m,n;
scanf("%d",&n);
m=n;
for(i=1;i<=n;i++)
{
    m=n;
    for(j=1;j<=(2*n-1);j++)
    {
        if(i+j>(2*n))
        printf ("%3d",++l);
        
       else if(i>j)
        {
            l=m+1-j;
            printf ("%3d",l);
        }
        
       else if(i<=j)
        {
            l=m+1-i;
            printf ("%3d",l);
        }
    }
printf ("\n\n");
}

for(i=n-1;i>=1;i--)
{
    m=n;
    for(j=1;j<=(2*n-1);j++)
    {
        if(i+j>(2*n))
        printf ("%3d",++l);
        
       else if(i>j)
        {
            l=m+1-j;
            printf ("%3d",l);
        }
        
       else if(i<=j)
        {
            l=m+1-i;
            printf ("%3d",l);
        }
    }
printf ("\n\n");
}


    return 0;
}