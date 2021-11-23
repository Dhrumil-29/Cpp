#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

class double_link _list
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
      cout<<"\n"<<head->data<<endl;
      cout<<head<<endl<<endl;
      return head;
  }
  
  node *gettail()
  {
      cout<<"\n"<<tail->data<<endl;
      cout<<tail<<endl<<endl;
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
  
};

int main() {
	return 0;
}