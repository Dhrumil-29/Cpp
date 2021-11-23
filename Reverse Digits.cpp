#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,reverse_num = 0,i = 0,digit;
    cout<<"enter a number:- ";
    cin>>n;
    cout<<"Original Number = "<<n;
    while(n != 0 )
    {
        digit = n%10;
        n/=10;
        reverse_num = reverse_num*10 + digit;
    }
    cout<<"\tReverse number = "<<reverse_num<<endl;
    cout<<"End of a programme..."<<endl;
    return 0;
}