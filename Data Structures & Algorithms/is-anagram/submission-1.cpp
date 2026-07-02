class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;

        if(s.size()!= t.size()){
            return false;
        }

        for(int i=0; i<s.size(); i++){
            hash1[s[i]]++;
        }
        for(int j=0; j<t.size(); j++){
            hash2[t[j]]++;
        }
        
        for(auto it:hash1){
            if(it.second != hash2[it.first]){
                return false;
            }
        }
        return true;
    }
};
