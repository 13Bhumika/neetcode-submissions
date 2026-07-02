class Solution {
public:
    bool isAnagram(string s, string t) {
              if(s.size() !=t.size()) return false;
        unordered_map<char, int> hash;
        for(int i=0; i<s.size(); i++){
            hash[s[i]]++;
        }        
        for(int j=0; j<t.size(); j++){
            if(hash.find(t[j])==hash.end()) return false;
            hash[t[j]]--;
            if(hash[t[j]]==0) hash.erase(t[j]);            
        }
        return hash.empty();  
    }
};
