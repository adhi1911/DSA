#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *lchild;
        Node *rchild;
        Node(){
            lchild = rchild = nullptr;
        }
        Node(int x){
            data = x;
            lchild = rchild = nullptr;
        }

};

class BinaryTree{
    private:
        Node *root;
    public:
        BinaryTree(){root = nullptr;}
        BinaryTree(int x){
            root = new Node;
            root->data = x;
            root->lchild = root->rchild = nullptr;
        }
        
        void create();

        void Preorder(Node*);
        void Inorder(Node*);
        void Postorder(Node*);

        void level_order(Node*);

        void Preorder_non_recursive();
        void Inorder_non_recursive();

        void create_by_inorder_preorder(vector<int>, vector<int>);
        //parameters are inorder, preorder and length of inorder/preorder array

        int count_node(Node*);
        int count_leaf_nodes(Node*);
        int height(Node*);

        int Equal_trees(Node*, Node*);

};

void BinaryTree::create(){
    Node *p, *t;
    int x;
    
    queue<Node*> q;
    cout<<"\nEnter root value: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.push(root);
    while(!q.empty()){
        cout<<"\nEnter left child of "<<q.front()->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new Node(x);
            q.front()->lchild = t;
            q.push(t);
        }
        else{
            q.front()->lchild = nullptr;
        }
        cout<<"\nEnter right child of "<<q.front()->data<<" : ";
        cin>>x;
        if(x!=-1){
            t = new Node(x);
            q.front()->rchild = t;
            q.push(t);
        }
        else{
            q.front()->rchild = nullptr;
        }

    }

}

void BinaryTree::Preorder(Node *p){
    if(p){
        std::cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void BinaryTree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        std::cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void BinaryTree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        std::cout<<p->data<<" ";
    }
}

void BinaryTree::Preorder_non_recursive(){
    /*
Algorithm: (Iterative)
1. Start
2. Create a stack of type Node* and push the root node into it.
3. While loop: (t not NULL OR stack not empty)
    a. If t is not NULL:
        1. Print value of t
        2. Push t into the stack
        3. Move t to t->leftchild
    b. Else:
        1. Pop the top element of the stack and store it in t
        2. Move t to t->rightchild
*/

    stack<Node*> stk;
    Node* temp = root;
    while(temp || !stk.empty()){
        if(temp){
            cout<<temp->data<<" ";
            stk.push(temp);
            temp = temp->lchild;
        }
        else{
            temp = stk.top();
            stk.pop();
            temp = temp->rchild;
        }
    }
}

void BinaryTree::Inorder_non_recursive(){

    /*
Algorithm: (Iterative)
1. Start
2. Create a stack of type Node* and push the root node into it.
3. While loop: (t not NULL OR stack not empty)
    a. If t is not NULL:
        1. Push t into the stack
        2. Move t to t->leftchild
    b. Else:
        1. Pop the top element of the stack and store it in t
        2. Print value of t
        3. Move t to t->rightchild
*/
    stack<Node*> stk;
    Node* temp = root;
    while(temp || !stk.empty()){
        if(temp){
            stk.push(temp);
            temp = temp->lchild;
        }
        else{
            temp = stk.top();
            stk.pop();
            cout<<temp->data<<" ";
            temp = temp->rchild;
        }
    }
}

//void BinaryTree::create_by_inorder_preorder(vector<int>){}


int BinaryTree::count_node(Node *p){
    if(p){
        return count_node(p->lchild) + count_node(p->rchild) + 1;
    }
    return 0;
}

int BinaryTree::count_leaf_nodes(Node *p){
    if(p){
        if(p->lchild == nullptr && p->rchild == nullptr){
            return count_leaf_nodes(p->lchild) + count_leaf_nodes(p->rchild) + 1;
        }
        else{
            return count_leaf_nodes(p->lchild) + count_leaf_nodes(p->rchild);
        }
    }
    return 0;
}

int BinaryTree::height(Node *p){
    int x, y;
    if(p){
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}


int BinaryTree::Equal_trees(Node *p, Node *q){
    if(p==nullptr && q==nullptr){
        return 1;
    }
    if(p==nullptr || q==nullptr){
        return 0;
    }
    if(p->data == q->data){
        return Equal_trees(p->lchild, q->lchild) && Equal_trees(p->rchild, q->rchild);
    }
    return 0;
}

void BinaryTree::level_order(Node *p){
    queue<Node*> q;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}