#include<iostream>
#include<vector>
using namespace std;


class Node {
 
  public:
      int data;
      Node* next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node* next) : data(x), next(next) {}
  };


Node *deleteLast(Node *list){
    Node* p = list;
    Node* q = NULL;
    while(p->next != NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete p;

    return list;

    //time complexity: O(n)
    //space complexity: O(1)
}