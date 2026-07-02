class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int diff =0;

        for(int i=0; i <nums.size(); i++){
            diff = target - nums[i];

            if(hash.contains(diff)){
                return {hash[diff],i};
            }
            hash[nums[i]]=i;
        }
    }
};
