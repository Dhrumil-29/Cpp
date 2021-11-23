#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//0 for  green 
//1 for yellow
//2 for red

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_colours(int arr[],int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high)
    {
        switch(arr[mid])
        {
            case 0:
                {
                    swap(&arr[mid],&arr[low]);
                    mid = mid + 1;
                    low = low + 1;
                    break;
                }
            case 1:
                {
                    mid = mid + 1;
                    break;
                }
            case 2:
                {
                    swap(arr[mid],arr[high]);
                    high = high - 1;
                    break;
                }
        }
    }
}


void print_array(int arr[],int n)
{
    cout<<"\noutput :- \t";
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            cout<<"Green ";
        }
        else if(arr[i] == 1)
        {
            cout<<"Yellow ";
        }
        else if(arr[i] == 2)
        {
        cout<<"Red ";
        }
    }
}
int main() {
    int n;
    char a;
    cout<<"please enter g : green , r : red , y : yellow"<<endl;
    cout<<"Enter how many times you wants to enter the colours : ";
    cin>>n;
    int arr[n];
    for(int i = 0 ;i<n;i++)
    {
        cin>>a;
        if(a == 'g')
            arr[i] = 0;
        else if(a == 'y')
            arr[i] = 1;
        else if(a == 'r')
            arr[i] = 2;
        
    }
    n = sizeof(arr)/sizeof(arr[0]);
    sort_colours(arr,n);
    print_array(arr,n);
	return 0;
}