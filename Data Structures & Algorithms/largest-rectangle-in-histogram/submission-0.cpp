class Solution {
private:
    vector<int> nextElement(vector<int>& arr) {
        stack<int> st;
        vector<int> result(arr.size());

        st.push(-1); 
        for(int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            result[i] = st.top();
            st.push(i); 
        }
        return result;
    }

    vector<int> prevElement(vector<int>& arr) {
        stack<int> st;
        vector<int> result(arr.size());

        st.push(-1); 
        for(int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            result[i] = st.top();
            st.push(i); 
        }
        return result;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;

        vector<int> next = nextElement(heights);
        vector<int> prev = prevElement(heights);

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            int length = heights[i];
        
            if(next[i] == -1) next[i] = heights.size();

            int breadth = next[i] - prev[i] - 1;
            int area = length * breadth;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
