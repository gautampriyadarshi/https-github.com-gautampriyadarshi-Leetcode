class MinStack {
private:
    // pair.first = actual value, pair.second = minimum at this stack height
    stack<pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else {
            // Compare current value with the minimum of the element below it
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */