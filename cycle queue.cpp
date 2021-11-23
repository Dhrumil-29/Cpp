#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
using namespace std;

//struct Arryqueue {
//    struct Arryqueue *a;
//};

class queue1
{
private:
    int capacity;
    int front1,rear;
    int *f;
public:
    queue1()
    {
        front1 = -1;
        rear = -1;
        capacity = 0;
    }
    void set_capacity(int n)
    {
        capacity = n;
    }
    void create_queue(int n)
    {
        //Arrayqueue *arr = new Arrayqueue;
        int *arr = (int *)malloc(capacity * sizeof(int));
        if(is_full())
        {
            cout<<"is full"<<endl;
        }
        else
        {
            rear = rear+1%capacity;
            arr[rear] = n;
            if(front1 == -1)
                front1 = rear;
        }
        f = arr;
    }
    void enqueue(int n)
    {
        int *arr = (int *)malloc(capacity * sizeof(int));
        //int *arr = f;

        if(is_full())
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
            rear = rear+1%capacity;
            arr[rear] = n;
            if(front1 == -1)
                front1 = rear;
            f = arr;
        }

    }

    void display()
    {
        int *arr = f;
        int i=front1;
        if(front1 == -1)
        {
            cout<<"Empty queue"<<endl;
        }
        else
        {
            while(i != rear+1)
            {
                cout<<arr[i]<<" ";
                i = i+1%capacity;
            }
        }
    }

    void dequeue()
    {
        int *arr;
        arr = f;
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
        }
        else
        {
            cout<<"delete value is "<<arr[front1]<<endl;
            front1 = front1+1%capacity;
            if(front1 == rear)
                front1 = rear = -1;
            f = arr;
        }
    }
    int is_full()
    {
        if((rear+1%capacity) == front1)
            return 1;
        else
            return 0;
    }
    int isEmpty()
    {
        if(front1 == -1)
            return 1;
        else
            return 0;
    }
    int total_element()
    {
        return((capacity-front1+rear+1)%capacity);
    }

};
main()
{
    int choice,n;
    printf("\n1.create queue");
    printf("\n2.exit\n");
    cin>>choice;
    if(choice == 2)
        return 0;
    else{
        queue1 q;
        printf("\nenter capicity of queue\n");
        cin>>n;
        q.set_capacity(n);
        while(1)
        {
            printf("\n1.enqueue");
            printf("\n2.dequeue");
            printf("\n3.show how many element");
            printf("\n4.display");
            printf("\n5.exit");
            cin>>choice;
            switch(choice)
            {
            case 1:
                printf("\nenter value:  ");
                cin>>n;
                q.enqueue(n);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout<<"total element in queue is "<<q.total_element()<<endl;

                break;
            case 4:
                q.display();
                break;
            case 5:
                return 0;
            default:
                cout<<"Invailide Choice\n";
            }


        }
    }

    return 0;
}
