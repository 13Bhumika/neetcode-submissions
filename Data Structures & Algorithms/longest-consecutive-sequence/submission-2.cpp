class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int result=1;

        if(nums.empty())return 0;
        for(int i:hash){
            if(hash.find(i-1)!= hash.end()) continue;
            int length =1;
            while(hash.find(i+1)!= hash.end()){
                length++;
                i++;
            }
            
        result= max(result,length);
        }
        return result;
    }
};