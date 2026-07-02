class Solution {
private:
public:
    int findMin(vector<int>& nums) {
        int minEle = 1e9;
        int low= 0;
        int high= nums.size()-1;

        while(low <=high){
            int mid= (low+high)/2;
            if(nums[low]<=nums[mid]){
                minEle=min(minEle, nums[low]);
                low=mid+1;
            }
            else {
                minEle= min(minEle, nums[mid]);
                high=mid-1;
            }
        }
         return minEle;
    }
};

