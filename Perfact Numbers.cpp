/*
perfact numbers = sum of their factor number exxclude that number

6 = 1 + 2 + 3
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,sum = 0;
    cout<<"Enter a number :- ";
    cin>>n;

    for(int i = 1;i<=ceil(n/2);i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }
    if(n == sum)
    {
        cout<<"n = "<<n<<" is a perfact number..."<<endl;
    }
    else
    {
        cout<<"n = "<<n<<" is not a perfact number..."<<endl;
    }
    return 0;
}