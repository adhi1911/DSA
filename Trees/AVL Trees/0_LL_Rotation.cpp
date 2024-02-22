#include<iostream>
using namespace std;

struct Node {
    Node* lchild;
    int key;
    int height;
    Node* rchild;
    
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->lchild) - height(node->rchild);
}

Node* rotateLL(Node* node) {
    Node* newRoot = node->lchild;
    node->lchild = newRoot->rchild;
    newRoot->rchild = node;
    node->height = max(height(node->lchild), height(node->rchild)) + 1;
    newRoot->height = max(height(newRoot->lchild), height(newRoot->rchild)) + 1;
    return newRoot;
}
