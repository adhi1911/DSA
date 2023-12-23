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


//recurssion
int length(Node *head)
{   Node* p = head;
	//int count = 0;
    if(p ==0){ return 0; }
    else
    return length(p->next)+1;
}
//time complexity: O(n)
//space complexity: O(n)

//iterative
int length(Node *head)
{   Node* p = head;
    int count = 0;
    while(p !=0){
        count++;
        p=p->next;
    }
    return count;
}
//time complexity: O(n)
//space complexity: O(1)


