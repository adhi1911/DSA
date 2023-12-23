#include<iostream>
#include<vector>
using namespace std;

  class Node
  {
  public:
     int data;
     Node *next, *prev;
     Node() : data(0), next(nullptr), prev(nullptr) {}
     Node(int x) : data(x), next(nullptr), prev(nullptr) {}
     Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
  };
 
Node* constructDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* p = head;
    Node* q = NULL;
    for(int i =1;i<arr.size();i++){
        q=p;
        p->next = new Node(arr[i]);
        p=p->next;
        p->prev=q;
    }
    return head;
}
//time complexity: O(n)
//space complexity: O(1)