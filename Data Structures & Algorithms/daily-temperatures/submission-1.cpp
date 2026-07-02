class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;

        for(int i=temperatures.size()-1; i>=0; i--){
            int curr= temperatures[i]; //28, 40

            while(!st.empty() && curr>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()) answer[i]=st.top()-i;
            st.push(i);
        }

        return answer;

    }
};
