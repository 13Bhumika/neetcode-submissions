class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int difference =0;

        for(int i=0; i<nums.size(); i++){
            difference = target- nums[i];
            if(hash.contains(difference)){
                return {hash[difference], i};
            }
            hash[nums[i]] =i;
        }
    }
};
