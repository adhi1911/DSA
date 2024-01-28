//program to create a binary tree

#include<iostream>
#include<cstdlib>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void create(Node **root){
    Node *p , *t;
    int x;
    queue<Node*> q;

    cout<<"\nEnter root value: ";
    cin>>x;
    *root = new Node(x);
    q.push(*root);

    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<"\nEnter left child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new Node(x);
            p->left = t;
            q.push(t);
        }
        cout<<"\nEnter right child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new Node(x);
            p->right = t;
            q.push(t);
        }
    }
}

void preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}


int main(){
    //implement the tree
    Node *root = NULL;
    create(&root);
    preorder(root);

    return 0;
}