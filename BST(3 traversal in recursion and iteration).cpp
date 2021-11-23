#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
   int data;
   node *left,*right;
   
   node(int data)
   {
       this->data = data;
       left = nullptr,right = nullptr;
   }
};

class BST
{
  private:
    node* root;
    
  public:

    BST(int data)
    {
        node *t = new node(data);
        root = t;
    }
    
    void Insert(node *root,int data)
    {
        if(data < root->data)
        {
            if(root->left == nullptr)
            {
                node *t = new node(data);
                root->left = t;
                return;
            }
            else
            {
                Insert(root->left,data);
            }
        }
        if(data > root->data)
        {
            if(root->right == nullptr)
            {
                node *t = new node(data);
                root->right = t;
                return;
            }
            else
            {
                Insert(root->right,data);
            }
        }
    }
    
    node* getRoot()
    {
        return root;
    }
    
    void PreOrderTraversalByRecursive(node* root)
    {
        if(!root)
            return;
        
        cout<<root->data<<" ";
        PreOrderTraversalByRecursive(root->left);
        PreOrderTraversalByRecursive(root->right);
    }
    
    void PreOrderTraversalByIteration(node* root)
    {
        stack<node *>s;
        s.push(root);
        while(!s.empty())
        {
            cout<<s.top()->data<<" ";
            node* t = s.top();
            s.pop();
            if(t->right)
                s.push(t->right);
            if(t->left)
                s.push(t->left);
        }
    }
    
    void InOrderTraversalByIteration(node* root)
    {
        stack<node *>s;
        while(root!= nullptr or !s.empty())
        {
            while(root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            node *t = s.top();
            s.pop();
            cout<<t->data<<" ";
            if(t->right != nullptr)
                root = t->right;
            else
                root = nullptr;
        }
    }
    
    void InOrderTraversalByRecursive(node* root)
    {
        if(!root)
            return;
        
        InOrderTraversalByRecursive(root->left);
        cout<<root->data<<" ";
        InOrderTraversalByRecursive(root->right);
    }
    void PostOrderTraversalByRecursive(node* root)
    {
        if(!root)
            return;
        
        PostOrderTraversalByRecursive(root->left);
        PostOrderTraversalByRecursive(root->right);
        cout<<root->data<<" ";
    }
    
    void PostOrderTraversalByIteration(node* root)
    {
        if(root == nullptr)
            return ;
        //PostOrder := L R Root
        //2 stack approach in that we need root node will print after going to their left and then right child tree.
        //so in s2 stack push root and in s1 push root left and root right child.
        //after that loop root is now s1 top which is prev root left.
        //in that way in s2 stack nodes are in L R ROOT ways.
        stack<node *>s1,s2;
        s1.push(root);
        node *t;
        while(!s1.empty())
        {
            t = s1.top();
            s1.pop();
            s2.push(t);
            if(t->left)
            s1.push(t->left);
            if(t->right)
            s1.push(t->right);
        }
        while(!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
        
        /*
        do it in 1 stack.
        */
        // stack<node *> s;
        
        // do
        // {
        //     while(root != nullptr)
        //     {
        //         cout<<root->data<<" ";
        //         if(root->right)
        //             s.push(root->right);
        //         s.push(root);
                
        //         if(!root->left)
        //             break;
        //         root = root->left;
        //     }
            
        //     root = s.top();
        //     s.pop();
            
        //     if(root->right and root->right == s.top())
        //     {
        //         s.pop();
        //         s.push(root);
        //         root = root->right;
        //     }
        //     else
        //     {
        //         cout<<root->data<<" ";
        //         root = nullptr;
        //     }
        // }while(!s.empty());
    }
};

int main()
{
    BST tree(5);
    //cout<<tree.getRoot()->data;
    tree.Insert(tree.getRoot(),3);
    tree.Insert(tree.getRoot(),7);
    tree.Insert(tree.getRoot(),2);
    tree.Insert(tree.getRoot(),4);
    tree.Insert(tree.getRoot(),6);
    tree.Insert(tree.getRoot(),8);
    
    // cout<<"PreOrder Traversal...\n";
    // tree.PreOrderTraversalByRecursive(tree.getRoot());
    // cout<<"\n";
    // cout<<"PreOrder Traversal...\n";
    // tree.PreOrderTraversalByIteration(tree.getRoot());
    // cout<<"\n";
    // cout<<"InOrder Traversal...\n";
    // tree.InOrderTraversalByRecursive(tree.getRoot());
    // cout<<"\n";
    // cout<<"InOrder Traversal...\n";
    // tree.InOrderTraversalByIteration(tree.getRoot());
    // cout<<"\n";
    cout<<"PostOrder Traversal...\n";
    tree.PostOrderTraversalByRecursive(tree.getRoot());
    cout<<"\n";
    cout<<"PostOrder Traversal...\n";
    tree.PostOrderTraversalByIteration(tree.getRoot());
    cout<<"\n";
    return 0;
}
