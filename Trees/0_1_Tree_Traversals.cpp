#include<iostream>
#include<cstdlib>
#include <queue>
#include <stack>

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

void r_preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        r_preorder(p->left);
        r_preorder(p->right);
    }
}
void r_inorder(Node *p){
    if(p){
        r_inorder(p->left);
        cout<<p->data<<" ";
        r_inorder(p->right);
    }
}
void r_postorder(Node *p){
    if(p){
        r_postorder(p->left);
        r_postorder(p->right);
        cout<<p->data<<" ";
    }
}
/*
Algorithm: (Iterative)
1. Start
2. Pass in root node to the function as arguement.
3. Create a stack of type Node* and push the root node into it.
4. While loop: (t not NULL OR stack not empty)
    a. If t is not NULL:
        1. Print value of t
        2. Push t into the stack
        3. Move t to t->leftchild
    b. Else:
        1. Pop the top element of the stack and store it in t
        2. Move t to t->rightchild
*/

void i_preorder(Node *t){
    stack <Node*> st;
    while(t || !st.empty()){
        if(t){
            cout<<t->data<<" ";
            st.push(t);
            t = t->left;
        }
        else{
            t = st.top();
            st.pop();
            t=t->right;
        }
    }
}




/*
Algorithm: (Iterative)
1. Start
2. Pass in root node to the function as arguement.
3. Create a stack of type Node* and push the root node into it.
4. While loop: (t not NULL OR stack not empty)
    a. If t is not NULL:
        1. Push t into the stack
        2. Move t to t->leftchild
    b. Else:
        1. Pop the top element of the stack and store it in t
        2. Print value of t
        3. Move t to t->rightchild
*/
void i_inorder(Node *t){
    stack <Node*> st;
    while(t || !st.empty()){
        if(t){
            st.push(t);
            t = t->left;
        }
        else{
            t = st.top();
            st.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }
}


/*
Algorithm: (Iterative)
1. Start
2. Pass in root node to the function as arguement.
3. Create a stack of type Node* and push the root node into it.
4. While loop: (t not NULL OR stack not empty)
    a. If t is not NULL:
        1. Push t into the stack
        2. Move t to t->leftchild
    b. Else:
        1. Pop the top element of the stack and store it in t
        2. If t->right is NULL:
            a. Print value of t
            While loop: (stack not empty AND t is the right child of the top element of the stack)
                a. Pop the top element of the stack and store it in t
                b. Print value of t
        3. Else:
            a. Move t to t->rightchild
            
*/
void i_postorder(Node *t){
    stack <Node*> st;
    Node *temp;
    while(t || !st.empty()){
        if(t){
            st.push(t);
            t = t->left;
        }
        else{
            temp = st.top();
            if(temp->right == NULL){
                cout<<temp->data<<" ";
                st.pop();
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else{
                t = temp->right;
            }
        }
    }
}

int main(){
    Node *root = NULL;
    create(&root);
    cout<<"Recursive Preorder: ";
    r_preorder(root);
    cout<<endl;
    cout<<"Iterative Preorder: ";
    i_preorder(root);
    return 0;
}