class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result =0;

        for(string token:tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int a = st.top();
                st.pop(); //2

                int b = st.top();
                st.pop(); //1

                if(token == "+") {
                    result = b+a;
                    st.push(result);
                }
                else if(token =="-"){
                    result = b-a;
                    st.push(result);
                }
                else if(token=="*"){
                    result =b*a;
                    st.push(result);
                }
                else{
                    result=b/a;
                    st.push(result);
                }
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
