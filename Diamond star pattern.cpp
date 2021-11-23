/*

n = 5
row = (n*2)-1
                        i    .  *
. . . . *               1    4  1    
. . . * * *             2    3  3    . => n - 1
. . * * * * *           3    2  5    * => (i*2)-1
. * * * * * * *         4    1  7
* * * * * * * * *       5    0  9----------------------------
. * * * * * * *         6    1  7 
. . * * * * *           7    2  5    . => i - n 
. . . * * *             8    3  3    * => (n-i)*2 + 1
. . . . *               9    4  1
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout<<"enter a odd number : - ";
    int n,row,s,d;
    cin>>n;
    row = (n*2)-1;
    cout<<row<<endl;
    for(int i = 1;i <= row;i++)
    {
        if( i > n)
        {
            d = i - n;
            s = (row - i) * 2 + 1;
        }
        else
        {
            s = i*2 - 1;
            d = (n-i);
        }
        
        for(int j = 1;j<=d;j++)
        {
            cout<<"  ";
        }
        for(int k = 1; k <= s;k++)
        {
            cout<<"* ";
        }

        cout<<endl;
    }

    cout<<"End of the programme..."<<endl;
    return 0;
}