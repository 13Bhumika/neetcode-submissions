class Solution { 
public:

    bool checkInclusion(string s1, string s2) {
        vector<int> hash1(26);
        vector<int> hash2(26);
        int start =0; 
        int end =0;

        if(s1.size()> s2.size()) return false;

        for(char ch:s1){
            hash1[ch-'a']++;
        }

        for(int i=0; i<s1.size(); i++){
            hash2[s2[i]-'a']++;
        }

        int i=0;

        for(i= s1.size(); i<s2.size(); i++){
            if(hash1==hash2) return true;

            hash2[s2[i- s1.size()]-'a']--;
            hash2[s2[i]-'a']++;
            
        }

        if(hash1 == hash2) return true;
        return false;
    }
};
