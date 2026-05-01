class MyQueue {
// Why using 2 stack:
// queue : 1 2 3 4 5  -- > 1 2 3 4 5
// stack1: 1 2 3 4 5  -- > 5 4 3 2 1
// stack2: 5 4 3 2 1  -- > 1 2 3 4 5
    stack<int> st1, st2;
public:
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() 
    {
        // Step - 1: Move all elements from stack1 to stack2
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Step - 2: Save the top of element of stack2 and pop it.
        int x = st2.top();
        st2.pop();

        // Step - 3: Again move all elements from stack2 to stack1, 
        //           as main stack is stack1 only.
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;   // return top;
    }
    
    int peek() 
    {
        // Step - 1: Move all elements from stack1 to stack2
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Step - 2: Save the top of element of stack2 to display.
        int x = st2.top();

        // Step - 3: Again move all elements from stack2 to stack1, 
        //           as main stack is stack1 only.
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;   // return top;
    }
    
    bool empty() 
    {
        if(st1.empty())
            return true;
        
        return false;
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