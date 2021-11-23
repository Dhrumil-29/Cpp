#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*Digit Root*/

int main() {
    int n;
    cout << "Enter a number :- ";
    cin>>n;
    int sum = 0;
    
    do
    {
        sum = 0;
        while(n != 0)
        {
            sum += (n%10);
            n /= 10;
        }
        n = sum;
    }while(sum > 9);
    
    cout<<"Digit Root = "<<sum<<endl;
    return 0;
}