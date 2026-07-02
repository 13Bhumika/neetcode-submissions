class Solution {
public:
    int maxArea(vector<int>& heights) {
        int width =0;
        int maximum= INT_MIN;
        int area =0;

        int start =0;
        int end = heights.size()-1;

        while(start<end){
            width = end-start;
            area = width * min(heights[start], heights[end]);//5, 
            maximum= max(maximum, area);//5,

            if(heights[start]<heights[end]) start++;
            else end--;
        }
        return maximum;
    }
};
