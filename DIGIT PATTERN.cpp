/*
n = 3    row = col = n*2 -  1
                row sp ep
3 3 3 3 3       1   1   5                  sp => row 
3 2 2 2 3       2   2   4                  ep => (row - 1) +1
3 2 1 2 3       3   3   3--------------------------------
3 2 2 2 3       4   2   4                   sp=>row - 1 + 1 
3 3 3 3 3       5   1   5                   ep=>row
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ,sp ,ep,row,term;
    cout<<"enter a number:- ";
    cin>>n;
    row = (n*2)-1;
    for(int i = 1;i <= row;i++)
    {
        if(i <= n)
        {
            sp = i;
            ep = (row - i) + 1;
        }
        else
        {
            ep = i;
            sp = (row - i) + 1;
        }
        term = n;
        for(int j=1;j<=row;j++)
        {
            cout<<term<<" ";
            if(j < sp)
            {
                term--;
            }
            else if(j >= ep){
                term++;
            }
        }
        cout<<endl;
    }

    cout<<"End of te programme..."<<endl;
    return 0;
}