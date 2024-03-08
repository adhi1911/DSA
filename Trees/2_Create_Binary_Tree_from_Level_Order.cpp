/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

#include<bits/stdc++.h>

Node* createTree(vector<int>&arr){
    if(arr.empty()) return nullptr; 

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1; 
    while(i < arr.size()){
        Node* current = q.front();
        q.pop();

        if(i < arr.size()){
            Node* leftChild = new Node(arr[i++]);
            current->left = leftChild;
            q.push(leftChild);
        }

        if(i < arr.size()){
            Node* rightChild = new Node(arr[i++]);
            current->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}