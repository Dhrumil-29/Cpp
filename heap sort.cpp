#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void check(int arr[],int n)//1935 4
{
    int i,temp;
    i=n/2;//2
    
        while(i!= 0)
        {
            if(arr[i-1] > arr[n-1])//9>5
            {
                temp = arr[i-1];
                arr[i-1] = arr[n-1];
                arr[n-1] = temp;
            }
           i=i/2;//0//1
        }
    
    
}

void heap_sort(int arr[],int n)
{
    int i,j,sorted_arr[n]={0},temp[n]={0};
    
    for(i=0;i<n;i++)
    {
        temp[i] = arr[i];
    }
    
    for(i=0;i<n;i++)
    {
        for(j=n-i;j>1;j--)
        {
            check(temp,j);
        }
        

        sorted_arr[i] = temp[0];
        temp[0] = temp[n-i-1];
        
    }
    
    for(i=0;i<n;i++)
    {
        cout<<sorted_arr[i]<<" ";
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,n;
    cin>>n;
    int arr[n];
    
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    
    heap_sort(arr,n);
    return 0;
}