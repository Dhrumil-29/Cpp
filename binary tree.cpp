#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

class bst
{
    private://creat a root of bst
        node *root;
        public:
        bst()//constructor of root and its value initialised null
        {
            root = NULL;
        }
        
        node* get_root()
        {
            return root;
        }
        
        //creat a function add which add a node in bst 
        void add(node* tmp,node* a)
        {
            if(root == NULL)
            {
                root = tmp;
                root = new node;
                root->data = tmp->data;
                root->left = NULL;
                root->right = NULL;
            }
            
            else 
            {
                if(tmp->data > a->data)
                {
                    if(a->right != NULL)
                    {
                        add(tmp,a->right);
                    }
                    else
                    {
                        a->right = tmp;
                        a->right->right = NULL;
                        a->right->left = NULL;
                    }
                }
                 if(tmp->data < a->data)
                 {
                    if(a->left != NULL)
                    {
                        add(tmp,a->left);
                    }
                    else
                    {
                        a->left = tmp;
                        a->left->right = NULL;
                        a->left->left = NULL;
                    }
                 }
                else if(tmp->data == a->data)
                {
                    cout<<"already exists"<<endl;
                }
            }
        }
        
        void inorder(node* a)
        {
            if(a == NULL)
            {
                return ;
            }
            inorder(a->left);
            cout << a->data << " ";
            inorder(a->right);
        }
        void postorder(node* a)
        {
            if(a == NULL)
            {
                return ;
            }
            cout << a->data << " ";
            postorder(a->left);
            postorder(a->right);
        }
        void preorder(node* a)
        {
            if(a == NULL)
            {
                return ;
            }
            preorder(a->left);
            preorder(a->right);
            cout << a->data << " ";
        }
    };
int main() {
    bst b;
    int no,i,value;
    cout<<"how many data you want to add:\t";
    cin>>no;
    
    for(i=0;i<no;i++)
    {
        node* tmp = new node;
        cout<<"\nenter "<<i+1<<" number value: ";
        cin>>value;
        tmp->data = value;
        b.add(tmp,b.get_root());
    }
    cout<<endl;
    b.preorder(b.get_root());
	return 0;
}