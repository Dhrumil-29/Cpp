#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);


        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i=n-1; i>0; i--)
    {
    
        swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void deleteRoot(int arr[], int& n)
{
    int lastElement = arr[n - 1];


    arr[0] = lastElement;


    n = n - 1;

    heapify(arr, n, 0);
}

void insertNode(int arr[], int& n, int Key)
{
    n = n + 1;

    arr[n - 1] = Key;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
int main()
{
    int i,n,choice;
    cout<<"Enter the number of the elements in array"<<"\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<"\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Choice 0 for heap sort ,1 for insertion, 2 for deletion "<<"\n";
    cin>>choice;
    switch(choice)
  {
    case 0:
        heapSort(arr,n);
        printArray(arr,n);
        break;

    case 1:
        int key;
        cout<<"Enter element to be inserted";
        cin>>key;
        insertNode(arr,n,key);
        printArray(arr,n);
        break;

    case 2:
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    deleteRoot(arr,n);
    printArray(arr,n);
  }
  return 0;
}