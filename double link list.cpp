#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

class double_link_list
{
  private:
  node *head,*tail;
  public:
  double_link_list()
  {
      head = NULL;
      tail = NULL;
  }
  
  node *gethead()
  {
      cout<<"\nhead value is: "<<head->data<<endl;
      cout<<"head address is: "<<head<<endl<<endl;
      return head;
  }
  
  node *gettail()
  {
      cout<<"\ntail value is: "<<tail->data<<endl;
      cout<<"head address is: "<<tail<<endl<<endl;
      return tail;
  }
  
  void add_last(int n)
  {
      node *tmp = new node;
      if(head == NULL)
      {
          tmp->data = n;
          tmp->next = NULL;
          tmp->prev = NULL;
          head = tmp;
          tail = tmp;
      }
      else
      {
          tmp->data = n;
          tmp->prev = tail;
          tmp->next = NULL;
          cout<<tmp->next<<endl;
          tail = tmp;
      }
  }
  void add_first(int n)
  {
      node *tmp = new node;
      if(head == NULL)
      {
          tmp->data = n;
          tmp->next = NULL;
          tmp->prev = NULL;
          head = tmp;
          tail = tmp;
      }
      else
      {
          tmp->data = n;
          tmp->next = head;
          tmp->prev = NULL;
          head = tmp;
      }
  }
  
  void add_after(node *a,int n)
  {
      node *tmp = new node;
      node *temp;
      if(head == NULL)
      {
          tmp->data = n;
          tmp->next = NULL;
          tmp->prev = NULL;
          head = tmp;
          tail = tmp;
      }
      else
      {
          temp = a->next;
          tmp->data = n;
          tmp->prev = a;
          tmp->next = temp;
          temp->prev = tmp;
      }
  }
  
  void add_before(node *a,int n)
  {
      node *tmp = new node;
      node *temp;
      if(head == NULL)
      {
          tmp->data = n;
          tmp->next = NULL;
          tmp->prev = NULL;
          head = tmp;
          tail = tmp;
      }
      else
      {
          temp = a->prev;
          tmp->data = n;
          tmp->next = a;
          tmp->prev = temp;
          temp->next = tmp;
      }
  }
  
  node *getnode(int n)
  {
      node *tmp;
      tmp = head;
      
      while(tmp->data != n)
      {
          tmp = tmp->next;
      }
      return tmp;
  }
  
  void search(int n)
  {
      node *tmp;
      tmp = head;
      int a = 0;
      int total = 0;
      
      if(head == NULL)
      {
          cout<<"\nNULL"<<endl;
      }
      else
      {
          while(tmp != NULL)
          {
              a++;
              if(tmp->data == n)
              {
                  total++;
                  cout<<a<<"\t"<<tmp->data<<endl;
              }
              else
              {
                  tmp = tmp->next;
              }
          }
          cout<<"total "<<total<<endl;
      }
  }
  
  void show_firstTOlast()
  {
      node *tmp = head;
      if(head == NULL)
      {
          cout<<"\nNULL"<<endl; 
      }
      else
      {
         while(tmp!=NULL)
         {
             cout<<tmp->data<<".."<<tmp->next<<endl;
             tmp = tmp->next;
         }
         cout<<"NULL"<<endl<<endl;
      }
  }
  
  void show_lastTOfirst()
  {
      node *tmp = tail;
      if(head == NULL)
      {
          cout<<"\nNULL"<<endl; 
      }
      else
      {
         while(tmp!=NULL)
         {
             cout<<tmp->data<<endl;
             tmp = tmp->prev;
         }
         cout<<"NULL"<<endl<<endl;
      }
  }
  
  static void show_node_first_last(node *a)
  {
      if(a == NULL)
      {
          cout<<"\nNULL\n"<<endl; 
      }
      else
      {
          cout<<a->data<<endl;
          show_node_first_last(a->next);
      }
  }
  
  static void show_node_last_first(node *a)
  {
      if(a == NULL)
      {
          cout<<"\nNULL\n"<<endl; 
      }
      else
      {
          cout<<a->data<<endl;
          show_node_first_last(a->prev);
      }
  }
  
};

int main() {
    double_link_list a;
    a.add_last(1);
    a.add_last(2);
    //a.add_last(3);
    //a.add_last(4);
    //a.add_last(5);
    a.show_firstTOlast();
    a.gethead();
    a.gettail();
	return 0;
}