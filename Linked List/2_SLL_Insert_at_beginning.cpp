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

  Node* insertAtFirst(Node* list, int newValue) {
    //list is head of the LL
    Node* temp = new Node;
    temp->data = newValue;
    temp->next = list;
    list = temp;
    return list;
    //time complexity: O(1)
    //space complexity: O(1)
  }