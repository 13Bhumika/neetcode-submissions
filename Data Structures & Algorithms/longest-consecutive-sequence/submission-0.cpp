class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result=1;

        if(nums.empty()) return 0;
        unordered_set<int> hash(nums.begin(), nums.end());

        for(int num: hash){
            if(hash.find(num-1)!= hash.end()) continue;

            int length=1;
            while(hash.find(num+1)!= hash.end()){
                length++;
                num++;
            }
            result= max(result,length);
        }
        return result;
    }
};