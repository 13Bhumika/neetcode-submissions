class Solution {
private:
    int sum(int a, int b){
        return a + b;
    }
    int diff(int a, int b){
        return a - b;
    }
    int product(int a, int b){
        return a * b;
    }
    int division(int a, int b){
        if(b == 0) return 0;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result = 0;
                if(tokens[i] == "+") result = sum(a, b);
                if(tokens[i] == "-") result = diff(a, b);
                if(tokens[i] == "*") result = product(a, b);
                if(tokens[i] == "/") result = division(a, b);
                st.push(result);
            }
        }
        return st.top();
    }
};
