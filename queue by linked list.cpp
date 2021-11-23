#include <iostream>
#include <stdio.h>
//#include <conio.h>
using namespace std;

struct node{
    int data;
    node *next;
};

class queue1
{
  private:
    node *front1,*rear;
    public:
        queue1()
        {
            front1= NULL;
            rear = NULL;
        }

        void add(int n)
        {
            node *tmp = new node;
            if(front1 == NULL)
            {
                tmp->data = n;
                tmp->next = NULL;
                front1 = tmp;
                rear = tmp;
            }
            else
            {
                tmp->data = n;
                rear->next = tmp;
                tmp->next = NULL;
                rear = tmp;
            }
        }
        void get_front()
        {
            if(front1 == NULL)
                cout<<"NULL";
            else
                cout<<front1->data<<endl;
        }
        void get_rear()
        {
            if(rear == NULL)
                cout<<"NULL";
            else
                cout<<rear->data<<endl;
        }
        void delete_node()
        {
            node *tmp = new node;
            tmp = front1;
            if(tmp == NULL)
            {
                cout<<"\n EMPTY QUEUE"<<endl;
            }
            else if(tmp == rear)
            {
                cout<<"\ndeleted node value is:  "<<front1->data<<endl;
                front1 = tmp->next;
                rear = NULL;
            }
            else
            {
                cout<<"\ndeleted node value is:  "<<front1->data<<endl;
                front1 = front1->next;
            }
        }
        void show()
        {
            node *tmp = new node;
            tmp = front1;
            if(front1 == NULL)
            {
                cout<<"\n EMPTY QUEUE"<<endl;
            }
            else
            {
                while (tmp != NULL)
                {
                    cout<<tmp->data<<" ";
                    tmp=tmp->next;
                }
            }
        }
};

int main() {
    int n,choice,i;
    printf("\n1. create queue");
    printf("\n2. exit");
    cin>>choice;
    queue1 q;

    if(choice == 1)
    {
        while(2)
        {
            printf("\n\n\n1. enqueue");
            printf("\n2. dequeue");
            printf("\n3. show queue");
            printf("\n4. front");
            printf("\n5. rear");
            printf("\n6. exit\n");
            cin>>i;

            switch(i)
            {
                case 1:
                    printf("\nenter a value:  ");
                    cin>>n;
                    cout<<".."<<endl;
                    q.add(n);
                    break;
                case 2:
                    q.delete_node();
                    break;
                case 3:
                    q.show();
                    break;
                case 4:
                    q.get_front();
                    break;
                case 5:
                    q.get_rear();
                    break;
                case 6:
                    return 0;
                default:
                    cout<<"\nInvailid Choice"<<endl;
            }
        }
        fflush(stdin);
    }

	return 0;
}
