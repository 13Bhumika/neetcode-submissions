class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);

        for(char ch: s1){
            hash1[ch-'a']++;
        }
        for(int i=0; i<s1.size(); i++){
            char ch= s2[i];
            hash2[ch-'a']++;
        }
        for(int i=s1.size(); i<s2.size(); i++){
            if(hash1==hash2) return true;

            int index_to_be_removed= i-s1.size();
            hash2[s2[index_to_be_removed]-'a']--;
            hash2[s2[i]-'a']++;
        }
        if(hash1==hash2) return true;
        return false;
    }
};