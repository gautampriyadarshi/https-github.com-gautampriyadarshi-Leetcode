class MyStack {
    queue<int> q1;
public:
    MyStack() {}
    
    void push(int x) 
    {
        int size = q1.size();
        if(size == 0)
            q1.push(x);
        else
        {
            q1.push(x);
            for(int i = 0; i < size; i++)
            {
                int p = q1.front();
                q1.pop();
                q1.push(p);
            }
        }
    }
    
    int pop() 
    {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */