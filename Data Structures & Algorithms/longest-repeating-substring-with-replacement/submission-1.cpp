class Solution {
private:
    bool isValid(unordered_map<char, int>& hash, int k){
        int mostFreq=0, allFreq=0;
        for(auto it: hash){
            int freq= it.second;
    
            mostFreq=max(mostFreq, freq);
            allFreq+=freq;
        }
        int restElement= allFreq- mostFreq;

        return restElement<=k;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int result=-1e9;
        int start=0, end=0;
        
        for(int end=0; end<s.size(); end++){
            hash[s[end]]++;

            while(!isValid(hash,k)){
                hash[s[start]]--;
                start++;
            }

            int length= end-start+1;
            result= max(result, length);
        }
        return result;
    }
};

