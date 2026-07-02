class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int maxLength =0;
        int left =0;  
        int right =0;

        while(right<s.size()){
            hash[s[right]]++;

            while(hash[s[right]]>1){
                hash[s[left]]--;
                left++;
            }
            
            maxLength = max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
};
