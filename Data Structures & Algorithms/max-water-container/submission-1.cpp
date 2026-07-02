class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0; 
        int right = heights.size()-1;
        int width =0;
        int area =0;
        int maximum = INT_MIN;

        while(left<right){
            width = right- left;
            area = width* min(heights[left], heights[right]); 
            maximum = max(maximum, area); 

            if(heights[left]< heights[right]) left++;
            else right--;
            
        }
        return maximum;
    }
};
