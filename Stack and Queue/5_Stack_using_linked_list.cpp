//coding ninjas 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    int size = 0;
    Node *top = NULL;

public:
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int data)
    {
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        size++;
        
    } 


    void pop()
    {
        if(!isEmpty()){
            Node *temp = top;
            top = top->next;
            delete temp;
            size --;
        }
    }

    int getTop()
    {
        if(isEmpty()) return -1;
        return top->data;
    }
};