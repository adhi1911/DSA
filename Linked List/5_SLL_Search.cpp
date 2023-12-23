#include<iostream>
#include<vector>
using namespace std;


template <typename T>
    class Node
    {
    public:
        T data;
        Node<T> *next;
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(T data, T* next)
        {
            this->data = data;
            this->next = next;
        }
    };


int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* p = head;
    while(p){
        if(k == p->data) return 1;
        else p = p->next;
    }
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)