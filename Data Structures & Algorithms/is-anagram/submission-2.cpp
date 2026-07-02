class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>hash1;
        unordered_map<char, int>hash2;

        if(s.size()!=t.size()) return false;

        for(int i=0; i<s.size(); i++){
            hash1[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            hash2[t[i]]++;
        }
        return hash1==hash2;
    }
};
