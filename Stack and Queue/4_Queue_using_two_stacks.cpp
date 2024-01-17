//using s1 and s2
//coding ninjas
class Queue {
    stack<int> s1, s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if(isEmpty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        if(isEmpty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.size() ==0;
    }
};

//using input and output stack
//leetcode

class MyQueue {
    stack<int> ip , op;
    //ip = input stack
    //op = output stack
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
      if(!op.empty()){
          int x = op.top();
          op.pop();
          return x;
      }
      else{
          while(!ip.empty()){
              op.push(ip.top());
              ip.pop();
          }
          int x = op.top();
          op.pop();
          return x;
      }
    }
    
    int peek() {
        if(!op.empty()) return op.top();
        else{
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
            return op.top();
        }
    }
    
    bool empty() {
        return (ip.size() + op.size() ==0);
    }
};

