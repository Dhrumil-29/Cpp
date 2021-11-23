/*
Tower of Hanoi by recursion

big disc is always below the small discs

no small disc is below its big discs

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void towerofhanoi(int n,char from_place,char end_place,char aux_place)
{
    if(n == 1)
    {
        cout<<"Move disc 1 from place "<< from_place<<" to place "<<end_place<<endl;
        
        return;
    }

    towerofhanoi(n-1,from_place,aux_place,end_place);
    cout<<"Move disc "<<n<<" from place "<<from_place<<" to place "<<end_place<<endl;
    towerofhanoi(n-1,aux_place,end_place,from_place);
}

int main() {

    int n;
    cout>>"How many Disc :- ";
    cin>>n;
    towerofhanoi(n,'a','b','c');
    return 0;
}