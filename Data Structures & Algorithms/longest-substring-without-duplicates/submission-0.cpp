class Solution {
private:
    bool isValid(unordered_map<char, int>& hash){
        for(auto it: hash){
            int freq= it.second;
            if(freq>1) return false;
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int result=0;
        int start=0, end=0;

        for(end=0; end<s.size(); end ++){
            hash[s[end]]++;

            while(!isValid(hash)){
                hash[s[start]]--;
                start++;
            }
            int length= end-start+1;
            result= max(result, length);
        }
        return result;
    }
};
