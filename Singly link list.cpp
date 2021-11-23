#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

class linked_list
{
  private :
  node *head,*tail;  
  public:
  linked_list()
  {
      head = NULL;
      tail=NULL;
  }
  
  node* gethead()
  {
      cout<<"head value is: "<<head->data<<endl;
      cout<<"head address is: "<<head<<endl;
      return head;
  }
  
  node* getnode(int n)
  {
      node*ptr;
      ptr=head;
      while(ptr!=NULL)
      {
          if(ptr->data == n)
          {
              break;
          }
          else
          {
              ptr=ptr->next;
          }
      }
      return ptr;
  }
  
  static void display_rec(node *head)
    {
        if(head==NULL)
        {
            cout<<"NULL\n\n"<<endl;
        }
        else
        {
            cout<<head->data<<endl;
            display_rec(head->next);
        }
    }
  
  node* gettail()
  {
      cout<<"tail value is: "<<tail->data<<endl;
      cout<<"tail address is: "<<tail<<endl;
      return tail;
  }
  
  void last(int n)
  {
      node*tmp=new node;
      if(head == NULL)
      {
        tmp->data=n;
        tmp->next=NULL;
        head = tmp;
        tail = tmp;
      }
      else
      {
          tmp->data=n;
          tmp->next=NULL;
          tail->next=tmp;
          tail=tail->next;
      }
  }
  
  void after(node*a,int n)
  {
      node*tmp=new node;
      tmp->data=n;
      tmp->next=a->next;
      a->next=tmp;
  }
  
  void front(int n)
  {
      node*tmp=new node;
      if(head == NULL)
      {
        tmp->data=n;
        tmp->next=NULL;
        head = tmp;
        tail = tmp;
      }
      else
      {
          tmp->data=n;
          tmp->next=head;
          head = tmp;
      }
  }
  
  void display_list()
  {
      node*tmp;
      tmp=head;
      if(tmp == NULL && tail == NULL)
      {
          cout<<"NULL\n\n"<<endl;
      }
      else
      {
          while(tmp!=NULL)
          {
              cout<<tmp->data<<endl;
              tmp=tmp->next;
          }
          cout<<"NULL\n\n"<<endl;
      }
  }
  
  
  void delete_head()
  {
      node*ptr = head;
      if(ptr==NULL)
      {
          cout<<"NULL\n\n";
      }
      else
      {
      head = ptr->next;
      }
  }
  void delete_tail()
  {
      node* curr,*prev;
      prev=NULL;
      curr = head;
      if(curr == NULL)
      {
          cout<<"NULL\n\n";
      }
      else
      {
      while (curr!=tail)
      {
          prev=curr;
          curr=curr->next;
      }
      tail = prev;
      prev->next = NULL;
      delete curr;
      }
  }
  
  void delete_data(int n)
  {
      node *curr,*prev;
      prev = NULL;
      curr = head;
      
      if(curr == NULL)
      {
          cout<<"NULL"<<endl;
      }
      else
      {
          while(curr->data != n && curr != NULL )
          {
              prev=curr;
              curr=curr->next;
          }
          if (prev == NULL)
          {
              head = curr->next;
              delete(curr);
          }
          else if(curr == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete(curr);
        }
          else 
          {
              prev->next = curr->next;
              curr->next = NULL;
          }
      }
      
  }
  
  void delete_node(int n)
  {
      node *curr,*prev;
      curr = head;
      prev = NULL;
      int i;
      if(curr==NULL)
      {
          cout<<"NULL"<<endl;
      }
      else
      {
        for(i=1;i<n;i++)
        {
              prev=curr;
              curr=curr->next;
        }
        if(prev == NULL)
        {
            head=curr->next;
            delete(curr);
        }
        else if(curr == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete(curr);
        }
        else
        {
            prev->next=curr->next;
            curr->next=NULL;
        }
      }
  }
  void search_data(int n)
  {
      node *ptr;
      ptr = head;
      int coun = 0;
      int node = 0;
      if(ptr == NULL)
      {
          cout<<"NULL";
      }
      else
      {
          do{

              node++;
              if(ptr->data == n)
              {
                  coun++;
                  cout<<node<<"\t"<<ptr->data<<endl;
              }
              ptr = ptr->next;
          }
          while(ptr != NULL);

          cout<<"total "<<coun<<endl;
      }
  }
  void reverse()
    {
        node * tmp = head;
        node *prevnode = head;
        node *current = head;
        node *nextnode = NULL;
        head = tail;
        while(prevnode != NULL)
            {
                prevnode = prevnode->next;
                current->next = nextnode;
                nextnode = current;
                current = prevnode;
            }
            tail = tmp;
    }

};
int main() {
    
    linked_list a;
    a.last(1);
    a.last(2);
    a.last(3);
    a.last(4);
    
    a.display_list();
    a.reverse();
    cout<<endl;
    a.display_list();
    //a.delete_tail();
    //a.display_list();
    cout<<endl;
    a.gethead();
    a.gettail();
    //a.display_list();
    
	return 0;
}