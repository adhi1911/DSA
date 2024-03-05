#include<iostream>
#include<cstdlib>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
    Node()
    {
        left = right = NULL;
    }

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    private:
        Node *root;
    public:
        BST(){root = NULL;}
        void create();
        void insert(int);
        void inorder(Node*);
        Node* search(int);
        Node* rsearch(Node*, int);
        Node* rinsert(Node*, int);
        Node* Delete(Node*, int);
        int height(Node*);
        Node* InPre(Node*);
        Node* InSucc(Node*);
};

void BST::insert(int key){
    Node *t = root;
    Node *r, *p;
    
    if(root == NULL){
        p = new Node(key);
        root = p;
        return;
    }
    while(t!=NULL){
        r = t;
        if(key < t->data)
            t = t->left;
        else if(key > t->data)
            t = t->right;
        else
            return;
    }
    p = new Node(key);
    if(key < r->data)
        r->left = p;
    else
        r->right = p;

}

void BST::create(){
    int x;
    cout<<"\nEnter root value: ";
    cin>>x;
    root = new Node(x);
    while(1){
        cout<<"\nEnter value to be inserted: ";
        cin>>x;
        if(x == -1)
            break;
        insert(x);
    }
}

void BST::inorder(Node *p){
    if(p){
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

Node* BST::search(int key){
    Node *t = root;
    while(t!=NULL){
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

Node* BST::rsearch(Node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else if(key < p->data)
        return rsearch(p->left, key);
    else
        return rsearch(p->right, key);
}