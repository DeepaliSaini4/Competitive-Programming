class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {
        s = stack<pair<int,int>>();
    }
    
    void push(int val) {
        // int prev_val = ;
        int mini = min((!s.empty() ? s.top().second : INT_MAX) ,val); 
      s.push({val, mini});
    }
    
    void pop() {
        if(!s.empty()) s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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
