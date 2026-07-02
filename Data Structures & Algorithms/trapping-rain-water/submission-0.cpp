class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int ans = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for (int j = n-2; j >= 0; j--) {
            right[j] = max(right[j+1], height[j]);
        }
        for (int k = 0; k < n; k++) {
            ans += min(left[k], right[k]) - height[k];
        }

        return ans;
    }
};
