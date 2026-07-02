class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char, int> hash_map1;
        unordered_map<char, int> hash_map2;
        int start = 0, end = 0;
        int max_len = 1e9, i = -1, j = -1;
        string result = ""; 

        for(end = 0 ; end < t.size() ; end ++) {
            hash_map2[t[end]] ++;
            hash_map1[s[end]] ++;
        }

        int num_unique = hash_map2.size();
        int matches = 0;

        for(auto it: hash_map2) {
            if(hash_map1[it.first] >= it.second)    matches ++;
        }
        
        for(end ; end < s.size() ; end ++) {
            while(matches == num_unique) {
                if(end - start < max_len) {
                    max_len = end - start;
                    i = start;
                    j = end - 1;
                }

                hash_map1[s[start]] --;
                if(hash_map2.find(s[start]) != hash_map2.end() && 
                hash_map1[s[start]] < hash_map2[s[start]])  matches --;

                start ++;
            }

            hash_map1[s[end]] ++;
            if(hash_map2.find(s[end]) != hash_map2.end() &&
            hash_map1[s[end]] == hash_map2[s[end]]) matches ++;
        }

        while(matches == num_unique) {
            if(end - start < max_len) {
                max_len = end - start;
                i = start;
                j = end - 1;
            }

            hash_map1[s[start]] --;
            if(hash_map2.find(s[start]) != hash_map2.end() && 
            hash_map1[s[start]] < hash_map2[s[start]])  matches --;

            start ++;
        }

        if(i != -1 && j != -1)  result = s.substr(i, j - i + 1);

        return result;
    }
};