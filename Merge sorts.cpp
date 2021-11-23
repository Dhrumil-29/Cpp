#include <iostream>
#include <stdio.h>
using namespace std;

void mergesort(int arr[],int n,int total)
{
    int j,k,i,r,combi,compare,z,w;
    k=0;
    combi = n/total;
    r = n-(combi*total);
    compare = total/2;
    while(k<n-r)
    {
        i=k;
        j = k+compare;

        while(i<(compare+k))
        {
            if(arr[i]<=arr[j])
            {
                i++;
            }
            else
            {

                swap(arr[i],arr[j]);
                //z=j;
                if(j+1<(k+(2*compare)) && arr[j]>arr[j+1])
                {
                    for(w=(k+(2*compare)-1);w>j;w--)
                        {
                            if(arr[j]>arr[w])
                                {
                                    swap(arr[j],arr[w]);
                                }
                        }
                }
                i++;
            }
        }


        k = k + total;
    }


    for(i=n-2;i>=(j-compare);i--)
    {
        if(arr[k]<arr[i])
        {
            swap(arr[k],arr[i]);
            k=i;
        }
    }
}

int main() {
    int i,n,l;
    //enter a total umber of inputs;
    cin>>n;
    int arr[n];//create an array of size n

    //store value in array
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    i=2;

    while(n>1 && i<n)
    {
        mergesort(arr,n,i);
        i=i*2;
    }


    //display array
    cout<<endl;
        for(l=0;l<n;l++)
        {
            cout<<arr[l]<<" ";
        }

	return 0;
}
