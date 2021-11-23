#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
//find the median
int findMedian(int arr[],int n)
{
    //first sort 5 element in constant time
    sort(arr,arr+n);
    //and return the mid element
    return arr[n/2];
}


int partition(int arr[],int l,int r, int k)
{
    //first MoM element mov to the last element
    int i;
    for(i=l;i<r;i++)
    {
        if(arr[i] == k)
        break;
    }
    swap(&arr[i],&arr[r]);
    //Now partition in left and right sides
    i = l;
    for(int j=l;i<r;i++)
    {
        if(arr[j] <= k)
        {
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}

//swap  function
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int k_element(int arr[],int l,int r,int k)
{
    //if k>0 and k<n then fide element else return 0
    if(k > 0 && k<=r-l+1 )
    {
        //find total element
        int n = r-l+1;
        //n+4 take because if element is 6 than size is 2 and (n+4/5) floor element
        int median[(n+4/5)];
        for(int  i=0;i<n/5;i++)
        {
            median[i] = findMedian(arr+l+i*5,5);
        }
        //for last column's median
        if(i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5,n%5);
            i++;
        }
        //if 1 column in find median than MoM is median else find median of median by recursion 
        int MoM = (i == 1) ? median[i-1]:k_element(median,0,i-1,i/2);
        //After getting MoM partition in left and right
        int pos = partition(arr,l,r,MoM);
        
        //if kth element is position then return pos element
        if(pos-l == k-1)
            return arr[pos];
        //if k<left side elements then find kth element by recursion else in right side elements
        if(pos-l > k)
            return k_element(arr,l,pos-1,k);
        else    
            return k_element(arr,pos+1,r,k-pos+l-1);
    }
    
}
int main() {
    int n,k;
    //Get inputs by users
    cout<<"How many numbers you want to enter : - ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n which smallest element you want : - ";
    cin>>k;
    cout<<"\n"<<k<<"th smallest element is :- "<<k_element(arr,0,n-1,k);
    
	return 0;
}