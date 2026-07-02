class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int product =1;

        for(int i=0; i<nums.size(); i++){
            prefix[i]= product;
            product*=nums[i];
        }
        product =1;

        for(int i=nums.size()-1; i>=0;i--){
            suffix[i]= product;
            product*=nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};
