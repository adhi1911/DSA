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

Node* constructLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
    //time complexity: O(n)
    //space complexity: O(1)
}
