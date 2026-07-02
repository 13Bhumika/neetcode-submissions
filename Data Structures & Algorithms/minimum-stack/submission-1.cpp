class MinStack {
private: 
    stack<int> st;
    stack<int> minstack;

public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            minstack.push(min(val, minstack.top()));
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        minstack.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        else return minstack.top();
    }
};
