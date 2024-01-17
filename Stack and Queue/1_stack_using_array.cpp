// Stack class.
class Stack {

    
public:
    int size;
    int Top;
    int* s;

    Stack(int capacity) {
        size = capacity;
        Top = -1;
        s = new int[size];
    }

    void push(int num) {
        if(!isFull()){
            Top++;
            s[Top]=num;
        }
    }

    int pop() {
        int x = -1;
        if(! isEmpty()){
            x = s[Top];
            Top--;
        }
        return x;
    }
    
    int top() {
        if (!isEmpty()) {
            return s[Top];
        }
        return -1;
    }
    
    int isEmpty() {
        return Top==-1 ? 1 : 0;
    }
    
    int isFull() {
        return Top==size-1 ? 1:0;
        
    }
    
};
