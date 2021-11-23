#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class linked_list
{
    private:
        node *head,*tail;
        
        public:
        
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }
        
        void add_first(int n)
        {
            if(head == NULL)
            {
                node *tmp;
                tmp = new node;
                tmp->data = n;
                tmp->next = NULL;
                head = tmp;
                tail = tmp;
            }
            else
            {
                node *tmp;
                tmp = new node;
                tmp->data = n;
                tmp->next = head;
                head = tmp;
            }
        }
        
        void add_last(int n)
        {
            if(head == NULL)
            {
                node *tmp;
                tmp = new node;
                tmp->data = n;
                tmp->next = NULL;
                head = tmp;
                tail = tmp;
            }
            else
            {
                node *tmp;
                tmp = new node;
                tmp->data = n;
                tail->next = tmp;
                tmp->next = NULL;
                tail = tmp;
            }
        }
        
        void delete_first()
        {
            if(head == NULL)
            {
                cout<<"\nempty queue";
            }
            else
            {
                node *tmp;
                tmp = head;
                head = head->next;
                delete(tmp);
            }
        }
        
        void delete_last()
        {
            if(tail == NULL)
            {
                cout<<"\nempty stack";
            }
            else
            {
                node *curr,*prev;
                curr = head;
                prev = NULL;
                while(curr->next != NULL)
                {
                    prev = curr;
                    curr = curr->next;
                }
                tail = prev;
                delete(curr);
            }
        }
        
        void display()
        {
            node *tmp = head;
            if(head == NULL)
            {
                cout<<"\nE M P T Y";
            }
            else
            {
                while(tmp != NULL)
                {
                    cout<<endl<<tmp->data<<"\t";
                    tmp = tmp->next;
                }
            }
        }
        //virtual void pop()=0;
        //virtual void push(int)=0;
        //virtual void show()=0;
};

class link_stack : public linked_list
{
    public:
    int count1 = 0;
    
    void push(int n)
    {
        add_first(n);
        count1++;
    }
    void pop()
    {
        delete_last();
        count1--;
    }
    void show()
    {
        cout<<"number of element in stack is "<<count1<<endl;
    }
};

class link_queue : public linked_list
{
    public:
  int count2 = 0;
  
  void push(int n)
  {
      add_last(n);
      count2++;
  }
  void pop()
  {
      delete_first();
      count2--;
  }
  void show()
    {
        cout<<"number of element in queue is "<<count2<<endl;
    }
};

int main() {
    link_queue q;
    int n,i,a,b;
    cout<<"\nenter 1 or 2 for create linked list\n1. stack\n2.queue\n";
    cin>>a;
    while(1)
    {
        if(a == 1)
        {
            link_stack s;
            cout<<"\nenter your choice\n1.push\n2.pop\n3.show\n4.exit\n";
            cin>>b;
            if(b == 1)
            {
                cout<<"\nenter data: \n";
                cin>>n;
                s.push(n);
            }
            else if(b == 2)
            {
                s.pop();
            }
            else if(b == 3)
            {
                s.show();
            }
            else if(b == 4)
            {
                exit(0);
            }
            else 
            {
                cout<<"\ninvalide choice";
            }
        }
        else if(a == 2)
        {
            link_queue q;
            cout<<"\nenter your choice\n1.push\n2.pop\n3.show\n4.exit\n";
            cin>>b;
            if(b == 1)
            {
                cout<<"\nenter data: \n";
                cin>>n;
                q.push(n);
            }
            else if(b == 2)
            {
                q.pop();
            }
            else if(b == 3)
            {
                q.show();
            }
            else if(b == 4)
            {
                exit(0);
            }
            else 
            {
                cout<<"\ninvalide choice";
            }
        }
    }
	return 0;
}