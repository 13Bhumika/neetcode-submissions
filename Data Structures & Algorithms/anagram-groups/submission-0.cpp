class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        vector<vector<string>>result;
        
        for(string &s: strs){
            vector<int> count(26,0);
            string key= " ";

            for(char ch: s) count[ch-'a']++;

            for(int c:count){
                key+= '&' + to_string(c);
            }
            hash_map[key].push_back(s);
        }

        for(auto it: hash_map){
            result.push_back(it.second);
        }
        return result;
    }
};