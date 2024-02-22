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


/*
Algorithm:
1. Create a queue of type Node* and push the root node into it.
2. While loop:
    a. Pop the front element of the queue and store it in a pointer p.
    b. Ask the user to enter the left child of p->data and store it in a variable x.
    c. If x is not equal to -1, create a new node with the value x and assign it to p->left.
    d. Push the new node into the queue.
    e. Ask the user to enter the right child of p->data and store it in a variable x.
    f. If x is not equal to -1, create a new node with the value x and assign it to p->right.
    g. Push the new node into the queue.
3. End of while loop.
4. End  
*/
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

int height(Node *p){
    int x,y;
    if(p){
        x = height(p->left);
        y = height(p->right);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0; 
}

int main(){
    //implement the tree
    Node *root = NULL;
    create(&root);
    preorder(root);

    return 0;
}