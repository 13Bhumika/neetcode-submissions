class Solution {
public:

    string encode(vector<string>& strs) {
        string temp;
        for(string s: strs){
            temp+=(to_string(s.length()));
            temp+=('#');
            temp+=s;
        }
        return temp;//5#hello5#world
    }

    vector<string> decode(string s) {
      vector<string> ans;
      int i=0;

      while(i<s.length()){
        int j=i;

        while(s[j]!= '#'){
            j++;
        }

        int len= stoi(s.substr(i, j-i));//5
        j++;
        string word = s.substr(j, len);
        ans.push_back(word);
        i=j+len;
      }
      return ans;
    }
};
