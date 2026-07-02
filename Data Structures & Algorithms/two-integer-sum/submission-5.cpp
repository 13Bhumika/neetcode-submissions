class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int difference = 0;
        unordered_map<int, int> hash;

       for(int i=0; i<nums.size(); i++){
            difference = target - nums[i];
            if(hash.count(difference)){
                return {hash[difference], i};
            }
            hash[nums[i]] = i;
       }
       return {};
    }
};
