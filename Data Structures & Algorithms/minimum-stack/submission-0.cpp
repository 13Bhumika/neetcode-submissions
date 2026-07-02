class MinStack {
private:
    stack<int> primary_stack;
    stack<int> secondary_stack;
public:
    MinStack() {

    }

    void push(int val) {
        primary_stack.push(val);
        if(secondary_stack.empty()) secondary_stack.push(val);
        else secondary_stack.push(min(val,secondary_stack.top()));
    }
    
    void pop() {
        if(!primary_stack.empty()){
            primary_stack.pop();
            secondary_stack.pop();
        }
    }
    
    int top() {
        if(primary_stack.empty()) return -1;
        return primary_stack.top();
    }
    
    int getMin() {
        if(primary_stack.empty()) return -1;
        return secondary_stack.top();
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