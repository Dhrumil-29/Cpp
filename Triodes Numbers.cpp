/*
find out all possible 3 digits triodes numbers x that 2*x and 3*x are dstinct digits

x is between 100 - 999 but distinct so 102 - 987

total distinct numbers is 10 => 0 - 9

x = 3 digits
2x = 3 or 4 
3x = 3 or 4(2x is 4digits then 3x must be 4 digit)

x = 3 , 2x = 4 , 3x = 4 digits are not possible because total digits 11 > 10

so 2x must  in 3 digits.(x = 500 => 2x = 1000 so x < 500)

so final range of x = 102 - 498
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int x,i,n,digit;
    for(x = 102;x<499;x++)
    {
        int arr[10] = {0};//for counting digits
        for(i = 1;i<4;i++)
        {
            n = i*x;
            while(n != 0)
            {
                digit = n%10;
                if(arr[digit] != 0)
                {
                    break;
                }
                else
                {
                    arr[digit]++;
                }
                n /= 10;
            }
            if(n!=0)
            {
                break;
            }
        }
        if(i == 4)
        {
            cout<<"x = "<<x<<"\t 2x = "<<2*x<<"\t 3x = "<<3*x<<endl;
        }
    }
    return 0;
}