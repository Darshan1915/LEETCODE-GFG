class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int front; 

    MyQueue() { }
    
    void push(int x) {
        if (s1.empty()) {
            front = x; // Update front when the first stack is empty
        }
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        // int f = s2.top();
        // return f;
        if (!s2.empty()) {
            return s2.top();
        }
        return front; // Correctly return front when s2 is empty
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */